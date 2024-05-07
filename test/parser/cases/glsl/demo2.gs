Shader "Water" {

  EditorProperties {
    // u_color( "Main Color", Color ) = ( 0, 1, 0, 1 );
    // u_range( "Test Range", Range( 1, 100, 3 ) ) = 10;
    // u_mode( "Mode Toggle", Boolean ) = true;
    // u_texture( "Texture", Texture2D );
    // u_texture2( "TextureCube", TextureCube );
  }

  DepthState depthState {
    Enabled = true;
    WriteEnabled = false;
    CompareFunction = Greater;
  }

  RasterState rasterState {
    CullMode = Front;
    DepthBias = 0.1;
    SlopeScaledDepthBias = 0.8;
  }

  SubShader "subname" {
    Tags { LightMode = "ForwardBase", ReplacementTag = true }

    BlendFactor material_SrcBlend;

    BlendState blendState {
      SourceAlphaBlendFactor = material_SrcBlend;
      Enabled[0] = true;
      ColorWriteMask[0] = 0.8;
      AlphaBlendOperation = BlendOperation.Max;
      BlendColor = Vector4(1.0, 1.0, 1.0, 1.0);
    }

    UsePass "pbr/Default/Forward"

    Pass "default" {

      Tags { ReplacementTag = "Opaque" }

      struct a2v {
       vec4 POSITION;
       vec2 TEXCOORD_0; 
      };

      struct v2f {
       vec2 v_uv;
       vec3 v_position;
      };

      mat4 renderer_MVPMat;
      mat4 renderer_MVMat;

      sampler2D material_BaseTexture;
      vec4 u_color;
      vec4 u_fogColor;
      float u_fogDensity;

      vec4 linearToGamma(vec4 linearIn) {
          return vec4(pow(linearIn.rgb, vec3(1.0 / 2.2)), linearIn.a);
    }

    BlendState = blendState;

    StencilState {
      Enabled = true;
      ReferenceValue = 2;
      Mask = 1.3; // 0xffffffff
      WriteMask = 0.32; // 0xffffffff
      CompareFunctionFront = CompareFunction.Less;
      PassOperationBack = StencilOperation.Zero;
    }

    DepthState = depthState;
    RasterState = rasterState;


      v2f vert(a2v v) {
        v2f o;

        o.v_uv = v.TEXCOORD_0;
        vec4 tmp = renderer_MVMat * POSITION;
        o.v_position = tmp.xyz;
        gl_Position = renderer_MVPMat * v.POSITION;
        return o;
      }

      void frag(v2f i) {
        vec4 color = texture2D(material_BaseTexture, i.v_uv) * u_color;
        float fogDistance = length(i.v_position);
        float fogAmount = 1.0 - exp2(-u_fogDensity * u_fogDensity * fogDistance * fogDistance * 1.442695);
        fogAmount = clamp(fogAmount, 0.0, 1.0);
        gl_FragColor = mix(color, u_fogColor, fogAmount); 

        // For testing only (macro)
          gl_FragColor = linearToGamma(gl_FragColor);

          gl_FragColor = vec4(1.0, 1.0, 0.0, 0.0);
      }

// TODO: 检查main entry varying 类型是否一致，frag main 入参只能有一个结构体类型
      VertexShader = vert;
      FragmentShader = frag;
    }
    UsePass "blinn-phong/Default/Forward"
  }
}