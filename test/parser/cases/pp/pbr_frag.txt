#version 300 es
#define GRAPHICS_API_WEBGL2

#ifdef GL_FRAGMENT_PRECISION_HIGH
    precision highp float;
    precision highp int;
#else
    precision mediump float;
    precision mediump int;
#endif
#define HAS_TEX_LOD
#define HAS_DERIVATIVES

#define RENDERER_IS_RECEIVE_SHADOWS
#define RENDERER_HAS_NORMAL
#define SCENE_USE_SH
#define SCENE_USE_SPECULAR_ENV
#define SCENE_IS_DECODE_ENV_RGBM
#define SCENE_FOG_MODE 0
#define SCENE_SHADOW_CASCADED_COUNT 1
#define MATERIAL_NEED_WORLD_POS
#define MATERIAL_NEED_TILING_OFFSET
#define SCENE_DIRECT_LIGHT_COUNT 1

#define GLSLIFY 1
#define IS_METALLIC_WORKFLOW
#define GLSLIFY 1
#define PI 3.14159265359
#define RECIPROCAL_PI 0.31830988618
#define EPSILON 1e-6
#define LOG2 1.442695
#define saturate( a ) clamp( a, 0.0, 1.0 )
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
#ifdef GRAPHICS_API_WEBGL2
    #define INVERSE_MAT(mat) inverse(mat)
#else
    mat2 inverseMat(mat2 m) {
        return mat2(m[1][1], -m[0][1], -m[1][0], m[0][0])/(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
    }
    mat3 inverseMat(mat3 m) {
        float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2];
        float a10 = m[1][0], a11 = m[1][1], a12 = m[1][2];
        float a20 = m[2][0], a21 = m[2][1], a22 = m[2][2];
        float b01 = a22*a11-a12*a21;
        float b11 = -a22*a10+a12*a20;
        float b21 = a21*a10-a11*a20;
        float det = a00*b01+a01*b11+a02*b21;
        return mat3(b01, (-a22*a01+a02*a21), (a12*a01-a02*a11), b11, (a22*a00-a02*a20), (-a12*a00+a02*a10), b21, (-a21*a00+a01*a20), (a11*a00-a01*a10))/det;
    }
    mat4 inverseMat(mat4 m) {
        float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2], a03 = m[0][3], a10 = m[1][0], a11 = m[1][1], a12 = m[1][2], a13 = m[1][3], a20 = m[2][0], a21 = m[2][1], a22 = m[2][2], a23 = m[2][3], a30 = m[3][0], a31 = m[3][1], a32 = m[3][2], a33 = m[3][3], b00 = a00*a11-a01*a10, b01 = a00*a12-a02*a10, b02 = a00*a13-a03*a10, b03 = a01*a12-a02*a11, b04 = a01*a13-a03*a11, b05 = a02*a13-a03*a12, b06 = a20*a31-a21*a30, b07 = a20*a32-a22*a30, b08 = a20*a33-a23*a30, b09 = a21*a32-a22*a31, b10 = a21*a33-a23*a31, b11 = a22*a33-a23*a32, det = b00*b11-b01*b10+b02*b09+b03*b08-b04*b07+b05*b06;
        return mat4(a11*b11-a12*b10+a13*b09, a02*b10-a01*b11-a03*b09, a31*b05-a32*b04+a33*b03, a22*b04-a21*b05-a23*b03, a12*b08-a10*b11-a13*b07, a00*b11-a02*b08+a03*b07, a32*b02-a30*b05-a33*b01, a20*b05-a22*b02+a23*b01, a10*b10-a11*b08+a13*b06, a01*b08-a00*b10-a03*b06, a30*b04-a31*b02+a33*b00, a21*b02-a20*b04-a23*b00, a11*b07-a10*b09-a12*b06, a00*b09-a01*b07+a02*b06, a31*b01-a30*b03-a32*b00, a20*b03-a21*b01+a22*b00)/det;
    }
    #define INVERSE_MAT(mat) inverseMat(mat)
#endif

#define GLSLIFY 1
uniform vec3 camera_Position;
uniform vec3 camera_Forward;
uniform vec4 camera_ProjectionParams;
#define GLSLIFY 1
#if SCENE_FOG_MODE ! = 0
    in vec3 v_positionVS;
    uniform vec4 scene_FogColor;
    uniform vec4 scene_FogParams;
    float ComputeFogIntensity(float fogDepth) {
        #if SCENE_FOG_MODE == 1
            return clamp(fogDepth*scene_FogParams.x+scene_FogParams.y, 0.0, 1.0);
            #elif SCENE_FOG_MODE == 2
            return clamp(exp2(-fogDepth*scene_FogParams.z), 0.0, 1.0);
            #elif SCENE_FOG_MODE == 3
            float factor = fogDepth*scene_FogParams.w;
            return clamp(exp2(-factor*factor), 0.0, 1.0);
        #endif
    }
#endif

#define GLSLIFY 1
in vec2 v_uv;
#ifdef RENDERER_HAS_UV1
    in vec2 v_uv1;
#endif

#define GLSLIFY 1
#ifndef MATERIAL_OMIT_NORMAL
    #ifdef RENDERER_HAS_NORMAL
        in vec3 v_normal;
        #if defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
            in mat3 v_TBN;
        #endif
    #endif
#endif

#define GLSLIFY 1
#ifdef RENDERER_ENABLE_VERTEXCOLOR
    in vec4 v_color;
#endif

#define GLSLIFY 1
#ifdef MATERIAL_NEED_WORLD_POS
    in vec3 v_pos;
#endif

#define GLSLIFY 1
#ifdef SCENE_DIRECT_LIGHT_COUNT
    struct DirectLight {
        vec3 color;
        vec3 direction;
    };
    uniform ivec2 scene_DirectLightCullingMask[SCENE_DIRECT_LIGHT_COUNT];
    uniform vec3 scene_DirectLightColor[SCENE_DIRECT_LIGHT_COUNT];
    uniform vec3 scene_DirectLightDirection[SCENE_DIRECT_LIGHT_COUNT];
