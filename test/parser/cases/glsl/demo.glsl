precision mediump float;
precision mediump int;
float pow2(float x) {
    return x*x;
}
vec4 RGBMToLinear(vec4 value, float maxRange) {
    return vec4(value.rgb*value.a*maxRange, 1.0);
}
vec4 gammaToLinear(vec4 srgbIn) {
    return vec4(pow(srgbIn.rgb, vec3(2.2)), srgbIn.a);
}
vec4 linearToGamma(vec4 linearIn) {
    return vec4(pow(linearIn.rgb, vec3(1.0/2.2)), linearIn.a);
}
uniform vec4 camera_DepthBufferParams;
float remapDepthBufferLinear01(float z) {
    return 1.0/(camera_DepthBufferParams.x*z+camera_DepthBufferParams.y);
}
uniform vec3 camera_Position;
uniform vec3 camera_Forward;
uniform vec4 camera_ProjectionParams;
varying vec2 v_uv;
varying vec3 v_normal;
varying vec3 v_pos;
struct DirectLight {
    vec3 color;
    vec3 direction;
};
uniform ivec2 scene_DirectLightCullingMask[1];
uniform vec3 scene_DirectLightColor[1];
uniform vec3 scene_DirectLightDirection[1];
struct EnvMapLight {
    vec3 diffuse;
    float mipMapLevel;
    float diffuseIntensity;
    float specularIntensity;
};
uniform EnvMapLight scene_EnvMapLight;
uniform ivec4 renderer_Layer;
uniform vec3 scene_EnvSH[9];
uniform samplerCube scene_EnvSpecularSampler;
bool isRendererCulledByLight(ivec2 rendererLayer, ivec2 lightCullingMask) {
    return!((rendererLayer.x&lightCullingMask.x)! = 0||(rendererLayer.y&lightCullingMask.y)! = 0);
}
uniform float material_AlphaCutoff;
uniform vec4 material_BaseColor;
uniform float material_Metal;
uniform float material_Roughness;
uniform float material_IOR;
uniform vec3 material_PBRSpecularColor;
uniform float material_Glossiness;
uniform vec3 material_EmissiveColor;
uniform float material_NormalIntensity;
uniform float material_OcclusionIntensity;
uniform float material_OcclusionTextureCoord;
struct ReflectedLight {
    vec3 directDiffuse;
    vec3 directSpecular;
    vec3 indirectDiffuse;
    vec3 indirectSpecular;
};
struct Geometry {
    vec3 position;
    vec3 normal;
    vec3 viewDir;
    float dotNV;
};
struct Material {
    vec3 diffuseColor;
    float roughness;
    vec3 specularColor;
    float opacity;
    float f0;
};
vec3 getNormal(bool isFrontFacing) {
    vec3 normal = normalize(v_normal);
    normal *= float(isFrontFacing)*2.0-1.0;
    return normal;
}
vec3 getNormalByNormalTexture(mat3 tbn, sampler2D normalTexture, float normalIntensity, vec2 uv, bool isFrontFacing) {
    vec3 normal = texture(normalTexture, uv).rgb;
    normal = normalize(tbn*((2.0*normal-1.0)*vec3(normalIntensity, normalIntensity, 1.0)));
    normal *= float(isFrontFacing)*2.0-1.0;
    return normal;
}
mat3 getTBN(bool isFrontFacing) {
    vec3 normal = getNormal(isFrontFacing);
    vec3 position = v_pos;
    vec2 uv = isFrontFacing? v_uv:-v_uv;
    vec3 dp1 = dFdx(position);
    vec3 dp2 = dFdy(position);
    vec2 duv1 = dFdx(uv);
    vec2 duv2 = dFdy(uv);
    vec3 dp2perp = cross(dp2, normal);
    vec3 dp1perp = cross(normal, dp1);
    vec3 tangent = dp2perp*duv1.x+dp1perp*duv2.x;
    vec3 bitangent = dp2perp*duv1.y+dp1perp*duv2.y;
    float denom = max(dot(tangent, tangent), dot(bitangent, bitangent));
    float invmax = (denom == 0.0)? 0.0 : camera_ProjectionParams.x/sqrt(denom);
    mat3 tbn = mat3(tangent*invmax, bitangent*invmax, normal);
    return tbn;
}
float computeSpecularOcclusion(float ambientOcclusion, float roughness, float dotNV) {
    return clamp( pow(dotNV+ambientOcclusion, exp2(-16.0*roughness-1.0))-1.0+ambientOcclusion, 0.0, 1.0 );
}
float getAARoughnessFactor(vec3 normal) {
    vec3 dxy = max(abs(dFdx(normal)), abs(dFdy(normal)));
    return 0.045+max(max(dxy.x, dxy.y), dxy.z);
}
void initGeometry(out Geometry geometry, bool isFrontFacing) {
    geometry.position = v_pos;
    geometry.viewDir = normalize(camera_Position-v_pos);
    geometry.normal = getNormal(isFrontFacing);
    geometry.dotNV = clamp( dot(geometry.normal, geometry.viewDir), 0.0, 1.0 );
}
void initMaterial(out Material material, inout Geometry geometry) {
    vec4 baseColor = material_BaseColor;
    float metal = material_Metal;
    float roughness = material_Roughness;
    vec3 specularColor = material_PBRSpecularColor;
    float glossiness = material_Glossiness;
    float alphaCutoff = material_AlphaCutoff;
    float f0 = pow2((material_IOR-1.0)/(material_IOR+1.0));
    material.f0 = f0;
    material.diffuseColor = baseColor.rgb*(1.0-metal);
    material.specularColor = mix(vec3(f0), baseColor.rgb, metal);
    material.roughness = roughness;
    material.roughness = max(material.roughness, getAARoughnessFactor(geometry.normal));
    material.opacity = 1.0;
}
float F_Schlick(float f0, float dotLH) {
    return f0+0.96*(pow(1.0-dotLH, 5.0));
}
vec3 F_Schlick(vec3 specularColor, float dotLH) {
    float fresnel = exp2((-5.55473*dotLH-6.98316)*dotLH);
    return(1.0-specularColor)*fresnel+specularColor;
}
float G_GGX_SmithCorrelated(float alpha, float dotNL, float dotNV) {
    float a2 = pow2(alpha);
    float gv = dotNL*sqrt(a2+(1.0-a2)*pow2(dotNV));
    float gl = dotNV*sqrt(a2+(1.0-a2)*pow2(dotNL));
    return 0.5/max(gv+gl, 1e-6);
}
float D_GGX(float alpha, float dotNH) {
    float a2 = pow2(alpha);
    float denom = pow2(dotNH)*(a2-1.0)+1.0;
    return 0.31830988618*a2/pow2(denom);
}
vec3 isotropicLobe(vec3 specularColor, float alpha, float dotNV, float dotNL, float dotNH, float dotLH) {
    vec3 F = F_Schlick(specularColor, dotLH);
    float D = D_GGX(alpha, dotNH);
    float G = G_GGX_SmithCorrelated(alpha, dotNL, dotNV);
    return F*(G*D);
}
vec3 BRDF_Specular_GGX(vec3 incidentDirection, Geometry geometry, vec3 normal, vec3 specularColor, float roughness) {
    float alpha = pow2(roughness);
    vec3 halfDir = normalize(incidentDirection+geometry.viewDir);
    float dotNL = clamp( dot(normal, incidentDirection), 0.0, 1.0 );
    float dotNV = clamp( dot(normal, geometry.viewDir), 0.0, 1.0 );
    float dotNH = clamp( dot(normal, halfDir), 0.0, 1.0 );
    float dotLH = clamp( dot(incidentDirection, halfDir), 0.0, 1.0 );
    return isotropicLobe(specularColor, alpha, dotNV, dotNL, dotNH, dotLH);
}
vec3 BRDF_Diffuse_Lambert(vec3 diffuseColor) {
    return 0.31830988618*diffuseColor;
}
void addDirectRadiance(vec3 incidentDirection, vec3 color, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    float attenuation = 1.0;
    float dotNL = clamp( dot(geometry.normal, incidentDirection), 0.0, 1.0 );
    vec3 irradiance = dotNL*color*3.14159265359;
    reflectedLight.directSpecular += attenuation*irradiance*BRDF_Specular_GGX(incidentDirection, geometry, geometry.normal, material.specularColor, material.roughness);
    reflectedLight.directDiffuse += attenuation*irradiance*BRDF_Diffuse_Lambert(material.diffuseColor);
}
void addDirectionalDirectLightRadiance(DirectLight directionalLight, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    vec3 color = directionalLight.color;
    vec3 direction = -directionalLight.direction;
    addDirectRadiance(direction, color, geometry, material, reflectedLight);
}
void addTotalDirectRadiance(Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    float shadowAttenuation = 1.0;
    shadowAttenuation = 1.0;
    DirectLight directionalLight;
    for(int i = 0;i<1;i++) {
        if(!isRendererCulledByLight(renderer_Layer.xy, scene_DirectLightCullingMask[i])) {
            directionalLight.color = scene_DirectLightColor[i];
            directionalLight.direction = scene_DirectLightDirection[i];
            addDirectionalDirectLightRadiance(directionalLight, geometry, material, reflectedLight);
        }

    }

}
vec3 getLightProbeIrradiance(vec3 sh[9], vec3 normal) {
    normal.x = -normal.x;
    vec3 result = sh[0]+sh[1]*(normal.y)+sh[2]*(normal.z)+sh[3]*(normal.x)+sh[4]*(normal.y*normal.x)+sh[5]*(normal.y*normal.z)+sh[6]*(3.0*normal.z*normal.z-1.0)+sh[7]*(normal.z*normal.x)+sh[8]*(normal.x*normal.x-normal.y*normal.y);
    return max(result, vec3(0.0));
}
vec3 envBRDFApprox(vec3 specularColor, float roughness, float dotNV) {
    const vec4 c0 = vec4(-1, -0.0275, -0.572, 0.022);
    const vec4 c1 = vec4(1, 0.0425, 1.04, -0.04);
    vec4 r = roughness*c0+c1;
    float a004 = min(r.x*r.x, exp2(-9.28*dotNV))*r.x+r.y;
    vec2 AB = vec2(-1.04, 1.04)*a004+r.zw;
    return specularColor*AB.x+AB.y;
}
float getSpecularMIPLevel(float roughness, int maxMIPLevel) {
    return roughness*float(maxMIPLevel);
}
vec3 getReflectedVector(Geometry geometry, vec3 n) {
    vec3 r = reflect(-geometry.viewDir, n);
    return r;
}
vec3 getLightProbeRadiance(Geometry geometry, vec3 normal, float roughness, int maxMIPLevel, float specularIntensity) {
    vec3 reflectVec = getReflectedVector(geometry, normal);
    reflectVec.x = -reflectVec.x;
    float specularMIPLevel = getSpecularMIPLevel(roughness, maxMIPLevel);
    vec4 envMapColor = textureLod(scene_EnvSpecularSampler, reflectVec, specularMIPLevel);
    envMapColor.rgb = RGBMToLinear(envMapColor, 5.0).rgb;
    return envMapColor.rgb*specularIntensity;
}
out vec4 glFragColor;
void main() {
    Geometry geometry;
    Material material;
    ReflectedLight reflectedLight = ReflectedLight(vec3(0.0), vec3(0.0), vec3(0.0), vec3(0.0));
    initGeometry(geometry, gl_FrontFacing);
    initMaterial(material, geometry);
    addTotalDirectRadiance(geometry, material, reflectedLight);
    vec3 irradiance = getLightProbeIrradiance(scene_EnvSH, geometry.normal);
    irradiance *= scene_EnvMapLight.diffuseIntensity;
    reflectedLight.indirectDiffuse += irradiance*BRDF_Diffuse_Lambert(material.diffuseColor);
    vec3 radiance = getLightProbeRadiance(geometry, geometry.normal, material.roughness, int(scene_EnvMapLight.mipMapLevel), scene_EnvMapLight.specularIntensity);
    float radianceAttenuation = 1.0;
    reflectedLight.indirectSpecular += radianceAttenuation*radiance*envBRDFApprox(material.specularColor, material.roughness, geometry.dotNV);
    vec3 emissiveRadiance = material_EmissiveColor;
    vec3 totalRadiance = reflectedLight.directDiffuse+reflectedLight.indirectDiffuse+reflectedLight.directSpecular+reflectedLight.indirectSpecular+emissiveRadiance;
    vec4 targetColor = vec4(totalRadiance, material.opacity);
    glFragColor = targetColor;
    glFragColor = linearToGamma(glFragColor);
}
