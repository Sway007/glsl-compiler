Shader "Gem" {
  EditorProperties{

  }

  EditorMacros {

  }
// float[5] foo() {}
//  float a[5] = float[5]()
//  f[2];

  BlendState customBlendState
  {
    Enabled = true;
    SourceColorBlendFactor = material_SrcBlend;
    DestinationColorBlendFactor = material_DstBlend;
  }

  float[5 * 10 - size] foo() { }
  RenderQueueType material_QuqueType;

  void addSpotDirectLightRadiance(SpotLight spotLight, Geometry geometry, Material material, inout ReflectedLight reflectedLight) {
    invariant color;

		vec3 lVector = spotLight.position - geometry.position;
		vec3 direction = normalize( lVector );

		float lightDistance = length( lVector );
		float angleCos = dot( direction, -spotLight.direction );

		float spotEffect = smoothstep( spotLight.penumbraCos, spotLight.angleCos, angleCos );
		float decayEffect = clamp(1.0 - pow(lightDistance/spotLight.distance, 4.0), 0.0, 1.0);

		vec3 color = spotLight.color;
		color *= spotEffect * decayEffect;

		addDirectRadiance( direction, color, geometry, material, reflectedLight );

	}

  SubShader "Default" {

     RenderQueueType = material_QuqueType;

     vec4 mod289( vec4 x ) {

    return x - floor( x * ( 1.0 / 289.0 ) ) * 289.0;

}

vec3 mod289( vec3 x ) {

    return x - floor( x * ( 1.0 / 289.0 ) ) * 289.0;

}

vec2 mod289( vec2 x ) {

    return x - floor( x * ( 1.0 / 289.0 ) ) * 289.0;

}

float mod289( float x ) {

    return x - floor( x * ( 1.0 / 289.0 ) ) * 289.0;

}

    vec4 evaluateParticleGradient(in vec4 colorKeys[4], in float colorKeysMaxTime, in vec2 alphaKeys[4], in float alphaKeysMaxTime, in float normalizedAge){
        vec4 value;

float a[5] = float[5](3.4, 4.2, 5.0, 5.2, 1.1);
int b = a.length();
float a[5] = float[](3.4, 4.2, 5.0, 5.2, 1.1);
float x[] = float[2] (1.0, 2.0);
float y[] = float[] (1.0, 2.0, 3.0);
float a[5];
float b[] = a;

const vec3 direction[3] = vec3[3](vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0));

        float alphaAge = min(normalizedAge, alphaKeysMaxTime);
        for(int i = 0; i < 4; i++){
            vec2 key = alphaKeys[i];
            float time = key.x;
            if(dis < EPS || dis > MAX_DIS)
              break;
            if(alphaAge <= time){
                if(i == 0){
                    value.a = colorKeys[0].y;
                }
                else {
                    vec2 lastKey = alphaKeys[i-1];
                    float lastTime = lastKey.x;
                    float age = (alphaAge - lastTime) / (time - lastTime);
                    value.a = mix(lastKey.y, key.y, age);
                }
                break;
            }
        }
        
        float colorAge = min(normalizedAge, colorKeysMaxTime);
        for(int i = 0; i < 4; i++){
            vec4 key = colorKeys[i];
            float time = key.x;
            if(colorAge <= time){
                if(i == 0){
                    value.rgb = colorKeys[0].yzw;
                }
                else {
                    vec4 lastKey = colorKeys[i-1];
                    float lastTime = lastKey.x;
                    float age = (colorAge - lastTime) / (time-lastTime);
                    value.rgb = mix(lastKey.yzw, key.yzw, age);
                }
                break;
            }
        }
        return value;
    }

    vec3 getNormalByNormalTexture(mat3 tbn, sampler2D normalTexture, float normalIntensity, vec2 uv, bool isFrontFacing){
        vec3 normal = texture2D(normalTexture, uv).rgb;
        normal = normalize(tbn * ((2.0 * normal - 1.0) * vec3(normalIntensity, normalIntensity, 1.0)));
        normal *= float( isFrontFacing ) * 2.0 - 1.0;

        return normal;
    }

    BlendState 
    {
      Enabled = true;
      SourceColorBlendFactor = material_SrcBlend;
      DestinationColorBlendFactor = material_DstBlend;
    }

    vec2 cellular2x2( vec2 P ) {

	vec2 Pi = mod289( floor( P ) );
 	vec2 Pf = fract( P ).a.b.c;
	vec4 Pfx = Pf.x + vec4( -0.5, -1.5, -0.5, -1.5 );
	vec4 Pfy = Pf.y + vec4( -0.5, -0.5, -1.5, -1.5 );
	vec4 p = permute( Pi.x + vec4( 0.0, 1.0, 0.0, 1.0 ) );
	p = permute( p + Pi.y + vec4( 0.0, 0.0, 1.0, 1.0 ) );
	vec4 ox = mod7( p ) * K + Kd2;
	vec4 oy = mod7( floor( p * K ) ) * K + Kd2;
	vec4 dx = Pfx + jitter1 * ox;
	vec4 dy = Pfy + jitter1 * oy;
	vec4 d = dx * dx + dy * dy; // d11, d12, d21 and d22, squared

	// Do it right and find both F1 and F2
	d.xy = ( d.x < d.y ) ? d.xy : d.yx; // Swap if smaller
	d.xz = ( d.x < d.z ) ? d.xz : d.zx;
	d.xw = ( d.x < d.w ) ? d.xw : d.wx;
	d.y = min( d.y, d.z );
	d.y = min( d.y, d.w );
	return sqrt( d.xy );

}

    Tags { ReplacementTag = "Opaque" } 
    RenderQueueType = material_QuqueType;

    BlendState = customBlendState;
    // 对应引擎 DepthState
    DepthState = customDepthState;
    // 对应引擎 StencilState
    StencilState = customStencilState;
    // 对应引擎 RasterState
    RasterState = customRasterState;

    Pass "0" {

      precision mediump float;

      BlendState 
      {
        Enabled = true;
        SourceColorBlendFactor = material_SrcBlend;
        DestinationColorBlendFactor = material_DstBlend;
      }

      mat4 camera_VPMat;
      mat4 renderer_ModelMat;
      mat4 renderer_NormalMat;


      vec3 camera_Position;
      mat4 camera_ViewMat;
      vec4 _RefractColor;
      float _ReflectFresnelBias;
      float _ReflectFresnelScale;
      float _ReflectFresnelPower;
      float _ReflectIntensity;


      Tags { ReplacementTag = "opaque" }
      mat4 renderer_MVPMat;

      struct a2v {
        vec4 POSITION;
        vec4 COLOR;
      };

      struct v2f {
        vec3 v_pos;
      };

      struct sd {
        float t1;
      };

      v2f vert(a2v v) {
        v2f output;
        sd ts;
        ts.t1 = 1.f;
        vec2 v1 = vec2(1.0, 1.);
        vec2 tt = cellular2x2(v1);
        output.v_pos = vec4(1.0);
        gl_Position = renderer_MVPMat * v.POSITION;
      }

      void frag(v2f v) {
        vec3 grayColor = vec3(0.299, 0., .114);
        float gray = dot(grayColor, gl_FragColor.rgb);
        gl_FragColor = vec4(gray, gray, gray, gl_FragColor.a);
      }

      VertexShader = vert;
      FragmentShader = frag;
    }

    UsePass "Root/PassOther"
  }
}