#endif
#ifdef SCENE_POINT_LIGHT_COUNT
    struct PointLight {
        vec3 color;
        vec3 position;
        float distance;
    };
    uniform ivec2 scene_PointLightCullingMask[SCENE_POINT_LIGHT_COUNT];
    uniform vec3 scene_PointLightColor[SCENE_POINT_LIGHT_COUNT];
    uniform vec3 scene_PointLightPosition[SCENE_POINT_LIGHT_COUNT];
    uniform float scene_PointLightDistance[SCENE_POINT_LIGHT_COUNT];
#endif
#ifdef SCENE_SPOT_LIGHT_COUNT
    struct SpotLight {
        vec3 color;
        vec3 position;
        vec3 direction;
        float distance;
        float angleCos;
        float penumbraCos;
    };
    uniform ivec2 scene_SpotLightCullingMask[SCENE_SPOT_LIGHT_COUNT];
    uniform vec3 scene_SpotLightColor[SCENE_SPOT_LIGHT_COUNT];
    uniform vec3 scene_SpotLightPosition[SCENE_SPOT_LIGHT_COUNT];
    uniform vec3 scene_SpotLightDirection[SCENE_SPOT_LIGHT_COUNT];
    uniform float scene_SpotLightDistance[SCENE_SPOT_LIGHT_COUNT];
    uniform float scene_SpotLightAngleCos[SCENE_SPOT_LIGHT_COUNT];
    uniform float scene_SpotLightPenumbraCos[SCENE_SPOT_LIGHT_COUNT];
#endif
struct EnvMapLight {
    vec3 diffuse;
    float mipMapLevel;
    float diffuseIntensity;
    float specularIntensity;
};
uniform EnvMapLight scene_EnvMapLight;
uniform ivec4 renderer_Layer;
#ifdef SCENE_USE_SH
    uniform vec3 scene_EnvSH[9];
#endif
#ifdef SCENE_USE_SPECULAR_ENV
    uniform samplerCube scene_EnvSpecularSampler;
#endif
#ifndef GRAPHICS_API_WEBGL2
    bool isBitSet(float value, float mask, float bitIndex) {
        return mod(floor(value/pow(2.0, bitIndex)), 2.0) == 1.0&&mod(floor(mask/pow(2.0, bitIndex)), 2.0) == 1.0;
    }
#endif
bool isRendererCulledByLight(ivec2 rendererLayer, ivec2 lightCullingMask) {
    #ifdef GRAPHICS_API_WEBGL2
        return!((rendererLayer.x&lightCullingMask.x)! = 0||(rendererLayer.y&lightCullingMask.y)! = 0);
    #else
        for(int i = 0;i<16;i++) {
            if(isBitSet(float(rendererLayer.x), float(lightCullingMask.x), float(i))||isBitSet(float(rendererLayer.y), float(lightCullingMask.y), float(i))) {
                return false;
            }
    
        }
        return true;
    #endif
}
#define GLSLIFY 1
#define MIN_PERCEPTUAL_ROUGHNESS 0.045
#define MIN_ROUGHNESS 0.002025
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
#ifdef MATERIAL_ENABLE_CLEAR_COAT
    uniform float material_ClearCoat;
    uniform float material_ClearCoatRoughness;
    #ifdef MATERIAL_HAS_CLEAR_COAT_TEXTURE
        uniform sampler2D material_ClearCoatTexture;
    #endif
    #ifdef MATERIAL_HAS_CLEAR_COAT_ROUGHNESS_TEXTURE
        uniform sampler2D material_ClearCoatRoughnessTexture;
    #endif
    #ifdef MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE
        uniform sampler2D material_ClearCoatNormalTexture;
    #endif
#endif
#ifdef MATERIAL_ENABLE_ANISOTROPY
    uniform vec3 material_AnisotropyInfo;
    #ifdef MATERIAL_HAS_ANISOTROPY_TEXTURE
        uniform sampler2D material_AnisotropyTexture;
    #endif
#endif
#ifdef MATERIAL_HAS_BASETEXTURE
    uniform sampler2D material_BaseTexture;
#endif
#ifdef MATERIAL_HAS_NORMALTEXTURE
    uniform sampler2D material_NormalTexture;
#endif
#ifdef MATERIAL_HAS_EMISSIVETEXTURE
    uniform sampler2D material_EmissiveTexture;
#endif
#ifdef MATERIAL_HAS_ROUGHNESS_METALLIC_TEXTURE
    uniform sampler2D material_RoughnessMetallicTexture;
#endif
#ifdef MATERIAL_HAS_SPECULAR_GLOSSINESS_TEXTURE
    uniform sampler2D material_SpecularGlossinessTexture;
#endif
#ifdef MATERIAL_HAS_OCCLUSION_TEXTURE
    uniform sampler2D material_OcclusionTexture;
