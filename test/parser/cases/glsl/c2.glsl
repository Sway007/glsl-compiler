Quad lights[1];
Quad quads[7];
Sphere spheres[2];
MaterialInput materials[8];

// https://www.researchgate.net/figure/Layout-of-the-Color-Checker-Chart-Used-with-Known-RGB-Values-24-This-figure-provides_fig1_372038692
vec3 colorChecker[24] = vec3[24]
(
    vec3(0.451,0.318,0.267),
    vec3(0.753,0.588,0.510),
    vec3(0.384,0.478,0.616),
    vec3(0.341,0.424,0.263),
    vec3(0.522,0.502,0.694),
    vec3(0.404,0.741,0.667),
    
    vec3(0.839,0.494,0.172),
    vec3(0.314,0.357,0.651),
    vec3(0.757,0.353,0.388),
    vec3(0.369,0.235,0.424),
    vec3(0.616,0.737,0.251),
    vec3(0.878,0.639,0.180),
    
    vec3(0.220,0.251,0.588),
    vec3(0.274,0.580,0.286),
    vec3(0.686,0.212,0.235),
    vec3(0.906,0.780,0.122),
    vec3(0.733,0.337,0.584),
    vec3(0.031,0.522,0.631),
    
    vec3(0.953),
    vec3(0.784),
    vec3(0.627),
    vec3(0.478),
    vec3(0.333),
    vec3(0.204)
);

void MakeScene()
{
    quads[0] = Quad(1, vec3(-6.0, 0.0, -6.0), vec3(0.0, 0.0, 12.0), vec3(12.0, 0.0, 0.0));
    quads[1] = Quad(2, vec3(-6.0, 10.0, -6.0), vec3(12.0, 0.0, 0.0), vec3(0.0, 0.0, 12.0));
    quads[2] = Quad(3, vec3(-6.0, 0.0, -6.0), vec3(0.0, 10.0, 0.0), vec3(0.0, 0.0, 12.0));
    quads[3] = Quad(4, vec3(6.0, 0.0, -6.0), vec3(0.0, 0.0, 12.0), vec3(0.0, 10.0, 0.0));
    quads[4] = Quad(2, vec3(-6.0, 0.0, 6.0), vec3(0.0, 10.0, 0.0), vec3(12.0, 0.0, 0.0));
    quads[5] = Quad(5, vec3(-4.0, 4.0, 5.8), vec3(0.0, 5.0, 0.0), vec3(8.0, 0.0, 0.0));
    
    spheres[0] = Sphere(6, vec3(2.5, 2.0, 0.0), 2.0);
    spheres[1] = Sphere(7, vec3(-2.5, 2.0, 0.0), 2.0);
    
    lights[0] = Quad(0, vec3(-2.0, 9.8, -2.0), vec3(4.0, 0.0, 0.0), vec3(0.0, 0.0, 4.0));
    quads[6] = lights[0];
    
    materials[0] = InitMaterialInput(0, vec4(5.0f, 5.0f, 5.0f, 1.0f), 0.0f, 0.0f);
    materials[1] = InitMaterialInput(2, vec4(0.85f, 0.85f, 0.85f, 1.0f), 0.8f, 0.0f);
    materials[2] = InitMaterialInput(1, vec4(0.88f, 0.88f, 0.88f, 1.0f), 0.9f, 0.0f);
    materials[3] = InitMaterialInput(1, vec4(1.00f, 0.00f, 0.00f, 1.0f), 0.9f, 0.0f);
    materials[4] = InitMaterialInput(1, vec4(0.00f, 1.00f, 0.00f, 1.0f), 0.9f, 0.0f);
    materials[5] = InitMaterialInput(3, vec4(1.00f, 1.00f, 1.00f, 1.0f), 1.0f, 0.0f);
    materials[6] = InitMaterialInput(1, vec4(1.00f, 0.74f, 0.15f, 1.0f), 0.4f, 0.95f);
    materials[7] = InitMaterialInput(1, vec4(0.98f, 0.98f, 0.98f, 1.0f), 0.8f, 0.0f);
}

///////////////////////////////////////////////////
//             Scene Related Tracing             //
///////////////////////////////////////////////////

bool TraceScene(Ray ray, out Intersection intersection, out int materialID)
{
    float d = INFINITY;
    bool hasHit = false;
    for(int i = min(0, iFrame); i < quads.length(); i++)
    {
        float t;
        Intersection tempIntersection;
        bool isHit = RayQuadIntersect(ray, quads[i], t, tempIntersection);
        if(isHit && t < d)
        {
            d = t;
            hasHit = true;
            
            materialID = quads[i].materialID;
            intersection = tempIntersection;
        }
    }
    
    for(int i = min(0, iFrame); i < spheres.length(); i++)
    {
        float t;
        Intersection tempIntersection;
        bool isHit = RaySphereIntersect(ray, spheres[i], t, tempIntersection);
        if(isHit && t < d)
        {
            d = t;
            hasHit = true;
            
            materialID = spheres[i].materialID;
            intersection = tempIntersection;
        }
    }

    return hasHit;
}

