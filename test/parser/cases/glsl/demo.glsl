/*originas https://www.shadertoy.com/view/WtdXzS  https://www.shadertoy.com/view/4tyfWy*/
float happy_lucky_star(vec2 uv, float anim) {
    uv = abs(uv);
    vec2 pos = min(uv.xy / uv.yx, anim);
    float p = (2.0 - pos.x - pos.y);
    return (2.0 + p * (p * p - 1.5)) / (uv.x + uv.y);
}

vec2 hash(vec2 p) {
    return fract(sin(vec2(dot(p, vec2(127.1, 311.7)), dot(p, vec2(269.5, 183.3)))) * 43758.5453);
}

float heart(vec2 uv, float h) {
    uv.y -= pow(abs(uv.x), h);
    uv.y *= 1.1;
    return length(uv);
}

mat2 rotate(float angle) {
    float c = cos(angle), s = sin(angle);
    return mat2(c, -s, s, c);
}

vec3 heartLayer(vec2 uv, float idx) {
    vec2 gv = fract(uv) - 0.5;
    vec2 id = floor(uv);
    vec3 minh = vec3(0.);
    float range = 1.;
    vec3 col1 = vec3(1.0, 1.7, 0.3);
    vec3 col2 = vec3(1.8, 0.01, 1.01);

    for(float x = -range; x <= range; ++x) {
        for(float y = -range; y <= range; ++y) {
            vec2 nb = vec2(x, y);
            vec2 p = hash(id + nb + idx) * 0.5;
            vec2 offset = p;//vec2(0);
            //offset = 0.5 + 0.5*sin(iTime + 6.2831*p);
            vec2 hp = gv - nb - offset;
            hp = rotate(fract(idx * 356.2) * 6.2) * hp;
            float h = heart(hp, 1.3) + 5. * clamp(fract(p.x * idx * 718.235), 0., 1.);
            h = 0.01 / pow(h, 5.1);//smoothstep(0.21,0.2,h);
            //h = clamp(h,0.0,1.);
            minh += h * sin(col2 * fract(idx * p.y * 78.235) * 1.);

            //minh = min(minh,pow(h,0.9)*minh);
            //break;
        	//h = smoothstep(.8,2.1,h);

        }
    }
    return minh;
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    vec2 uv = (fragCoord - .5 * iResolution.xy) / iResolution.y;
    float asp = iResolution.x / iResolution.y;
    float c = length(uv);
    float mainheart = heart(uv, 1.3);

    uv = rotate(iTime * 0.1) * uv;
    const float N = 50.;
    vec3 minh = vec3(0.);
    for(float i = 0.; i < 1.; i += 1. / N) {
        float depth = fract(i - iTime * 0.15);
        depth = pow(depth, 1.1);
        depth = smoothstep(0.3, 1., depth);
        float num = mix(6.5, 0.05, depth);
        float fade = pow(depth, 1.2) * smoothstep(1., .97, depth);
        minh += heartLayer(uv * num, i + 1.) * fade;
        float t = depth;
        float si = 0.8 * mix(1., 8.5, t);

        vec3 m = smoothstep(si, si * 0.95, mainheart) * vec3(0.3, 0.25, 0.25) * (1. - t);
        //minh += m*depth;
    }
    float t = fract(iTime * 0.15);

    float f = smoothstep(-0.1, 1.1, c);
    //minh   = mix(vec3(0.,0.,0.),minh,f);
    float fb = smoothstep(0.1, 1., c);
    vec3 forground = vec3(0.05, 0.2, 0.3) * pow(exp(c), 0.7) * 0.2;
    vec3 bg = forground;//mix(vec3(0.,0.,0.),forground,smoothstep(0.,1.,c));
    float fb1 = smoothstep(-0.3, 1.1, f);
    vec3 bg1 = mix(vec3(0.1, 0.2, 0.), vec3(0.1, 0., 1.), fb1);

    fb1 = smoothstep(-0.2, 1.5, f);
    bg1 = mix(vec3(0.1, 0.1, 0.3) * 2., vec3(0.1, 0., 1.), fb1);
    bg += 0.;
    vec3 col = bg + minh;//*vec3(1.,.3,.3);
    uv *= 2.0 * (cos(iTime * 2.0) - 2.5); // scale
    float anim = sin(iTime * 12.0) * 0.1 + 1.0;  // anim between 0.9 - 1.1 
    fragColor = vec4(happy_lucky_star(uv, anim) * vec3(0.35, 0.2, 0.15) + col, 1.0);
}