#endif
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
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        vec3 clearCoatNormal;
        float clearCoatDotNV;
    #endif
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        vec3 anisotropicT;
        vec3 anisotropicB;
        vec3 anisotropicN;
        float anisotropy;
    #endif
};
struct Material {
    vec3 diffuseColor;
    float roughness;
    vec3 specularColor;
    float opacity;
    float f0;
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        float clearCoat;
        float clearCoatRoughness;
    #endif
};
#define GLSLIFY 1
#define GLSLIFY 1
vec3 getNormal(bool isFrontFacing) {
    #ifdef RENDERER_HAS_NORMAL
        vec3 normal = normalize(v_normal);
        #elif defined(HAS_DERIVATIVES)
        vec3 pos_dx = dFdx(v_pos);
        vec3 pos_dy = dFdy(v_pos);
        vec3 normal = normalize(cross(pos_dx, pos_dy));
        normal *= camera_ProjectionParams.x;
    #else
        vec3 normal = vec3(0, 0, 1);
    #endif
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
    #if defined(RENDERER_HAS_NORMAL) && defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
        mat3 tbn = v_TBN;
    #else
        vec3 normal = getNormal(isFrontFacing);
        vec3 position = v_pos;
        vec2 uv = isFrontFacing? v_uv:-v_uv;
        #ifdef HAS_DERIVATIVES
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
        #else
            mat3 tbn = mat3(vec3(0.0), vec3(0.0), normal);
        #endif
    #endif
    return tbn;
}
float computeSpecularOcclusion(float ambientOcclusion, float roughness, float dotNV) {
    return saturate(pow(dotNV+ambientOcclusion, exp2(-16.0*roughness-1.0))-1.0+ambientOcclusion);
}
float getAARoughnessFactor(vec3 normal) {
    #ifdef HAS_DERIVATIVES
        vec3 dxy = max(abs(dFdx(normal)), abs(dFdy(normal)));
        return MIN_PERCEPTUAL_ROUGHNESS+max(max(dxy.x, dxy.y), dxy.z);
    #else
        return MIN_PERCEPTUAL_ROUGHNESS;
    #endif
}
#ifdef MATERIAL_ENABLE_ANISOTROPY
    vec3 getAnisotropicBentNormal(Geometry geometry, vec3 n, float roughness) {
        vec3 anisotropyDirection = geometry.anisotropy >= 0.0 ? geometry.anisotropicB : geometry.anisotropicT;
        vec3 anisotropicTangent = cross(anisotropyDirection, geometry.viewDir);
        vec3 anisotropicNormal = cross(anisotropicTangent, anisotropyDirection);
        vec3 bentNormal = normalize(mix(n, anisotropicNormal, abs(geometry.anisotropy)*saturate(5.0*roughness)));
        return bentNormal;
    }
#endif
void initGeometry(out Geometry geometry, bool isFrontFacing) {
    geometry.position = v_pos;
    #ifdef CAMERA_ORTHOGRAPHIC
        geometry.viewDir = -camera_Forward;
    #else
        geometry.viewDir = normalize(camera_Position-v_pos);
    #endif
    #if defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY)
        mat3 tbn = getTBN(isFrontFacing);
    #endif
    #ifdef MATERIAL_HAS_NORMALTEXTURE
        geometry.normal = getNormalByNormalTexture(tbn, material_NormalTexture, material_NormalIntensity, v_uv, isFrontFacing);
    #else
        geometry.normal = getNormal(isFrontFacing);
    #endif
    geometry.dotNV = saturate(dot(geometry.normal, geometry.viewDir));
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        #ifdef MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE
            geometry.clearCoatNormal = getNormalByNormalTexture(tbn, material_ClearCoatNormalTexture, material_NormalIntensity, v_uv, isFrontFacing);
        #else
            geometry.clearCoatNormal = getNormal(isFrontFacing);
        #endif
        geometry.clearCoatDotNV = saturate(dot(geometry.clearCoatNormal, geometry.viewDir));
    #endif
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        float anisotropy = material_AnisotropyInfo.z;
        vec3 anisotropicDirection = vec3(material_AnisotropyInfo.xy, 0.0);
        #ifdef MATERIAL_HAS_ANISOTROPY_TEXTURE
            vec3 anisotropyTextureInfo = texture(material_AnisotropyTexture, v_uv).rgb;
            anisotropy *= anisotropyTextureInfo.b;
            anisotropicDirection.xy *= anisotropyTextureInfo.rg*2.0-1.0;
        #endif
        geometry.anisotropy = anisotropy;
        geometry.anisotropicT = normalize(tbn*anisotropicDirection);
        geometry.anisotropicB = normalize(cross(geometry.normal, geometry.anisotropicT));
    #endif
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
    #ifdef MATERIAL_HAS_BASETEXTURE
        vec4 baseTextureColor = texture(material_BaseTexture, v_uv);
        #ifndef ENGINE_IS_COLORSPACE_GAMMA
            baseTextureColor = gammaToLinear(baseTextureColor);
        #endif
        baseColor *= baseTextureColor;
    #endif
    #ifdef RENDERER_ENABLE_VERTEXCOLOR
        baseColor *= v_color;
    #endif
    #ifdef MATERIAL_IS_ALPHA_CUTOFF
        if(baseColor.a<alphaCutoff) {
            discard;
        }
    #endif
    #ifdef MATERIAL_HAS_ROUGHNESS_METALLIC_TEXTURE
        vec4 metalRoughMapColor = texture(material_RoughnessMetallicTexture, v_uv);
        roughness *= metalRoughMapColor.g;
        metal *= metalRoughMapColor.b;
    #endif
    #ifdef MATERIAL_HAS_SPECULAR_GLOSSINESS_TEXTURE
        vec4 specularGlossinessColor = texture(material_SpecularGlossinessTexture, v_uv);
        #ifndef ENGINE_IS_COLORSPACE_GAMMA
            specularGlossinessColor = gammaToLinear(specularGlossinessColor);
        #endif
        specularColor *= specularGlossinessColor.rgb;
        glossiness *= specularGlossinessColor.a;
    #endif
    #ifdef IS_METALLIC_WORKFLOW
        material.diffuseColor = baseColor.rgb*(1.0-metal);
        material.specularColor = mix(vec3(f0), baseColor.rgb, metal);
        material.roughness = roughness;
    #else
        float specularStrength = max(max(specularColor.r, specularColor.g), specularColor.b);
        material.diffuseColor = baseColor.rgb*(1.0-specularStrength);
        material.specularColor = specularColor;
        material.roughness = 1.0-glossiness;
    #endif
    material.roughness = max(material.roughness, getAARoughnessFactor(geometry.normal));
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        material.clearCoat = material_ClearCoat;
        material.clearCoatRoughness = material_ClearCoatRoughness;
        #ifdef MATERIAL_HAS_CLEAR_COAT_TEXTURE
            material.clearCoat *= texture(material_ClearCoatTexture, v_uv).r;
        #endif
        #ifdef MATERIAL_HAS_CLEAR_COAT_ROUGHNESS_TEXTURE
            material.clearCoatRoughness *= texture(material_ClearCoatRoughnessTexture, v_uv).g;
        #endif
        material.clearCoat = saturate(material.clearCoat);
        material.clearCoatRoughness = max(material.clearCoatRoughness, getAARoughnessFactor(geometry.clearCoatNormal));
    #endif
    #ifdef MATERIAL_IS_TRANSPARENT
        material.opacity = baseColor.a;
    #else
        material.opacity = 1.0;
    #endif
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        geometry.anisotropicN = getAnisotropicBentNormal(geometry, geometry.normal, material.roughness);
    #endif
}
#define GLSLIFY 1
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
    return 0.5/max(gv+gl, EPSILON);
}
#ifdef MATERIAL_ENABLE_ANISOTROPY
    float G_GGX_SmithCorrelated_Anisotropic(float at, float ab, float ToV, float BoV, float ToL, float BoL, float NoV, float NoL) {
        float lambdaV = NoL*length(vec3(at*ToV, ab*BoV, NoV));
        float lambdaL = NoV*length(vec3(at*ToL, ab*BoL, NoL));
        return 0.5/max(lambdaV+lambdaL, EPSILON);
    }