bool TraceLight(Ray ray, int lightMaterialID)
{
    float d = INFINITY;
    int materialID = -1;
    for(int i = min(0, iFrame); i < quads.length(); i++)
    {
        float t;
        Intersection tempIntersection;
        bool isHit = RayQuadIntersect(ray, quads[i], t, tempIntersection);
        if(isHit && t < d)
        {
            d = t;
            
            materialID = quads[i].materialID;
        }
    }
    
    for(int i = min(0, iFrame); i < spheres.length(); i++)
    {
        float t;
        Intersection tempIntersection;
        bool isHit = RaySphereIntersect(ray, spheres[i], t, tempIntersection);
        if(isHit && t < d)
        {
            d = t;
            
            materialID = spheres[i].materialID;
        }
    }

    return materialID == lightMaterialID;
}

vec3 GetBackgroundColor(vec3 rd)
{
    return pow(texture(iChannel0, normalize(rd)).rgb, vec3(2.2f));
}

// https://iquilezles.org/articles/checkerfiltering/
float Checkers(vec2 p)
{
    vec2 s = sign(fract(p*.5)-.5);
    return .5 - .5*s.x*s.y;
}

/////////////////////////////////////////
//              Sampling               //
/////////////////////////////////////////

vec3 SampleHemiSphere(vec2 rv)
{
    float theta = acos(rv.x);
    float phi = 2.0 * PI * rv.y;
    float sinTheta = sin(theta);

    return vec3(cos(phi) * sinTheta, sin(phi) * sinTheta, cos(theta));
}

vec3 SampleHemiSphereGGX(vec2 rv, float roughness)
{
    float theta = acos(sqrt((1.0 - rv.x) / ((roughness * roughness - 1.0) * rv.x + 1.0)));
    float phi = 2.0 * PI * rv.y;
    float sinTheta = sin(theta);
    
    return vec3(cos(phi) * sinTheta, sin(phi) * sinTheta, cos(theta));
}

// Sampling Visible GGX Normals with Spherical Caps, Jonathan Dupuy 2023
vec3 SampleVndf_SphericalCaps(vec2 rv, vec3 wi)
{
    float phi = 2.0f * PI * rv.x;
    float z = (1.0f - rv.y) * (1.0f + wi.z) - wi.z;
    float sinTheta = sqrt(clamp(1.0f - z * z, 0.0f, 1.0f));
    float x = sinTheta * cos(phi);
    float y = sinTheta * sin(phi);
    vec3 c = vec3(x, y, z);
    vec3 h = c + wi;
    return h;
}

vec3 SampleVNDF_GGX(vec2 rv, vec3 viewTS, float roughness)
{
    vec3 wiStd = normalize(vec3(viewTS.xy * roughness, viewTS.z));
    vec3 wmStd = SampleVndf_SphericalCaps(rv, wiStd);
    vec3 wm = normalize(vec3(wmStd.xy * roughness, wmStd.z));
    return wm;
}

Ray GetRandomRay(vec2 rv, vec3 lastRayDir, vec3 position, vec3 normal)
{
    Ray ray;
    
    vec3 s = SampleHemiSphere(rv);
    s.z = abs(s.z);
    
    vec3 w = normal;
    vec3 u, v;
    if(abs(dot(normal, vec3(0.0, 1.0, 0.0))) <= SQRT2_2)
    {
        u = normalize(cross(vec3(0.0, 1.0, 0.0), w));
        v = cross(w, u);
    }
    else
    {
        v = normalize(cross(w, vec3(1.0, 0.0, 0.0)));
        u = cross(v, w);
    }
    ray.direction = s.x * u + s.y * v + s.z * w;
    ray.origin = position + ray.direction * EPSILON;
    
    return ray;    
}