#endif
float D_GGX(float alpha, float dotNH) {
    float a2 = pow2(alpha);
    float denom = pow2(dotNH)*(a2-1.0)+1.0;
    return RECIPROCAL_PI*a2/pow2(denom);
}
#ifdef MATERIAL_ENABLE_ANISOTROPY
    float D_GGX_Anisotropic(float at, float ab, float ToH, float BoH, float NoH) {
        float a2 = at*ab;
        highp vec3 d = vec3(ab*ToH, at*BoH, a2*NoH);
        highp float d2 = dot(d, d);
        float b2 = a2/d2;
        return a2*b2*b2*RECIPROCAL_PI;
    }
#endif
vec3 isotropicLobe(vec3 specularColor, float alpha, float dotNV, float dotNL, float dotNH, float dotLH) {
    vec3 F = F_Schlick(specularColor, dotLH);
    float D = D_GGX(alpha, dotNH);
    float G = G_GGX_SmithCorrelated(alpha, dotNL, dotNV);
    return F*(G*D);
}
#ifdef MATERIAL_ENABLE_ANISOTROPY
    vec3 anisotropicLobe(vec3 h, vec3 l, Geometry geometry, vec3 specularColor, float alpha, float dotNV, float dotNL, float dotNH, float dotLH) {
        vec3 t = geometry.anisotropicT;
        vec3 b = geometry.anisotropicB;
        vec3 v = geometry.viewDir;
        float dotTV = dot(t, v);
        float dotBV = dot(b, v);
        float dotTL = dot(t, l);
        float dotBL = dot(b, l);
        float dotTH = dot(t, h);
        float dotBH = dot(b, h);
        float at = max(alpha*(1.0+geometry.anisotropy), MIN_ROUGHNESS);
        float ab = max(alpha*(1.0-geometry.anisotropy), MIN_ROUGHNESS);
        vec3 F = F_Schlick(specularColor, dotLH);
        float D = D_GGX_Anisotropic(at, ab, dotTH, dotBH, dotNH);
        float G = G_GGX_SmithCorrelated_Anisotropic(at, ab, dotTV, dotBV, dotTL, dotBL, dotNV, dotNL);
        return F*(G*D);
    }
#endif
vec3 BRDF_Specular_GGX(vec3 incidentDirection, Geometry geometry, vec3 normal, vec3 specularColor, float roughness) {
    float alpha = pow2(roughness);
    vec3 halfDir = normalize(incidentDirection+geometry.viewDir);
    float dotNL = saturate(dot(normal, incidentDirection));
    float dotNV = saturate(dot(normal, geometry.viewDir));
    float dotNH = saturate(dot(normal, halfDir));
    float dotLH = saturate(dot(incidentDirection, halfDir));
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        return anisotropicLobe(halfDir, incidentDirection, geometry, specularColor, alpha, dotNV, dotNL, dotNH, dotLH);
    #else
        return isotropicLobe(specularColor, alpha, dotNV, dotNL, dotNH, dotLH);
    #endif
}
vec3 BRDF_Diffuse_Lambert(vec3 diffuseColor) {
    return RECIPROCAL_PI*diffuseColor;
}
#define GLSLIFY 1
#define GLSLIFY 1
#if defined(SCENE_SHADOW_TYPE) && defined(RENDERER_IS_RECEIVE_SHADOWS)
    #define SCENE_IS_CALCULATE_SHADOWS
#endif
#ifdef SCENE_IS_CALCULATE_SHADOWS
    #if SCENE_SHADOW_CASCADED_COUNT == 1
        in vec3 v_shadowCoord;
    #else
        #define GLSLIFY 1
        uniform mat4 scene_ShadowMatrices[SCENE_SHADOW_CASCADED_COUNT+1];
        uniform vec4 scene_ShadowSplitSpheres[4];
        mediump int computeCascadeIndex(vec3 positionWS) {
            vec3 fromCenter0 = positionWS-scene_ShadowSplitSpheres[0].xyz;
            vec3 fromCenter1 = positionWS-scene_ShadowSplitSpheres[1].xyz;
            vec3 fromCenter2 = positionWS-scene_ShadowSplitSpheres[2].xyz;
            vec3 fromCenter3 = positionWS-scene_ShadowSplitSpheres[3].xyz;
            mediump vec4 comparison = vec4(dot(fromCenter0, fromCenter0)<scene_ShadowSplitSpheres[0].w, dot(fromCenter1, fromCenter1)<scene_ShadowSplitSpheres[1].w, dot(fromCenter2, fromCenter2)<scene_ShadowSplitSpheres[2].w, dot(fromCenter3, fromCenter3)<scene_ShadowSplitSpheres[3].w);
            comparison.yzw = clamp(comparison.yzw-comparison.xyz, 0.0, 1.0);
            mediump vec4 indexCoefficient = vec4(4.0, 3.0, 2.0, 1.0);
            mediump int index = 4-int(dot(comparison, indexCoefficient));
            return index;
        }
        vec3 getShadowCoord() {
            #if SCENE_SHADOW_CASCADED_COUNT == 1
                mediump int cascadeIndex = 0;
            #else
                mediump int cascadeIndex = computeCascadeIndex(v_pos);
            #endif
            #ifdef GRAPHICS_API_WEBGL2
                mat4 shadowMatrix = scene_ShadowMatrices[cascadeIndex];
            #else
                mat4 shadowMatrix;
                #if SCENE_SHADOW_CASCADED_COUNT == 4
                    if(cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    }
                    else if(cascadeIndex == 1) {
                        shadowMatrix = scene_ShadowMatrices[1];
                    }
                    else if(cascadeIndex == 2) {
                        shadowMatrix = scene_ShadowMatrices[2];
                    }
                    else if(cascadeIndex == 3) {
                        shadowMatrix = scene_ShadowMatrices[3];
                    }
                    else {
                        shadowMatrix = scene_ShadowMatrices[4];
                    }
                #endif
                #if SCENE_SHADOW_CASCADED_COUNT == 2
                    if(cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    }
                    else if(cascadeIndex == 1) {
                        shadowMatrix = scene_ShadowMatrices[1];
                    }
                    else {
                        shadowMatrix = scene_ShadowMatrices[2];
                    }
                #endif
                #if SCENE_SHADOW_CASCADED_COUNT == 1
                    if(cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    }
                    else {
                        shadowMatrix = scene_ShadowMatrices[1];
                    }
                #endif
            #endif
            vec4 shadowCoord = shadowMatrix*vec4(v_pos, 1.0);
            return shadowCoord.xyz;
        }
    #endif
    uniform vec4 scene_ShadowInfo;
    uniform vec4 scene_ShadowMapSize;
    #ifdef GRAPHICS_API_WEBGL2
        uniform mediump sampler2DShadow scene_ShadowMap;
        #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) textureLod(textureName, coord3, 0.0)
        #define TEXTURE2D_SHADOW_PARAM(shadowMap) mediump sampler2DShadow shadowMap
    #else
        uniform sampler2D scene_ShadowMap;
        #ifdef ENGINE_NO_DEPTH_TEXTURE
            const vec4 bitShift = vec4(1.0, 1.0/256.0, 1.0/(256.0*256.0), 1.0/(256.0*256.0*256.0));
            float unpack(const in vec4 rgbaDepth) {
                return dot(rgbaDepth, bitShift);
            }
            #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) (unpack(texture(textureName, coord3.xy)) < coord3.z ? 0.0 : 1.0)
        #else
            #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) (texture(textureName, coord3.xy).r < coord3.z ? 0.0 : 1.0)
        #endif
        #define TEXTURE2D_SHADOW_PARAM(shadowMap) mediump sampler2D shadowMap
    #endif
    #if SCENE_SHADOW_TYPE == 2
        float sampleShadowMapFiltered4(TEXTURE2D_SHADOW_PARAM(shadowMap), vec3 shadowCoord, vec4 shadowMapSize) {
            float attenuation;
            vec4 attenuation4;
            vec2 offset = shadowMapSize.xy/2.0;
            vec3 shadowCoord0 = shadowCoord+vec3(-offset, 0.0);
            vec3 shadowCoord1 = shadowCoord+vec3(offset.x, -offset.y, 0.0);
            vec3 shadowCoord2 = shadowCoord+vec3(-offset.x, offset.y, 0.0);
            vec3 shadowCoord3 = shadowCoord+vec3(offset, 0.0);
            attenuation4.x = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord0);
            attenuation4.y = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord1);
            attenuation4.z = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord2);
            attenuation4.w = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord3);
            attenuation = dot(attenuation4, vec4(0.25));
            return attenuation;
        }
    #endif
    #if SCENE_SHADOW_TYPE == 3
        #define GLSLIFY 1
        float sampleShadowGetIRTriangleTexelArea(float triangleHeight) {
            return triangleHeight-0.5;
        }
        void sampleShadowGetTexelAreasTent3x3(float offset, out vec4 computedArea, out vec4 computedAreaUncut) {
            float a = offset+0.5;
            float offsetSquaredHalved = a*a*0.5;
            computedAreaUncut.x = computedArea.x = offsetSquaredHalved-offset;
            computedAreaUncut.w = computedArea.w = offsetSquaredHalved;
            computedAreaUncut.y = sampleShadowGetIRTriangleTexelArea(1.5-offset);
            float clampedOffsetLeft = min(offset, 0.0);
            float areaOfSmallLeftTriangle = clampedOffsetLeft*clampedOffsetLeft;
            computedArea.y = computedAreaUncut.y-areaOfSmallLeftTriangle;
            computedAreaUncut.z = sampleShadowGetIRTriangleTexelArea(1.5+offset);
            float clampedOffsetRight = max(offset, 0.0);
            float areaOfSmallRightTriangle = clampedOffsetRight*clampedOffsetRight;
            computedArea.z = computedAreaUncut.z-areaOfSmallRightTriangle;
        }
        void sampleShadowGetTexelWeightsTent5x5(float offset, out vec3 texelsWeightsA, out vec3 texelsWeightsB) {
            vec4 areaFrom3texelTriangle;
            vec4 areaUncutFrom3texelTriangle;
            sampleShadowGetTexelAreasTent3x3(offset, areaFrom3texelTriangle, areaUncutFrom3texelTriangle);
            texelsWeightsA.x = 0.16*(areaFrom3texelTriangle.x);
            texelsWeightsA.y = 0.16*(areaUncutFrom3texelTriangle.y);
            texelsWeightsA.z = 0.16*(areaFrom3texelTriangle.y+1.0);
            texelsWeightsB.x = 0.16*(areaFrom3texelTriangle.z+1.0);
            texelsWeightsB.y = 0.16*(areaUncutFrom3texelTriangle.z);
            texelsWeightsB.z = 0.16*(areaFrom3texelTriangle.w);
        }
        void sampleShadowComputeSamplesTent5x5(vec4 shadowMapTextureTexelSize, vec2 coord, out float fetchesWeights[9], out vec2 fetchesUV[9]) {
            vec2 tentCenterInTexelSpace = coord.xy*shadowMapTextureTexelSize.zw;
            vec2 centerOfFetchesInTexelSpace = floor(tentCenterInTexelSpace+0.5);
            vec2 offsetFromTentCenterToCenterOfFetches = tentCenterInTexelSpace-centerOfFetchesInTexelSpace;
            vec3 texelsWeightsUA, texelsWeightsUB;
            vec3 texelsWeightsVA, texelsWeightsVB;
            sampleShadowGetTexelWeightsTent5x5(offsetFromTentCenterToCenterOfFetches.x, texelsWeightsUA, texelsWeightsUB);
            sampleShadowGetTexelWeightsTent5x5(offsetFromTentCenterToCenterOfFetches.y, texelsWeightsVA, texelsWeightsVB);
            vec3 fetchesWeightsU = vec3(texelsWeightsUA.xz, texelsWeightsUB.y)+vec3(texelsWeightsUA.y, texelsWeightsUB.xz);
            vec3 fetchesWeightsV = vec3(texelsWeightsVA.xz, texelsWeightsVB.y)+vec3(texelsWeightsVA.y, texelsWeightsVB.xz);
            vec3 fetchesOffsetsU = vec3(texelsWeightsUA.y, texelsWeightsUB.xz)/fetchesWeightsU.xyz+vec3(-2.5, -0.5, 1.5);
            vec3 fetchesOffsetsV = vec3(texelsWeightsVA.y, texelsWeightsVB.xz)/fetchesWeightsV.xyz+vec3(-2.5, -0.5, 1.5);
            fetchesOffsetsU *= shadowMapTextureTexelSize.xxx;
            fetchesOffsetsV *= shadowMapTextureTexelSize.yyy;
            vec2 bilinearFetchOrigin = centerOfFetchesInTexelSpace*shadowMapTextureTexelSize.xy;
            fetchesUV[0] = bilinearFetchOrigin+vec2(fetchesOffsetsU.x, fetchesOffsetsV.x);
            fetchesUV[1] = bilinearFetchOrigin+vec2(fetchesOffsetsU.y, fetchesOffsetsV.x);
            fetchesUV[2] = bilinearFetchOrigin+vec2(fetchesOffsetsU.z, fetchesOffsetsV.x);
            fetchesUV[3] = bilinearFetchOrigin+vec2(fetchesOffsetsU.x, fetchesOffsetsV.y);
            fetchesUV[4] = bilinearFetchOrigin+vec2(fetchesOffsetsU.y, fetchesOffsetsV.y);
            fetchesUV[5] = bilinearFetchOrigin+vec2(fetchesOffsetsU.z, fetchesOffsetsV.y);
            fetchesUV[6] = bilinearFetchOrigin+vec2(fetchesOffsetsU.x, fetchesOffsetsV.z);
            fetchesUV[7] = bilinearFetchOrigin+vec2(fetchesOffsetsU.y, fetchesOffsetsV.z);
            fetchesUV[8] = bilinearFetchOrigin+vec2(fetchesOffsetsU.z, fetchesOffsetsV.z);
            fetchesWeights[0] = fetchesWeightsU.x*fetchesWeightsV.x;
            fetchesWeights[1] = fetchesWeightsU.y*fetchesWeightsV.x;
            fetchesWeights[2] = fetchesWeightsU.z*fetchesWeightsV.x;
            fetchesWeights[3] = fetchesWeightsU.x*fetchesWeightsV.y;
            fetchesWeights[4] = fetchesWeightsU.y*fetchesWeightsV.y;
            fetchesWeights[5] = fetchesWeightsU.z*fetchesWeightsV.y;
            fetchesWeights[6] = fetchesWeightsU.x*fetchesWeightsV.z;
            fetchesWeights[7] = fetchesWeightsU.y*fetchesWeightsV.z;
            fetchesWeights[8] = fetchesWeightsU.z*fetchesWeightsV.z;
        }
        float sampleShadowMapFiltered9(TEXTURE2D_SHADOW_PARAM(shadowMap), vec3 shadowCoord, vec4 shadowmapSize) {
            float attenuation;
            float fetchesWeights[9];
            vec2 fetchesUV[9];
            sampleShadowComputeSamplesTent5x5(shadowmapSize, shadowCoord.xy, fetchesWeights, fetchesUV);
            attenuation = fetchesWeights[0]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[0].xy, shadowCoord.z));
            attenuation += fetchesWeights[1]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[1].xy, shadowCoord.z));
            attenuation += fetchesWeights[2]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[2].xy, shadowCoord.z));
            attenuation += fetchesWeights[3]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[3].xy, shadowCoord.z));
            attenuation += fetchesWeights[4]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[4].xy, shadowCoord.z));
            attenuation += fetchesWeights[5]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[5].xy, shadowCoord.z));
            attenuation += fetchesWeights[6]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[6].xy, shadowCoord.z));
            attenuation += fetchesWeights[7]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[7].xy, shadowCoord.z));
            attenuation += fetchesWeights[8]*SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[8].xy, shadowCoord.z));
            return attenuation;
        }
    #endif
    float getShadowFade(vec3 positionWS) {
        vec3 camToPixel = positionWS-camera_Position;
        float distanceCamToPixel2 = dot(camToPixel, camToPixel);
        return saturate(distanceCamToPixel2*scene_ShadowInfo.z+scene_ShadowInfo.w);
    }
    float sampleShadowMap() {
        #if SCENE_SHADOW_CASCADED_COUNT == 1
            vec3 shadowCoord = v_shadowCoord;
        #else
            vec3 shadowCoord = getShadowCoord();
        #endif
        float attenuation = 1.0;
        if(shadowCoord.z>0.0&&shadowCoord.z<1.0) {
            #if SCENE_SHADOW_TYPE == 1
                attenuation = SAMPLE_TEXTURE2D_SHADOW(scene_ShadowMap, shadowCoord);
            #endif
            #if SCENE_SHADOW_TYPE == 2
                attenuation = sampleShadowMapFiltered4(scene_ShadowMap, shadowCoord, scene_ShadowMapSize);
            #endif
            #if SCENE_SHADOW_TYPE == 3
                attenuation = sampleShadowMapFiltered9(scene_ShadowMap, shadowCoord, scene_ShadowMapSize);
            #endif
            float shadowFade = getShadowFade(v_pos);
            attenuation = mix(1.0, mix(attenuation, 1.0, shadowFade), scene_ShadowInfo.x);
        }
        return attenuation;
    }