Ray GetRandomRay_GGX(vec3 rv, vec3 lastRayDir, vec3 position, vec3 normal, float roughness, float t)
{
    Ray ray;

    vec3 w = normal;
    vec3 s, u, v;
    
    if(abs(dot(normal, vec3(0.0, 1.0, 0.0))) <= SQRT2_2)
    {
        u = normalize(cross(vec3(0.0, 1.0, 0.0), w));
        v = cross(w, u);
    }
    else
    {
        v = normalize(cross(w, vec3(1.0, 0.0, 0.0)));
        u = cross(v, w);
    }

    if(rv.x < t)
    {
        //Sample specular, half vector.
        mat3 tangnetToWorld = mat3(u, v, w);
        vec3 viewTS = (-lastRayDir) * tangnetToWorld; // Notice the order of multiplication.
        s = SampleVNDF_GGX(rv.yz, viewTS, roughness);
    }
    else
    {
        //Sample diffuse, sample vector;
        s = SampleHemiSphere(rv.yz);
    }
    
    s.z = abs(s.z);

    if(rv.x < t)
    {
        vec3 halfVec = s.x * u + s.y * v + s.z * w;
        ray.direction = reflect(lastRayDir, halfVec);
    }
    else
    {
        ray.direction = s.x * u + s.y * v + s.z * w;
    }

    ray.origin = position + ray.direction * EPSILON;

    return ray;
}

Ray GetRandomRay_NEE(vec2 rv, Quad light, vec3 position, vec3 normal, out float dist)
{
    vec3 lightTarget = light.p + light.w * rv.x + light.l * rv.y;

    vec3 lightOrigin = position + normal * EPSILON;
    vec3 lightDirection = normalize(lightTarget - lightOrigin);

    Ray lightRay = Ray(lightOrigin, lightDirection);
    dist = length(lightTarget - lightRay.origin);
    return lightRay;
}

/////////////////////////////////////////
//               PDFs                  //
/////////////////////////////////////////

float PDF_Lambert(vec3 wi, vec3 normal){
    return INV_PI * max(dot(normal, wi), 0.0);
}

float PDF_GGX(vec3 wi, vec3 wo, vec3 normal, float roughness)
{
    vec3 h = normalize(wi + wo);
    float NdotH = max(dot(normal, h), 0.0);
    
    return D_GGX(NdotH, roughness) * NdotH / (4.0 * max(dot(wo, h), EPSILON));
}

float PDF_VNDF(vec3 wi, vec3 wo, vec3 normal, float roughness)
{
    vec3 h = normalize(wi + wo);
    float NoH = max(dot(normal, h), 0.0f);
    float NoV = max(dot(normal, wo), 1e-5f);
    
    // Many terms are cancelled.
    float a2 = roughness * roughness;
    float G1 = 0.5f / (NoV + sqrt(NoV * NoV * (1.0f - a2) + a2));
    return D_GGX(NoH, roughness) * G1;
}

float PDF_Quad(Quad light, Ray ray)
{
    vec3 lightNormal = cross(light.w, light.l);
    float area = length(lightNormal);
    lightNormal = normalize(lightNormal);
    float LNoL = dot(lightNormal, -ray.direction);
    if(LNoL <= 0.0f) return 0.0f;
    
    float t;
    Intersection intersection;
    bool hasIntersect = RayQuadIntersect(ray, light, t, intersection);
    if(!hasIntersect) return 0.0f;
    
    return t * t / (area * LNoL); 
}

float PDF_NEE(Ray ray)
{
    float pdfNEE = 0.0;
    for (int i = min(0, iFrame); i < lights.length(); i++)
    {
        float pdfLight = PDF_Quad(lights[i], ray);
        pdfNEE += pdfLight;
    }
    return pdfNEE / float(lights.length());
}

float PDF_BRDF(vec3 wi, vec3 wo, vec3 normal, float roughness, float t)
{
    return (1.0 - t) * PDF_Lambert(wi, normal) + t * PDF_VNDF(wi, wo, normal, roughness);  
}

void WeightPDF(Ray ray, vec3 wo, vec3 normal, float roughness, float t, out float weightNEE, out float weightBRDF)
{
    float pdfNEE = PDF_NEE(ray);
    float pdfBRDF = PDF_BRDF(ray.direction, wo, normal, roughness, t);
    
    float squareSum = pdfNEE * pdfNEE + pdfBRDF * pdfBRDF;
    if(squareSum == 0.0)
    {
        weightNEE = 1.0;
        weightBRDF = 0.0;
    }
    else
    {
        weightNEE = pdfNEE / squareSum;
        weightBRDF = pdfBRDF / squareSum;
    }
}

/////////////////////////////////////////
//              Evaluate               //
/////////////////////////////////////////

vec3 EvaluateBRDF(SurfaceInput si, MaterialInput mi)
{
    vec3 fr = Fr(si.NoV, si.NoL, si.NoH, si.LoH, mi.roughness, mi.specular);    
    vec3 fd = Fd_Burley(si.NoV, si.NoL, si.LoH, mi.roughness) * mi.diffuse;    
    return (fr + fd) * si.NoL;
}