#endif
void addDirectRadiance(vec3 incidentDirection, vec3 color, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    float attenuation = 1.0;
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        float clearCoatDotNL = saturate(dot(geometry.clearCoatNormal, incidentDirection));
        vec3 clearCoatIrradiance = clearCoatDotNL*color;
        reflectedLight.directSpecular += material.clearCoat*clearCoatIrradiance*BRDF_Specular_GGX(incidentDirection, geometry, geometry.clearCoatNormal, vec3(0.04), material.clearCoatRoughness);
        attenuation -= material.clearCoat*F_Schlick(material.f0, geometry.clearCoatDotNV);
    #endif
    float dotNL = saturate(dot(geometry.normal, incidentDirection));
    vec3 irradiance = dotNL*color*PI;
    reflectedLight.directSpecular += attenuation*irradiance*BRDF_Specular_GGX(incidentDirection, geometry, geometry.normal, material.specularColor, material.roughness);
    reflectedLight.directDiffuse += attenuation*irradiance*BRDF_Diffuse_Lambert(material.diffuseColor);
}
#ifdef SCENE_DIRECT_LIGHT_COUNT
    void addDirectionalDirectLightRadiance(DirectLight directionalLight, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
        vec3 color = directionalLight.color;
        vec3 direction = -directionalLight.direction;
        addDirectRadiance(direction, color, geometry, material, reflectedLight);
    }