///////////////////////////////////////////////////
//                Main Function                  //
///////////////////////////////////////////////////

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    if (iFrame == 0)
    {
        fragColor = vec4(0.0f); return;
    }

    uvec2 iFragCoord = uvec2(fragCoord);
    seed = lowbias32(uint(iFrame) + lowbias32(iFragCoord.x + lowbias32(iFragCoord.y)));
 
    MakeScene();
    Camera camera = Camera(vec3(0.0f, 4.0f, -12.0f), vec3(0.0f, 4.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f), 45.0f);  
    Ray ray = InitRay(vec2(GetRandom(), GetRandom()), camera, fragCoord, iResolution.xy);
    
    vec3 color = vec3(0.0f);
    vec3 lastBRDF = vec3(1.0f);
    Intersection intersection;
    int depth = 0;

    while(depth < 10)
    {
        int materialID;
        bool isHit = TraceScene(ray, intersection, materialID);      
        if(!isHit)
        {
            color += lastBRDF * GetBackgroundColor(ray.direction);
            break;
        }
        
        MaterialInput mi = materials[materialID];      
        if(mi.materialType == 0)
        {
            float frontLight = dot(intersection.normal, -ray.direction) > 0.0f ? 1.0f : 0.0f;
            color += lastBRDF * mi.diffuse * frontLight;
            break;
        }
        else if(mi.materialType == 2)
        {
            mi.diffuse = vec3(mix(0.2f, 0.95f, Checkers(intersection.uv * 10.0f)));
        }
        else if(mi.materialType == 3)
        {
            vec2 uv = intersection.uv;
            vec2 fracUV = abs(fract(uv * vec2(4.0f, 6.0f)) - 0.5f);
            int index = int(uv.y * 6.0f) + int((1.0f - uv.x) * 4.0f) * 6;
            vec3 checkerColor = colorChecker[index];
            mi.diffuse = vec3(0.0f);
            
            if (all(lessThanEqual(fracUV, vec2(0.45f)))) mi.diffuse = pow(checkerColor, vec3(2.2f));
        }
        
        float diffuseSum = dot(mi.diffuse, vec3(1.0f));
        float specularSum = dot(mi.specular, vec3(1.0f));
        float t = max(specularSum / (diffuseSum + specularSum), 0.25);     
        
        float weightNEE, weightBRDF;
        vec3 directBRDF = vec3(0.0f);
        for(int i = ZERO; i < lights.length(); i++)
        {
            Quad light = lights[i];        
            float dist;
            Ray lightRay = GetRandomRay_NEE(vec2(GetRandom(), GetRandom()), light, intersection.position, intersection.normal, dist);
            vec3 lightNormal = cross(light.w, light.l);
            float LNoL = dot(lightNormal, -lightRay.direction);
            if(LNoL > 0.0f)
            {
                WeightPDF(lightRay, -ray.direction, intersection.normal, mi.roughness, t, weightNEE, weightBRDF);
                bool isShaded = TraceLight(lightRay, light.materialID);
                if(isShaded)
                {
                    SurfaceInput si = InitSurfaceInput(intersection.position, intersection.normal, -ray.direction, lightRay.direction);
                    MaterialInput lightMI = materials[light.materialID];
                    directBRDF += EvaluateBRDF(si, mi) * weightNEE * lightMI.diffuse;
                }  
            }
        }
        color += lastBRDF * directBRDF;
        
        float probability = 1.0 - min(max(max(lastBRDF.r, lastBRDF.g), lastBRDF.b), 1.0);
        if(GetRandom() < probability) break;
         
        Ray ggxRay = GetRandomRay_GGX(vec3(GetRandom(), GetRandom(), GetRandom()), ray.direction, intersection.position, intersection.normal, mi.roughness, t);
        SurfaceInput si = InitSurfaceInput(intersection.position, intersection.normal, -ray.direction, ggxRay.direction);
        WeightPDF(ggxRay, -ray.direction, intersection.normal, mi.roughness, t, weightNEE, weightBRDF);
        lastBRDF *= EvaluateBRDF(si, mi) * weightBRDF / (1.0f - probability);
        
        ray = ggxRay;
        depth++;
    }
    
    vec4 bufferA = texelFetch(iChannel1, ivec2(iFragCoord), 0);
    if(texelFetch(iChannel2,ivec2(82,0),0).x > 0.)
    {
        fragColor = vec4(color, 1.0);
    }
    else
    {
        bufferA.a += 1.0;
        color = mix(bufferA.rgb, color, 1.0 / bufferA.a);
        fragColor = vec4(color, bufferA.a);
    }
}