#endif
#ifdef SCENE_POINT_LIGHT_COUNT
    void addPointDirectLightRadiance(PointLight pointLight, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
        vec3 lVector = pointLight.position-geometry.position;
        vec3 direction = normalize(lVector);
        float lightDistance = length(lVector);
        vec3 color = pointLight.color;
        color *= clamp(1.0-pow(lightDistance/pointLight.distance, 4.0), 0.0, 1.0);
        addDirectRadiance(direction, color, geometry, material, reflectedLight);
    }
#endif
#ifdef SCENE_SPOT_LIGHT_COUNT
    void addSpotDirectLightRadiance(SpotLight spotLight, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
        vec3 lVector = spotLight.position-geometry.position;
        vec3 direction = normalize(lVector);
        float lightDistance = length(lVector);
        float angleCos = dot(direction, -spotLight.direction);
        float spotEffect = smoothstep(spotLight.penumbraCos, spotLight.angleCos, angleCos);
        float decayEffect = clamp(1.0-pow(lightDistance/spotLight.distance, 4.0), 0.0, 1.0);
        vec3 color = spotLight.color;
        color *= spotEffect*decayEffect;
        addDirectRadiance(direction, color, geometry, material, reflectedLight);
    }
#endif
void addTotalDirectRadiance(Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    float shadowAttenuation = 1.0;
    #ifdef SCENE_DIRECT_LIGHT_COUNT
        shadowAttenuation = 1.0;
        #ifdef SCENE_IS_CALCULATE_SHADOWS
            shadowAttenuation *= sampleShadowMap();
        #endif
        DirectLight directionalLight;
        for(int i = 0;i<SCENE_DIRECT_LIGHT_COUNT;i++) {
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_DirectLightCullingMask[i])) {
                directionalLight.color = scene_DirectLightColor[i];
                #ifdef SCENE_IS_CALCULATE_SHADOWS
                    if(i == 0) {
                        directionalLight.color *= shadowAttenuation;
                    }
                #endif
                directionalLight.direction = scene_DirectLightDirection[i];
                addDirectionalDirectLightRadiance(directionalLight, geometry, material, reflectedLight);
            }
    
        }
    #endif
    #ifdef SCENE_POINT_LIGHT_COUNT
        PointLight pointLight;
        for(int i = 0;i<SCENE_POINT_LIGHT_COUNT;i++) {
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_PointLightCullingMask[i])) {
                pointLight.color = scene_PointLightColor[i];
                pointLight.position = scene_PointLightPosition[i];
                pointLight.distance = scene_PointLightDistance[i];
                addPointDirectLightRadiance(pointLight, geometry, material, reflectedLight);
            }
    
        }
    #endif
    #ifdef SCENE_SPOT_LIGHT_COUNT
        SpotLight spotLight;
        for(int i = 0;i<SCENE_SPOT_LIGHT_COUNT;i++) {
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_SpotLightCullingMask[i])) {
                spotLight.color = scene_SpotLightColor[i];
                spotLight.position = scene_SpotLightPosition[i];
                spotLight.direction = scene_SpotLightDirection[i];
                spotLight.distance = scene_SpotLightDistance[i];
                spotLight.angleCos = scene_SpotLightAngleCos[i];
                spotLight.penumbraCos = scene_SpotLightPenumbraCos[i];
                addSpotDirectLightRadiance(spotLight, geometry, material, reflectedLight);
            }
    
        }
    #endif

}
#define GLSLIFY 1
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
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        vec3 r = reflect(-geometry.viewDir, geometry.anisotropicN);
    #else
        vec3 r = reflect(-geometry.viewDir, n);
    #endif
    return r;
}
vec3 getLightProbeRadiance(Geometry geometry, vec3 normal, float roughness, int maxMIPLevel, float specularIntensity) {
    #ifndef SCENE_USE_SPECULAR_ENV
        return vec3(0);
    #else
        vec3 reflectVec = getReflectedVector(geometry, normal);
        reflectVec.x = -reflectVec.x;
        float specularMIPLevel = getSpecularMIPLevel(roughness, maxMIPLevel);
        #ifdef HAS_TEX_LOD
            vec4 envMapColor = textureLod(scene_EnvSpecularSampler, reflectVec, specularMIPLevel);
        #else
            vec4 envMapColor = texture(scene_EnvSpecularSampler, reflectVec, specularMIPLevel);
        #endif
        #ifdef SCENE_IS_DECODE_ENV_RGBM
            envMapColor.rgb = RGBMToLinear(envMapColor, 5.0).rgb;
            #ifdef ENGINE_IS_COLORSPACE_GAMMA
                envMapColor = linearToGamma(envMapColor);
            #endif
        #else
            #ifndef ENGINE_IS_COLORSPACE_GAMMA
                envMapColor = gammaToLinear(envMapColor);
            #endif
        #endif
        return envMapColor.rgb*specularIntensity;
    #endif
}
out vec4 glFragColor;
void main() {
    #define GLSLIFY 1
    Geometry geometry;
    Material material;
    ReflectedLight reflectedLight = ReflectedLight(vec3(0.0), vec3(0.0), vec3(0.0), vec3(0.0));
    initGeometry(geometry, gl_FrontFacing);
    initMaterial(material, geometry);
    addTotalDirectRadiance(geometry, material, reflectedLight);
    #ifdef SCENE_USE_SH
        vec3 irradiance = getLightProbeIrradiance(scene_EnvSH, geometry.normal);
        #ifdef ENGINE_IS_COLORSPACE_GAMMA
            irradiance = linearToGamma(vec4(irradiance, 1.0)).rgb;
        #endif
        irradiance *= scene_EnvMapLight.diffuseIntensity;
    #else
        vec3 irradiance = scene_EnvMapLight.diffuse*scene_EnvMapLight.diffuseIntensity;
        irradiance *= PI;
    #endif
    reflectedLight.indirectDiffuse += irradiance*BRDF_Diffuse_Lambert(material.diffuseColor);
    vec3 radiance = getLightProbeRadiance(geometry, geometry.normal, material.roughness, int(scene_EnvMapLight.mipMapLevel), scene_EnvMapLight.specularIntensity);
    float radianceAttenuation = 1.0;
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        vec3 clearCoatRadiance = getLightProbeRadiance(geometry, geometry.clearCoatNormal, material.clearCoatRoughness, int(scene_EnvMapLight.mipMapLevel), scene_EnvMapLight.specularIntensity);
        reflectedLight.indirectSpecular += clearCoatRadiance*material.clearCoat*envBRDFApprox(vec3(0.04), material.clearCoatRoughness, geometry.clearCoatDotNV);
        radianceAttenuation -= material.clearCoat*F_Schlick(material.f0, geometry.clearCoatDotNV);
    #endif
    reflectedLight.indirectSpecular += radianceAttenuation*radiance*envBRDFApprox(material.specularColor, material.roughness, geometry.dotNV);
    #ifdef MATERIAL_HAS_OCCLUSION_TEXTURE
        vec2 aoUV = v_uv;
        #ifdef RENDERER_HAS_UV1
            if(material_OcclusionTextureCoord == 1.0) {
                aoUV = v_uv1;
            }
        #endif
        float ambientOcclusion = (texture(material_OcclusionTexture, aoUV).r-1.0)*material_OcclusionIntensity+1.0;
        reflectedLight.indirectDiffuse *= ambientOcclusion;
        #ifdef SCENE_USE_SPECULAR_ENV
            reflectedLight.indirectSpecular *= computeSpecularOcclusion(ambientOcclusion, material.roughness, geometry.dotNV);
        #endif
    #endif
    vec3 emissiveRadiance = material_EmissiveColor;
    #ifdef MATERIAL_HAS_EMISSIVETEXTURE
        vec4 emissiveColor = texture(material_EmissiveTexture, v_uv);
        #ifndef ENGINE_IS_COLORSPACE_GAMMA
            emissiveColor = gammaToLinear(emissiveColor);
        #endif
        emissiveRadiance *= emissiveColor.rgb;
    #endif
    vec3 totalRadiance = reflectedLight.directDiffuse+reflectedLight.indirectDiffuse+reflectedLight.directSpecular+reflectedLight.indirectSpecular+emissiveRadiance;
    vec4 targetColor = vec4(totalRadiance, material.opacity);
    glFragColor = targetColor;
    #define GLSLIFY 1
    #if SCENE_FOG_MODE ! = 0
        float fogIntensity = ComputeFogIntensity(length(v_positionVS));
        glFragColor.rgb = mix(scene_FogColor.rgb, glFragColor.rgb, fogIntensity);
    #endif
    
    #ifndef ENGINE_IS_COLORSPACE_GAMMA
        glFragColor = linearToGamma(glFragColor);
    #endif
}
