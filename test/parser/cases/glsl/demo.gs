Shader "pbr.gs" {
    

    
    
    SubShader "Default" {
      UsePass "pbr/Default/ShadowCaster"

      Pass "Forward Pass" {
        Tags { pipelineStage = "Forward"} 

        

        struct Attributes{
  	vec3 POSITION;

	#ifdef RENDERER_HAS_BLENDSHAPE
    	#ifndef RENDERER_BLENDSHAPE_USE_TEXTURE
    		vec3 POSITION_BS0;
    	  	vec3 POSITION_BS1;
    	  	#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) && defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    	    	vec3 NORMAL_BS0;
    	    	vec3 NORMAL_BS1;
    	    	vec3 TANGENT_BS0;
    	    	vec3 TANGENT_BS1;
    	  	#else
    	    	#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) || defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    	    	  vec3 POSITION_BS2;
    	    	  vec3 POSITION_BS3;

    	    	  #ifdef RENDERER_BLENDSHAPE_HAS_NORMAL
    	    	    vec3 NORMAL_BS0;
    	    	    vec3 NORMAL_BS1;
    	    	    vec3 NORMAL_BS2;
    	    	    vec3 NORMAL_BS3;
    	    	  #endif

    	    	  #ifdef RENDERER_BLENDSHAPE_HAS_TANGENT
    	    	    vec3 TANGENT_BS0;
    	    	    vec3 TANGENT_BS1;
    	    	    vec3 TANGENT_BS2;
    	    	    vec3 TANGENT_BS3;
    	    	  #endif

    	    	#else
    	    	  vec3 POSITION_BS2;
    	    	  vec3 POSITION_BS3;
    	    	  vec3 POSITION_BS4;
    	    	  vec3 POSITION_BS5;
    	    	  vec3 POSITION_BS6;
    	    	  vec3 POSITION_BS7;
    	    #endif
    	#endif
    #endif
  #endif


  #ifdef RENDERER_HAS_UV
      vec2 TEXCOORD_0;
  #endif

  #ifdef RENDERER_HAS_UV1
      vec2 TEXCOORD_1;
  #endif

  #ifdef RENDERER_HAS_SKIN
      vec4 JOINTS_0;
      vec4 WEIGHTS_0;
  #endif

  #ifdef RENDERER_ENABLE_VERTEXCOLOR
      vec4 COLOR_0;
  #endif

  #ifndef MATERIAL_OMIT_NORMAL
      #ifdef RENDERER_HAS_NORMAL
          vec3 NORMAL;
      #endif

      #ifdef RENDERER_HAS_TANGENT
          vec4 TANGENT;
      #endif
  #endif
}

struct Varyings{
	vec2 v_uv;

	#ifdef RENDERER_ENABLE_VERTEXCOLOR
  		vec4 v_color;
	#endif

	#if SCENE_FOG_MODE != 0
	    vec3 v_positionVS;
	#endif

	#ifndef MATERIAL_OMIT_NORMAL
	    #ifdef RENDERER_HAS_NORMAL
	        vec3 v_normal;
	        #if defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
	            mat3 v_TBN;
	        #endif
	    #endif
	#endif

	#ifdef SCENE_IS_CALCULATE_SHADOWS
	    #if SCENE_SHADOW_CASCADED_COUNT==1
	        vec3 v_shadowCoord;
	    #endif
	#endif

	#ifdef RENDERER_HAS_UV1
	    vec2 v_uv1;
	#endif
	#ifdef MATERIAL_NEED_WORLD_POS
	    vec3 v_pos;
	#endif
}

struct Temp_Attributes{
	#ifdef RENDERER_HAS_BLENDSHAPE
    	#ifndef RENDERER_BLENDSHAPE_USE_TEXTURE
    		vec3 POSITION_BS0;
    	  	vec3 POSITION_BS1;
    	  	#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) && defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    	    	vec3 NORMAL_BS0;
    	    	vec3 NORMAL_BS1;
    	    	vec3 TANGENT_BS0;
    	    	vec3 TANGENT_BS1;
    	  	#else
    	    	#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) || defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    	    	  vec3 POSITION_BS2;
    	    	  vec3 POSITION_BS3;

    	    	  #ifdef RENDERER_BLENDSHAPE_HAS_NORMAL
    	    	    vec3 NORMAL_BS0;
    	    	    vec3 NORMAL_BS1;
    	    	    vec3 NORMAL_BS2;
    	    	    vec3 NORMAL_BS3;
    	    	  #endif

    	    	  #ifdef RENDERER_BLENDSHAPE_HAS_TANGENT
    	    	    vec3 TANGENT_BS0;
    	    	    vec3 TANGENT_BS1;
    	    	    vec3 TANGENT_BS2;
    	    	    vec3 TANGENT_BS3;
    	    	  #endif

    	    	#else
    	    	  vec3 POSITION_BS2;
    	    	  vec3 POSITION_BS3;
    	    	  vec3 POSITION_BS4;
    	    	  vec3 POSITION_BS5;
    	    	  vec3 POSITION_BS6;
    	    	  vec3 POSITION_BS7;
    	    #endif
    	#endif
    #endif
  #endif

  vec3 POSITION;

  #ifdef RENDERER_HAS_UV
      vec2 TEXCOORD_0;
  #endif

  #ifdef RENDERER_HAS_UV1
      vec2 TEXCOORD_1;
  #endif

  #ifdef RENDERER_HAS_SKIN
      vec4 JOINTS_0;
      vec4 WEIGHTS_0;
  #endif

  #ifdef RENDERER_ENABLE_VERTEXCOLOR
      vec4 COLOR_0;
  #endif

  #ifndef MATERIAL_OMIT_NORMAL
      #ifdef RENDERER_HAS_NORMAL
          vec3 NORMAL;
      #endif

      #ifdef RENDERER_HAS_TANGENT
          vec4 TANGENT;
      #endif
  #endif
}

struct Temp_Varyings{
	#ifdef RENDERER_ENABLE_VERTEXCOLOR
  		vec4 v_color;
	#endif

	#if SCENE_FOG_MODE != 0
	    vec3 v_positionVS;
	#endif

	#ifndef MATERIAL_OMIT_NORMAL
	    #ifdef RENDERER_HAS_NORMAL
	        vec3 v_normal;
	        #if defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
	            mat3 v_TBN;
	        #endif
	    #endif
	#endif

	#ifdef SCENE_IS_CALCULATE_SHADOWS
	    #if SCENE_SHADOW_CASCADED_COUNT==1
	        vec3 v_shadowCoord;
	    #endif
	#endif

	vec2 v_uv;

	#ifdef RENDERER_HAS_UV1
	    vec2 v_uv1;
	#endif
	#ifdef MATERIAL_NEED_WORLD_POS
	    vec3 v_pos;
	#endif
}

        






float pow2(float x ) {
    return x * x;
}

vec4 RGBMToLinear(vec4 value, float maxRange ) {
    return vec4( value.rgb * value.a * maxRange, 1.0 );
}

vec4 gammaToLinear(vec4 srgbIn){
    return vec4( pow(srgbIn.rgb, vec3(2.2)), srgbIn.a);
}

vec4 linearToGamma(vec4 linearIn){
    return vec4( pow(linearIn.rgb, vec3(1.0 / 2.2)), linearIn.a);
}

vec4 camera_DepthBufferParams;

float remapDepthBufferLinear01(float z){
	return 1.0/ (camera_DepthBufferParams.x * z + camera_DepthBufferParams.y);
}


#ifdef GRAPHICS_API_WEBGL2
	#define INVERSE_MAT(mat) inverse(mat)
#else
	mat2 inverseMat(mat2 m) {
		return mat2(m[1][1],-m[0][1],
				-m[1][0], m[0][0]) / (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
	}
	mat3 inverseMat(mat3 m) {
		float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2];
		float a10 = m[1][0], a11 = m[1][1], a12 = m[1][2];
		float a20 = m[2][0], a21 = m[2][1], a22 = m[2][2];

		float b01 = a22 * a11 - a12 * a21;
		float b11 = -a22 * a10 + a12 * a20;
		float b21 = a21 * a10 - a11 * a20;

		float det = a00 * b01 + a01 * b11 + a02 * b21;

		return mat3(b01, (-a22 * a01 + a02 * a21), (a12 * a01 - a02 * a11),
					b11, (a22 * a00 - a02 * a20), (-a12 * a00 + a02 * a10),
					b21, (-a21 * a00 + a01 * a20), (a11 * a00 - a01 * a10)) / det;
	}
	mat4 inverseMat(mat4 m) {
		float a00 = m[0][0], a01 = m[0][1], a02 = m[0][2], a03 = m[0][3],
			a10 = m[1][0], a11 = m[1][1], a12 = m[1][2], a13 = m[1][3],
			a20 = m[2][0], a21 = m[2][1], a22 = m[2][2], a23 = m[2][3],
			a30 = m[3][0], a31 = m[3][1], a32 = m[3][2], a33 = m[3][3],

			b00 = a00 * a11 - a01 * a10,
			b01 = a00 * a12 - a02 * a10,
			b02 = a00 * a13 - a03 * a10,
			b03 = a01 * a12 - a02 * a11,
			b04 = a01 * a13 - a03 * a11,
			b05 = a02 * a13 - a03 * a12,
			b06 = a20 * a31 - a21 * a30,
			b07 = a20 * a32 - a22 * a30,
			b08 = a20 * a33 - a23 * a30,
			b09 = a21 * a32 - a22 * a31,
			b10 = a21 * a33 - a23 * a31,
			b11 = a22 * a33 - a23 * a32,

			det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

		return mat4(
			a11 * b11 - a12 * b10 + a13 * b09,
			a02 * b10 - a01 * b11 - a03 * b09,
			a31 * b05 - a32 * b04 + a33 * b03,
			a22 * b04 - a21 * b05 - a23 * b03,
			a12 * b08 - a10 * b11 - a13 * b07,
			a00 * b11 - a02 * b08 + a03 * b07,
			a32 * b02 - a30 * b05 - a33 * b01,
			a20 * b05 - a22 * b02 + a23 * b01,
			a10 * b10 - a11 * b08 + a13 * b06,
			a01 * b08 - a00 * b10 - a03 * b06,
			a30 * b04 - a31 * b02 + a33 * b00,
			a21 * b02 - a20 * b04 - a23 * b00,
			a11 * b07 - a10 * b09 - a12 * b06,
			a00 * b09 - a01 * b07 + a02 * b06,
			a31 * b01 - a30 * b03 - a32 * b00,
			a20 * b03 - a21 * b01 + a22 * b00) / det;
	}

	#define INVERSE_MAT(mat) inverseMat(mat)
#endif

        mat4 renderer_LocalMat;
mat4 renderer_ModelMat;
mat4 camera_ViewMat;
mat4 camera_ProjMat;
mat4 renderer_MVMat;
mat4 renderer_MVPMat;
mat4 renderer_NormalMat;

vec3 camera_Position;
vec3 camera_Forward; 

        #ifdef RENDERER_HAS_BLENDSHAPE
	#ifdef RENDERER_BLENDSHAPE_USE_TEXTURE
		mediump sampler2DArray renderer_BlendShapeTexture;
		ivec3 renderer_BlendShapeTextureInfo;
		float renderer_BlendShapeWeights[RENDERER_BLENDSHAPE_COUNT];
	#else
		#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) && defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
			float renderer_BlendShapeWeights[2];
		#else
			#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) || defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
				float renderer_BlendShapeWeights[4];
			#else
				float renderer_BlendShapeWeights[8];
			#endif
		#endif
	#endif

	#ifdef RENDERER_BLENDSHAPE_USE_TEXTURE
		vec3 getBlendShapeVertexElement(int blendShapeIndex, int vertexElementIndex)
		{			
			int y = vertexElementIndex / renderer_BlendShapeTextureInfo.y;
			int x = vertexElementIndex - y * renderer_BlendShapeTextureInfo.y;
			ivec3 uv = ivec3(x, y , blendShapeIndex);
			return (texelFetch(renderer_BlendShapeTexture, uv, 0)).xyz;
		}
	#endif
#endif

        #ifdef RENDERER_HAS_SKIN
  #ifdef RENDERER_USE_JOINT_TEXTURE
    sampler2D renderer_JointSampler;
    float renderer_JointCount;

    mat4 getJointMatrix(sampler2D smp, float index)
    {
        float base = index / renderer_JointCount;
        float hf = 0.5 / renderer_JointCount;
        float v = base + hf;

        vec4 m0 = texture2D(smp, vec2(0.125, v ));
        vec4 m1 = texture2D(smp, vec2(0.375, v ));
        vec4 m2 = texture2D(smp, vec2(0.625, v ));
        vec4 m3 = texture2D(smp, vec2(0.875, v ));

        return mat4(m0, m1, m2, m3);
    }

    #else
        mat4 renderer_JointMatrix[ RENDERER_JOINTS_NUM ];
    #endif
#endif

vec4 material_TilingOffset;



void initVertex(){
    vec4 position = vec4( attr.POSITION , 1.0 );

    #ifndef MATERIAL_OMIT_NORMAL
        #ifdef RENDERER_HAS_NORMAL
            vec3 normal = vec3( attr.NORMAL );
        #endif

        #ifdef RENDERER_HAS_TANGENT
            vec4 tangent = vec4( attr.TANGENT );
        #endif
    #endif


    // blendShape
    #ifdef RENDERER_HAS_BLENDSHAPE
    	#ifdef RENDERER_BLENDSHAPE_USE_TEXTURE	
    		int vertexOffset = gl_VertexID * renderer_BlendShapeTextureInfo.x;
    		for(int i = 0; i < RENDERER_BLENDSHAPE_COUNT; i++){
    			int vertexElementOffset = vertexOffset;
    			float weight = renderer_BlendShapeWeights[i];
    			// Warnning: Multiplying by 0 creates weird precision issues, causing rendering anomalies in Ace2 Android13
    			if(weight != 0.0){
    				position.xyz += getBlendShapeVertexElement(i, vertexElementOffset) * weight;
    
    				#ifndef MATERIAL_OMIT_NORMAL
    					#if defined( RENDERER_HAS_NORMAL ) && defined( RENDERER_BLENDSHAPE_HAS_NORMAL )
    						vertexElementOffset += 1;
    						normal += getBlendShapeVertexElement(i, vertexElementOffset) * weight;
    					#endif
    
    					#if defined( RENDERER_HAS_TANGENT ) && defined(RENDERER_BLENDSHAPE_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) )
    						vertexElementOffset += 1;
    						tangent.xyz += getBlendShapeVertexElement(i, vertexElementOffset) * weight;
    					#endif
    				#endif
    			}
    
    		}
    	#else
    		position.xyz += attr.POSITION_BS0 * renderer_BlendShapeWeights[0];
    		position.xyz += attr.POSITION_BS1 * renderer_BlendShapeWeights[1];

    		#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) && defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    			#ifndef MATERIAL_OMIT_NORMAL
    				#ifdef RENDERER_HAS_NORMAL
    					normal += attr.NORMAL_BS0 * renderer_BlendShapeWeights[0];
    					normal += attr.NORMAL_BS1 * renderer_BlendShapeWeights[1];
    				#endif
    				#if defined( RENDERER_HAS_TANGENT ) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) )
    					tangent.xyz += attr.TANGENT_BS0 * renderer_BlendShapeWeights[0];
    					tangent.xyz += attr.TANGENT_BS1 * renderer_BlendShapeWeights[1];
    				#endif				
    			#endif
    		#else
    			#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) || defined( RENDERER_BLENDSHAPE_HAS_TANGENT )
    				#ifndef MATERIAL_OMIT_NORMAL
    					position.xyz += attr.POSITION_BS2 * renderer_BlendShapeWeights[2];
    					position.xyz += attr.POSITION_BS3 * renderer_BlendShapeWeights[3];

    					#if defined( RENDERER_BLENDSHAPE_HAS_NORMAL ) && defined( RENDERER_HAS_NORMAL )
    						normal += attr.NORMAL_BS0 * renderer_BlendShapeWeights[0];
    						normal += attr.NORMAL_BS1 * renderer_BlendShapeWeights[1];
    						normal += attr.NORMAL_BS2 * renderer_BlendShapeWeights[2];
    						normal += attr.NORMAL_BS3 * renderer_BlendShapeWeights[3];
    					#endif

    					#if defined(RENDERER_BLENDSHAPE_HAS_TANGENT) && defined( RENDERER_HAS_TANGENT ) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) )
    						tangent.xyz += attr.TANGENT_BS0 * renderer_BlendShapeWeights[0];
    						tangent.xyz += attr.TANGENT_BS1 * renderer_BlendShapeWeights[1];
    						tangent.xyz += attr.TANGENT_BS2 * renderer_BlendShapeWeights[2];
    						tangent.xyz += attr.TANGENT_BS3 * renderer_BlendShapeWeights[3];
    					#endif
    				#endif
    			#else
    				position.xyz += attr.POSITION_BS2 * renderer_BlendShapeWeights[2];
    				position.xyz += attr.POSITION_BS3 * renderer_BlendShapeWeights[3];
    				position.xyz += attr.POSITION_BS4 * renderer_BlendShapeWeights[4];
    				position.xyz += attr.POSITION_BS5 * renderer_BlendShapeWeights[5];
    				position.xyz += attr.POSITION_BS6 * renderer_BlendShapeWeights[6];
    				position.xyz += attr.POSITION_BS7 * renderer_BlendShapeWeights[7];
    			#endif
    		#endif
    	#endif
    #endif



    // skin
    #ifdef RENDERER_HAS_SKIN

            #ifdef RENDERER_USE_JOINT_TEXTURE
                mat4 skinMatrix =
                    attr.WEIGHTS_0.x * getJointMatrix(renderer_JointSampler, attr.JOINTS_0.x ) +
                    attr.WEIGHTS_0.y * getJointMatrix(renderer_JointSampler, attr.JOINTS_0.y ) +
                    attr.WEIGHTS_0.z * getJointMatrix(renderer_JointSampler, attr.JOINTS_0.z ) +
                    attr.WEIGHTS_0.w * getJointMatrix(renderer_JointSampler, attr.JOINTS_0.w );

            #else
                mat4 skinMatrix =
                    attr.WEIGHTS_0.x * renderer_JointMatrix[ int( attr.JOINTS_0.x ) ] +
                    attr.WEIGHTS_0.y * renderer_JointMatrix[ int( attr.JOINTS_0.y ) ] +
                    attr.WEIGHTS_0.z * renderer_JointMatrix[ int( attr.JOINTS_0.z ) ] +
                    attr.WEIGHTS_0.w * renderer_JointMatrix[ int( attr.JOINTS_0.w ) ];
            #endif

            position = skinMatrix * position;

            #if defined(RENDERER_HAS_NORMAL) && !defined(MATERIAL_OMIT_NORMAL)
                mat3 skinNormalMatrix = INVERSE_MAT(mat3(skinMatrix));
                normal = normal * skinNormalMatrix;
                #if defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) )
                    tangent.xyz = tangent.xyz * skinNormalMatrix;
                #endif

            #endif

    #endif




    // fog
    #if SCENE_FOG_MODE != 0
        vec4 positionVS = renderer_MVMat * position;
        v.v_positionVS = positionVS.xyz / positionVS.w;
    #endif


    // uv_vert
    #ifdef RENDERER_HAS_UV
        v.v_uv = attr.TEXCOORD_0;
    #else
        // may need this calculate normal
        v.v_uv = vec2( 0.0, 0.0 );
    #endif

    #ifdef RENDERER_HAS_UV1
        v.v_uv1 = attr.TEXCOORD_1;
    #endif

    #ifdef MATERIAL_NEED_TILING_OFFSET
        v.v_uv = v.v_uv * material_TilingOffset.xy + material_TilingOffset.zw;
    #endif


    // color_vert
    #ifdef RENDERER_ENABLE_VERTEXCOLOR
    	v.v_color = COLOR_0;
    #endif


    // normal_vert
    #ifndef MATERIAL_OMIT_NORMAL
        #ifdef RENDERER_HAS_NORMAL
            v.v_normal = normalize( mat3(renderer_NormalMat) * normal );

            #if defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
                vec3 tangentW = normalize( mat3(renderer_NormalMat) * tangent.xyz );
                vec3 bitangentW = cross( v.v_normal, tangentW ) * tangent.w;

                v.v_TBN = mat3( tangentW, bitangentW, v.v_normal );
            #endif
        #endif
    #endif


    // worldpos_vert
    #ifdef MATERIAL_NEED_WORLD_POS
        vec4 temp_pos = renderer_ModelMat * position;
        v.v_pos = temp_pos.xyz / temp_pos.w;
    #endif

    // shadow
    #ifdef SCENE_IS_CALCULATE_SHADOWS
        #if SCENE_SHADOW_CASCADED_COUNT == 1
            v.v_shadowCoord = getShadowCoord(v.v_pos);
        #endif
    #endif

    // position_vert
    gl_Position = renderer_MVPMat * position;
}
        #if defined(SCENE_SHADOW_TYPE) && defined(RENDERER_IS_RECEIVE_SHADOWS)
    #define SCENE_IS_CALCULATE_SHADOWS
#endif

#ifdef SCENE_IS_CALCULATE_SHADOWS
    #if SCENE_SHADOW_CASCADED_COUNT==1

        mat4 scene_ShadowMatrices[SCENE_SHADOW_CASCADED_COUNT + 1];
        vec4 scene_ShadowSplitSpheres[4];

        mediump int computeCascadeIndex(vec3 positionWS) {
            vec3 fromCenter0 = positionWS - scene_ShadowSplitSpheres[0].xyz;
            vec3 fromCenter1 = positionWS - scene_ShadowSplitSpheres[1].xyz;
            vec3 fromCenter2 = positionWS - scene_ShadowSplitSpheres[2].xyz;
            vec3 fromCenter3 = positionWS - scene_ShadowSplitSpheres[3].xyz;

            mediump vec4 comparison = vec4(
                (dot(fromCenter0, fromCenter0) < scene_ShadowSplitSpheres[0].w),
                (dot(fromCenter1, fromCenter1) < scene_ShadowSplitSpheres[1].w),
                (dot(fromCenter2, fromCenter2) < scene_ShadowSplitSpheres[2].w),
                (dot(fromCenter3, fromCenter3) < scene_ShadowSplitSpheres[3].w));
            comparison.yzw = clamp(comparison.yzw - comparison.xyz,0.0,1.0);//keep the nearest
            mediump vec4 indexCoefficient = vec4(4.0,3.0,2.0,1.0);
            mediump int index = 4 - int(dot(comparison, indexCoefficient));
            return index;
        }

        vec3 getShadowCoord(vec3 positionWS) {
            #if SCENE_SHADOW_CASCADED_COUNT == 1
                mediump int cascadeIndex = 0;
            #else
                mediump int cascadeIndex = computeCascadeIndex(positionWS);
            #endif
        
            #ifdef GRAPHICS_API_WEBGL2
                mat4 shadowMatrix = scene_ShadowMatrices[cascadeIndex];
            #else
                mat4 shadowMatrix;
                #if SCENE_SHADOW_CASCADED_COUNT == 4
                    if (cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    } else if (cascadeIndex == 1) {
                        shadowMatrix = scene_ShadowMatrices[1];
                    } else if (cascadeIndex == 2) {
                        shadowMatrix = scene_ShadowMatrices[2];
                    } else if (cascadeIndex == 3) {
                        shadowMatrix = scene_ShadowMatrices[3];
                    } else {
                        shadowMatrix = scene_ShadowMatrices[4];
                    }
                #endif
                #if SCENE_SHADOW_CASCADED_COUNT == 2
                    if (cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    } else if (cascadeIndex == 1) {
                        shadowMatrix = scene_ShadowMatrices[1];
                    } else {
                        shadowMatrix = scene_ShadowMatrices[2];
                    } 
                #endif
                #if SCENE_SHADOW_CASCADED_COUNT == 1
                    if (cascadeIndex == 0) {
                        shadowMatrix = scene_ShadowMatrices[0];
                    } else  {
                        shadowMatrix = scene_ShadowMatrices[1];
                    } 
                #endif
            #endif
        
            vec4 shadowCoord = shadowMatrix * vec4(positionWS, 1.0);
            return shadowCoord.xyz;
        }

    #endif
#endif


#ifdef SCENE_IS_CALCULATE_SHADOWS
    // intensity, null, fadeScale, fadeBias
    vec4 scene_ShadowInfo;
    vec4 scene_ShadowMapSize;

    #ifdef GRAPHICS_API_WEBGL2
        mediump sampler2DShadow scene_ShadowMap;
        #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) textureLod(textureName, coord3 , 0.0)
        #define TEXTURE2D_SHADOW_PARAM(shadowMap) mediump sampler2DShadow shadowMap
    #else
        sampler2D scene_ShadowMap;
        #ifdef ENGINE_NO_DEPTH_TEXTURE
            const vec4 bitShift = vec4(1.0, 1.0/256.0, 1.0/(256.0*256.0), 1.0/(256.0*256.0*256.0));
            /**
            * Unpack depth value.
            */
            float unpack(in vec4 rgbaDepth) {
                return dot(rgbaDepth, bitShift);
            }
            #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) (unpack(texture2D(textureName, coord3.xy)) < coord3.z ? 0.0 : 1.0)
        #else
            #define SAMPLE_TEXTURE2D_SHADOW(textureName, coord3) ((texture2D(textureName, coord3.xy)).r < coord3.z ? 0.0 : 1.0)
        #endif
        #define TEXTURE2D_SHADOW_PARAM(shadowMap) mediump sampler2D shadowMap
    #endif

    #if SCENE_SHADOW_TYPE == 2
        float sampleShadowMapFiltered4(TEXTURE2D_SHADOW_PARAM(shadowMap), vec3 shadowCoord, vec4 shadowMapSize) {
            float attenuation;
            vec4 attenuation4;
            vec2 offset=shadowMapSize.xy/2.0;
            vec3 shadowCoord0=shadowCoord + vec3(-offset,0.0);
            vec3 shadowCoord1=shadowCoord + vec3(offset.x,-offset.y,0.0);
            vec3 shadowCoord2=shadowCoord + vec3(-offset.x,offset.y,0.0);
            vec3 shadowCoord3=shadowCoord + vec3(offset,0.0);
            attenuation4.x = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord0);
            attenuation4.y = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord1);
            attenuation4.z = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord2);
            attenuation4.w = SAMPLE_TEXTURE2D_SHADOW(shadowMap, shadowCoord3);
            attenuation = dot(attenuation4, vec4(0.25));
            return attenuation;
        }
    #endif

    #if SCENE_SHADOW_TYPE == 3
        // ------------------------------------------------------------------
//  PCF Filtering Tent Functions
// ------------------------------------------------------------------

// Assuming a isoceles right angled triangle of height "triangleHeight" (as drawn below).
// This function return the area of the triangle above the first texel(in Y the first texel).
//
// |\      <-- 45 degree slop isosceles right angled triangle
// | \
// ----    <-- length of this side is "triangleHeight"
// _ _ _ _ <-- texels
float sampleShadowGetIRTriangleTexelArea(float triangleHeight) {
    return triangleHeight - 0.5;
}

// Assuming a isoceles triangle of 1.5 texels height and 3 texels wide lying on 4 texels.
// This function return the area of the triangle above each of those texels.
//    |    <-- offset from -0.5 to 0.5, 0 meaning triangle is exactly in the center
//   / \   <-- 45 degree slop isosceles triangle (ie tent projected in 2D)
//  /   \
// _ _ _ _ <-- texels
// X Y Z W <-- result indices (in computedArea.xyzw and computedAreaUncut.xyzw)
// Top point at (right,top) in a texel,left bottom point at (middle,middle) in a texel,right bottom point at (middle,middle) in a texel.
void sampleShadowGetTexelAreasTent3x3(float offset, out vec4 computedArea, out vec4 computedAreaUncut) {
    // Compute the exterior areas,a and h is same.
    float a = offset + 0.5;
    float offsetSquaredHalved = a * a * 0.5;
    computedAreaUncut.x = computedArea.x = offsetSquaredHalved - offset;
    computedAreaUncut.w = computedArea.w = offsetSquaredHalved;

    // Compute the middle areas
    // For Y : We find the area in Y of as if the left section of the isoceles triangle would
    // intersect the axis between Y and Z (ie where offset = 0).
    computedAreaUncut.y = sampleShadowGetIRTriangleTexelArea(1.5 - offset);
    // This area is superior to the one we are looking for if (offset < 0) thus we need to
    // subtract the area of the triangle defined by (0,1.5-offset), (0,1.5+offset), (-offset,1.5).
    float clampedOffsetLeft = min(offset,0.0);
    float areaOfSmallLeftTriangle = clampedOffsetLeft * clampedOffsetLeft;
    computedArea.y = computedAreaUncut.y - areaOfSmallLeftTriangle;

    // We do the same for the Z but with the right part of the isoceles triangle
    computedAreaUncut.z = sampleShadowGetIRTriangleTexelArea(1.5 + offset);
    float clampedOffsetRight = max(offset,0.0);
    float areaOfSmallRightTriangle = clampedOffsetRight * clampedOffsetRight;
    computedArea.z = computedAreaUncut.z - areaOfSmallRightTriangle;
}

// Assuming a isoceles triangle of 2.5 texel height and 5 texels wide lying on 6 texels.
// This function return the weight of each texels area relative to the full triangle area.
//  /       \
// _ _ _ _ _ _ <-- texels
// 0 1 2 3 4 5 <-- computed area indices (in texelsWeights[])
// Top point at (right,top) in a texel,left bottom point at (middle,middle) in a texel,right bottom point at (middle,middle) in a texel.
void sampleShadowGetTexelWeightsTent5x5(float offset, out vec3 texelsWeightsA, out vec3 texelsWeightsB) {
    vec4 areaFrom3texelTriangle;
    vec4 areaUncutFrom3texelTriangle;
    sampleShadowGetTexelAreasTent3x3(offset, areaFrom3texelTriangle, areaUncutFrom3texelTriangle);

    // Triangle slope is 45 degree thus we can almost reuse the result of the 3 texel wide computation.
    // the 5 texel wide triangle can be seen as the 3 texel wide one but shifted up by one unit/texel.
    // 0.16 is 1/(the triangle area)
    texelsWeightsA.x = 0.16 * (areaFrom3texelTriangle.x);
    texelsWeightsA.y = 0.16 * (areaUncutFrom3texelTriangle.y);
    texelsWeightsA.z = 0.16 * (areaFrom3texelTriangle.y + 1.0);
    texelsWeightsB.x = 0.16 * (areaFrom3texelTriangle.z + 1.0);
    texelsWeightsB.y = 0.16 * (areaUncutFrom3texelTriangle.z);
    texelsWeightsB.z = 0.16 * (areaFrom3texelTriangle.w);
}

// 5x5 Tent filter (45 degree sloped triangles in U and V)
void sampleShadowComputeSamplesTent5x5(vec4 shadowMapTextureTexelSize, vec2 coord, out float fetchesWeights[9], out vec2 fetchesUV[9])
{
    // tent base is 5x5 base thus covering from 25 to 36 texels, thus we need 9 bilinear PCF fetches
    vec2 tentCenterInTexelSpace = coord.xy * shadowMapTextureTexelSize.zw;
    vec2 centerOfFetchesInTexelSpace = floor(tentCenterInTexelSpace + 0.5);
    vec2 offsetFromTentCenterToCenterOfFetches = tentCenterInTexelSpace - centerOfFetchesInTexelSpace;

    // find the weight of each texel based on the area of a 45 degree slop tent above each of them.
    vec3 texelsWeightsUA, texelsWeightsUB;
    vec3 texelsWeightsVA, texelsWeightsVB;
    sampleShadowGetTexelWeightsTent5x5(offsetFromTentCenterToCenterOfFetches.x, texelsWeightsUA, texelsWeightsUB);
    sampleShadowGetTexelWeightsTent5x5(offsetFromTentCenterToCenterOfFetches.y, texelsWeightsVA, texelsWeightsVB);

    // each fetch will cover a group of 2x2 texels, the weight of each group is the sum of the weights of the texels
    vec3 fetchesWeightsU = vec3(texelsWeightsUA.xz, texelsWeightsUB.y) + vec3(texelsWeightsUA.y, texelsWeightsUB.xz);
    vec3 fetchesWeightsV = vec3(texelsWeightsVA.xz, texelsWeightsVB.y) + vec3(texelsWeightsVA.y, texelsWeightsVB.xz);

    // move the PCF bilinear fetches to respect texels weights
    vec3 fetchesOffsetsU = vec3(texelsWeightsUA.y, texelsWeightsUB.xz) / fetchesWeightsU.xyz + vec3(-2.5,-0.5,1.5);
    vec3 fetchesOffsetsV = vec3(texelsWeightsVA.y, texelsWeightsVB.xz) / fetchesWeightsV.xyz + vec3(-2.5,-0.5,1.5);
    fetchesOffsetsU *= shadowMapTextureTexelSize.xxx;
    fetchesOffsetsV *= shadowMapTextureTexelSize.yyy;

    vec2 bilinearFetchOrigin = centerOfFetchesInTexelSpace * shadowMapTextureTexelSize.xy;
    fetchesUV[0] = bilinearFetchOrigin + vec2(fetchesOffsetsU.x, fetchesOffsetsV.x);
    fetchesUV[1] = bilinearFetchOrigin + vec2(fetchesOffsetsU.y, fetchesOffsetsV.x);
    fetchesUV[2] = bilinearFetchOrigin + vec2(fetchesOffsetsU.z, fetchesOffsetsV.x);
    fetchesUV[3] = bilinearFetchOrigin + vec2(fetchesOffsetsU.x, fetchesOffsetsV.y);
    fetchesUV[4] = bilinearFetchOrigin + vec2(fetchesOffsetsU.y, fetchesOffsetsV.y);
    fetchesUV[5] = bilinearFetchOrigin + vec2(fetchesOffsetsU.z, fetchesOffsetsV.y);
    fetchesUV[6] = bilinearFetchOrigin + vec2(fetchesOffsetsU.x, fetchesOffsetsV.z);
    fetchesUV[7] = bilinearFetchOrigin + vec2(fetchesOffsetsU.y, fetchesOffsetsV.z);
    fetchesUV[8] = bilinearFetchOrigin + vec2(fetchesOffsetsU.z, fetchesOffsetsV.z);

    fetchesWeights[0] = fetchesWeightsU.x * fetchesWeightsV.x;
    fetchesWeights[1] = fetchesWeightsU.y * fetchesWeightsV.x;
    fetchesWeights[2] = fetchesWeightsU.z * fetchesWeightsV.x;
    fetchesWeights[3] = fetchesWeightsU.x * fetchesWeightsV.y;
    fetchesWeights[4] = fetchesWeightsU.y * fetchesWeightsV.y;
    fetchesWeights[5] = fetchesWeightsU.z * fetchesWeightsV.y;
    fetchesWeights[6] = fetchesWeightsU.x * fetchesWeightsV.z;
    fetchesWeights[7] = fetchesWeightsU.y * fetchesWeightsV.z;
    fetchesWeights[8] = fetchesWeightsU.z * fetchesWeightsV.z;
}

        float sampleShadowMapFiltered9(TEXTURE2D_SHADOW_PARAM(shadowMap), vec3 shadowCoord, vec4 shadowmapSize) {
            float attenuation;
            float fetchesWeights[9];
            vec2 fetchesUV[9];
            sampleShadowComputeSamplesTent5x5(shadowmapSize, shadowCoord.xy, fetchesWeights, fetchesUV);
            attenuation = fetchesWeights[0] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[0].xy, shadowCoord.z));
            attenuation += fetchesWeights[1] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[1].xy, shadowCoord.z));
            attenuation += fetchesWeights[2] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[2].xy, shadowCoord.z));
            attenuation += fetchesWeights[3] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[3].xy, shadowCoord.z));
            attenuation += fetchesWeights[4] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[4].xy, shadowCoord.z));
            attenuation += fetchesWeights[5] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[5].xy, shadowCoord.z));
            attenuation += fetchesWeights[6] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[6].xy, shadowCoord.z));
            attenuation += fetchesWeights[7] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[7].xy, shadowCoord.z));
            attenuation += fetchesWeights[8] * SAMPLE_TEXTURE2D_SHADOW(shadowMap, vec3(fetchesUV[8].xy, shadowCoord.z));
            return attenuation;
        }
    #endif


    float getShadowFade(vec3 positionWS){
        vec3 camToPixel = positionWS - camera_Position;
        float distanceCamToPixel2 = dot(camToPixel, camToPixel);
        return saturate( distanceCamToPixel2 * scene_ShadowInfo.z + scene_ShadowInfo.w );
    }


    float sampleShadowMap(Temp_Varyings v) {
        #if SCENE_SHADOW_CASCADED_COUNT == 1
            vec3 shadowCoord = v.v_shadowCoord;
        #else
            vec3 shadowCoord = getShadowCoord(v.v_pos);
        #endif
        
        float attenuation = 1.0;
        if(shadowCoord.z > 0.0 && shadowCoord.z < 1.0) {
        #if SCENE_SHADOW_TYPE == 1
            attenuation = SAMPLE_TEXTURE2D_SHADOW(scene_ShadowMap, shadowCoord);
        #endif

        #if SCENE_SHADOW_TYPE == 2
            attenuation = sampleShadowMapFiltered4(scene_ShadowMap, shadowCoord, scene_ShadowMapSize);
        #endif

        #if SCENE_SHADOW_TYPE == 3
            attenuation = sampleShadowMapFiltered9(scene_ShadowMap, shadowCoord, scene_ShadowMapSize);
        #endif
            attenuation = mix(1.0, attenuation, scene_ShadowInfo.x);
        }

        float shadowFade = getShadowFade(v.v_pos);
        attenuation = mix(1.0, mix(attenuation, 1.0, shadowFade), scene_ShadowInfo.x);

        return attenuation;
    }
#endif

        #if SCENE_FOG_MODE != 0
    vec4 scene_FogColor;
    vec4 scene_FogParams; // (-1/(end-start), end/(end-start), density/ln(2),density/sprt(ln(2)));

    vec4 fog(vec4 color, vec3 positionVS){
        float fogDepth = length(positionVS);

        #if SCENE_FOG_MODE == 1
            // (end-z) / (end-start) = z * (-1/(end-start)) + (end/(end-start))
            float fogIntensity = clamp(fogDepth * scene_FogParams.x + scene_FogParams.y, 0.0, 1.0);
        #elif SCENE_FOG_MODE == 2
            // exp(-z * density) = exp2((-z * density)/ln(2)) = exp2(-z * density/ln(2))
            float fogIntensity = clamp(exp2(-fogDepth * scene_FogParams.z), 0.0, 1.0);
        #elif SCENE_FOG_MODE == 3
            // exp(-(z * density)^2) = exp2(-(z * density)^2/ln(2)) = exp2(-(z * density/sprt(ln(2)))^2)
            float factor = fogDepth * scene_FogParams.w;
            float fogIntensity = clamp(exp2(-factor * factor), 0.0, 1.0);
        #endif

        color.rgb = mix(scene_FogColor.rgb, color.rgb, fogIntensity);

        return color;
    }
#endif

        // Directional light
#ifdef SCENE_DIRECT_LIGHT_COUNT

    struct DirectLight {
        vec3 color;
        vec3 direction;
    }

    ivec2 scene_DirectLightCullingMask[SCENE_DIRECT_LIGHT_COUNT];
    vec3 scene_DirectLightColor[SCENE_DIRECT_LIGHT_COUNT];
    vec3 scene_DirectLightDirection[SCENE_DIRECT_LIGHT_COUNT];

#endif


// Point light
#ifdef SCENE_POINT_LIGHT_COUNT

    struct PointLight {
        vec3 color;
        vec3 position;
        float distance;
    }

    ivec2 scene_PointLightCullingMask[ SCENE_POINT_LIGHT_COUNT ];
    vec3 scene_PointLightColor[ SCENE_POINT_LIGHT_COUNT ];
    vec3 scene_PointLightPosition[ SCENE_POINT_LIGHT_COUNT ];
    float scene_PointLightDistance[ SCENE_POINT_LIGHT_COUNT ];

#endif


// Spot light
#ifdef SCENE_SPOT_LIGHT_COUNT

    struct SpotLight {
        vec3 color;
        vec3 position;
        vec3 direction;
        float distance;
        float angleCos;
        float penumbraCos;
    }

    ivec2 scene_SpotLightCullingMask[ SCENE_SPOT_LIGHT_COUNT ];
    vec3 scene_SpotLightColor[ SCENE_SPOT_LIGHT_COUNT ];
    vec3 scene_SpotLightPosition[ SCENE_SPOT_LIGHT_COUNT ];
    vec3 scene_SpotLightDirection[ SCENE_SPOT_LIGHT_COUNT ];
    float scene_SpotLightDistance[ SCENE_SPOT_LIGHT_COUNT ];
    float scene_SpotLightAngleCos[ SCENE_SPOT_LIGHT_COUNT ];
    float scene_SpotLightPenumbraCos[ SCENE_SPOT_LIGHT_COUNT ];

#endif

// Ambient light
struct EnvMapLight {
    vec3 diffuse;
    float mipMapLevel;
    float diffuseIntensity;
    float specularIntensity;
}


EnvMapLight scene_EnvMapLight;
ivec4 renderer_Layer;

#ifdef SCENE_USE_SH
    vec3 scene_EnvSH[9];
#endif

#ifdef SCENE_USE_SPECULAR_ENV
    samplerCube scene_EnvSpecularSampler;
#endif

#ifndef GRAPHICS_API_WEBGL2
bool isBitSet(float value, float mask, float bitIndex)
{
    return mod(floor(value / pow(2.0, bitIndex)), 2.0) == 1.0 && mod(floor(mask / pow(2.0, bitIndex)), 2.0) == 1.0;
}
#endif

bool isRendererCulledByLight(ivec2 rendererLayer, ivec2 lightCullingMask)
{
    #ifdef GRAPHICS_API_WEBGL2
    return !((rendererLayer.x & lightCullingMask.x) != 0 || (rendererLayer.y & lightCullingMask.y) != 0);
    #else
    for (int i = 0; i < 16; i++) {
        if (isBitSet( float(rendererLayer.x), float(lightCullingMask.x), float(i)) || isBitSet( float(rendererLayer.y), float(lightCullingMask.y), float(i))) {
            return false;
        }
    }
    return true;
    #endif
}


        // #ifndef SHADING_PBR_INCLUDED
// #define SHADING_PBR_INCLUDED 1




float material_AlphaCutoff;
vec4 material_BaseColor;
float material_Metal;
float material_Roughness;
float material_IOR;
vec3 material_PBRSpecularColor;
float material_Glossiness;
vec3 material_EmissiveColor;
float material_NormalIntensity;
float material_OcclusionIntensity;
float material_OcclusionTextureCoord;

#ifdef MATERIAL_ENABLE_CLEAR_COAT
    float material_ClearCoat;
    float material_ClearCoatRoughness;

    #ifdef MATERIAL_HAS_CLEAR_COAT_TEXTURE
        sampler2D material_ClearCoatTexture;
    #endif

    #ifdef MATERIAL_HAS_CLEAR_COAT_ROUGHNESS_TEXTURE
        sampler2D material_ClearCoatRoughnessTexture;
    #endif

    #ifdef MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE
        sampler2D material_ClearCoatNormalTexture;
    #endif
#endif

#ifdef MATERIAL_ENABLE_ANISOTROPY
    vec3 material_AnisotropyInfo;
    #ifdef MATERIAL_HAS_ANISOTROPY_TEXTURE
        sampler2D material_AnisotropyTexture;
    #endif
#endif

// Texture
#ifdef MATERIAL_HAS_BASETEXTURE
    sampler2D material_BaseTexture;
#endif

#ifdef MATERIAL_HAS_NORMALTEXTURE
    sampler2D material_NormalTexture;
#endif

#ifdef MATERIAL_HAS_EMISSIVETEXTURE
    sampler2D material_EmissiveTexture;
#endif

#ifdef MATERIAL_HAS_ROUGHNESS_METALLIC_TEXTURE
    sampler2D material_RoughnessMetallicTexture;
#endif


#ifdef MATERIAL_HAS_SPECULAR_GLOSSINESS_TEXTURE
    sampler2D material_SpecularGlossinessTexture;
#endif

#ifdef MATERIAL_HAS_OCCLUSION_TEXTURE
    sampler2D material_OcclusionTexture;
#endif


float evaluateDiffuseAO(Temp_Varyings v){
    float diffuseAO = 1.0;

    #ifdef MATERIAL_HAS_OCCLUSION_TEXTURE
        vec2 aoUV = v.v_uv;
        #ifdef RENDERER_HAS_UV1
            if(material_OcclusionTextureCoord == 1.0){
                aoUV = v.v_uv1;
            }
        #endif
        diffuseAO = ((texture2D(material_OcclusionTexture, aoUV)).r - 1.0) * material_OcclusionIntensity + 1.0;
    #endif

    return diffuseAO;
}

float evaluateSpecularAO(float diffuseAO, float roughness, float dotNV){
    float specularAO = 1.0;

    #if defined(MATERIAL_HAS_OCCLUSION_TEXTURE) && defined(SCENE_USE_SPECULAR_ENV) 
        specularAO = saturate( pow( dotNV + diffuseAO, exp2( - 16.0 * roughness - 1.0 ) ) - 1.0 + diffuseAO );
    #endif

    return specularAO;
}


float getAARoughnessFactor(vec3 normal) {
    // Kaplanyan 2016, "Stable specular highlights"
    // Tokuyoshi 2017, "Error Reduction and Simplification for Shading Anti-Aliasing"
    // Tokuyoshi and Kaplanyan 2019, "Improved Geometric Specular Antialiasing"
    #ifdef HAS_DERIVATIVES
        vec3 dxy = max( abs(dFdx(normal)), abs(dFdy(normal)) );
        return MIN_PERCEPTUAL_ROUGHNESS + max( max(dxy.x, dxy.y), dxy.z );
    #else
        return MIN_PERCEPTUAL_ROUGHNESS;
    #endif
}

// gl_FrontFacing has random value on Adreno GPUs
// the Adreno bug is only when gl_FrontFacing is inside a function
// https://bugs.chromium.org/p/chromium/issues/detail?id=1154842
vec3 getNormal(Temp_Varyings v, bool isFrontFacing){
    #ifdef RENDERER_HAS_NORMAL
        vec3 normal = normalize(v.v_normal);
    #elif defined(HAS_DERIVATIVES)
        vec3 pos_dx = dFdx(v.v_pos);
        vec3 pos_dy = dFdy(v.v_pos);
        vec3 normal = normalize( cross(pos_dx, pos_dy) );
    #else
        vec3 normal = vec3(0, 0, 1);
    #endif

    normal *= float( isFrontFacing ) * 2.0 - 1.0;
    return normal;
}

vec3 getNormalByNormalTexture(mat3 tbn, sampler2D normalTexture, float normalIntensity, vec2 uv, bool isFrontFacing){
    vec3 normal = (texture2D(normalTexture, uv)).rgb;
    normal = normalize(tbn * ((2.0 * normal - 1.0) * vec3(normalIntensity, normalIntensity, 1.0)));
    normal *= float( isFrontFacing ) * 2.0 - 1.0;

    return normal;
}

mat3 getTBN(Temp_Varyings v, bool isFrontFacing){
    #if defined(RENDERER_HAS_NORMAL) && defined(RENDERER_HAS_TANGENT) && ( defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY) )
        mat3 tbn = v.v_TBN;
    #else
        vec3 normal = getNormal(v, isFrontFacing);
        vec3 position = v.v_pos;
        vec2 uv = isFrontFacing? v.v_uv: -v.v_uv;

        #ifdef HAS_DERIVATIVES
            // ref: http://www.thetenthplanet.de/archives/1180
            // get edge vectors of the pixel triangle
	        vec3 dp1 = dFdx(position);
	        vec3 dp2 = dFdy(position);
	        vec2 duv1 = dFdx(uv);
	        vec2 duv2 = dFdy(uv);

	        // solve the linear system
	        vec3 dp2perp = cross(dp2, normal);
	        vec3 dp1perp = cross(normal, dp1);
	        vec3 tangent = dp2perp * duv1.x + dp1perp * duv2.x;
	        vec3 bitangent = dp2perp * duv1.y + dp1perp * duv2.y;

	        // construct a scale-invariant frame 
	        float invmax = inversesqrt(max(dot(tangent, tangent), dot(bitangent, bitangent)));
	        mat3 tbn = mat3(tangent * invmax, bitangent * invmax, normal);
        #else
            mat3 tbn = mat3(vec3(0.0), vec3(0.0), normal);
        #endif
    #endif
	
    return tbn;
}

struct SurfaceData{
	vec3  position;
    vec3  normal;
    vec3  viewDir;
    float dotNV;
    
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        vec3 clearCoatNormal;
        float clearCoatDotNV;
    #endif

    #ifdef MATERIAL_ENABLE_ANISOTROPY
        vec3  anisotropicT;
        vec3  anisotropicB;
        vec3  anisotropicN;
        float anisotropy;
    #endif
	
	vec3  diffuseColor;
    float roughness;
    vec3  specularColor;
    float opacity;
    float f0;
    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        float clearCoat;
        float clearCoatRoughness;
    #endif
	vec3 emissive;
}


#ifdef MATERIAL_ENABLE_ANISOTROPY
    // Aniso Bent Normals
    // Mc Alley https://www.gdcvault.com/play/1022235/Rendering-the-World-of-Far 
    vec3 getAnisotropicBentNormal(SurfaceData surfaceData) {
        vec3  anisotropyDirection = (surfaceData.anisotropy >= 0.0) ? surfaceData.anisotropicB : surfaceData.anisotropicT;
        vec3  anisotropicTangent  = cross(anisotropyDirection, surfaceData.viewDir);
        vec3  anisotropicNormal   = cross(anisotropicTangent, anisotropyDirection);
        // reduce stretching for (roughness < 0.2), refer to https://advances.realtimerendering.com/s2018/Siggraph%202018%20HDRP%20talk_with%20notes.pdf 80
        vec3  bentNormal          = normalize( mix(surfaceData.normal, anisotropicNormal, abs(surfaceData.anisotropy) * saturate( 5.0 * surfaceData.roughness)) );

        return bentNormal;
    }
#endif



void initGeometry(Temp_Varyings v, inout SurfaceData surfaceData, bool isFrontFacing){
    surfaceData.position = v.v_pos;
    #ifdef CAMERA_ORTHOGRAPHIC
        surfaceData.viewDir =  -camera_Forward;
    #else
        surfaceData.viewDir =  normalize(camera_Position - v.v_pos);
    #endif
    #if defined(MATERIAL_HAS_NORMALTEXTURE) || defined(MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE) || defined(MATERIAL_ENABLE_ANISOTROPY)
        mat3 tbn = getTBN(v, isFrontFacing);
    #endif

    #ifdef MATERIAL_HAS_NORMALTEXTURE
        surfaceData.normal = getNormalByNormalTexture(tbn, material_NormalTexture, material_NormalIntensity, v.v_uv, isFrontFacing);
    #else
        surfaceData.normal = getNormal(v, isFrontFacing);
    #endif

    surfaceData.dotNV = clamp(  dot(surfaceData.normal, surfaceData.viewDir) , 0.0, 1.0 );


    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        #ifdef MATERIAL_HAS_CLEAR_COAT_NORMAL_TEXTURE
            surfaceData.clearCoatNormal = getNormalByNormalTexture(tbn, material_ClearCoatNormalTexture, material_NormalIntensity, v.v_uv, isFrontFacing);
        #else
            surfaceData.clearCoatNormal = getNormal(v, isFrontFacing);
        #endif
        surfaceData.clearCoatDotNV = saturate( dot(surfaceData.clearCoatNormal, surfaceData.viewDir) );
    #endif

    #ifdef MATERIAL_ENABLE_ANISOTROPY
        float anisotropy = material_AnisotropyInfo.z;
        vec3 anisotropicDirection = vec3(material_AnisotropyInfo.xy, 0.0);
        #ifdef MATERIAL_HAS_ANISOTROPY_TEXTURE
            vec3 anisotropyTextureInfo = (texture2D( material_AnisotropyTexture, v.v_uv )).rgb;
            anisotropy *= anisotropyTextureInfo.b;
            anisotropicDirection.xy *= anisotropyTextureInfo.rg * 2.0 - 1.0;
        #endif

        surfaceData.anisotropy = anisotropy;
        surfaceData.anisotropicT = normalize(tbn * anisotropicDirection);
        surfaceData.anisotropicB = normalize(cross(surfaceData.normal, surfaceData.anisotropicT));
        surfaceData.anisotropicN = getAnisotropicBentNormal(surfaceData);

    #endif
}

void initMaterial(Temp_Varyings v, inout SurfaceData surfaceData){
        vec4 baseColor = material_BaseColor;
        float metal = material_Metal;
        float roughness = material_Roughness;
        vec3 specularColor = material_PBRSpecularColor;
        float glossiness = material_Glossiness;
        float alphaCutoff = material_AlphaCutoff;
        float f0 = pow2( (material_IOR - 1.0) / (material_IOR + 1.0) );

        surfaceData.f0 = f0;

        #ifdef MATERIAL_HAS_BASETEXTURE
            vec4 baseTextureColor = texture2D(material_BaseTexture, v.v_uv);
            #ifndef ENGINE_IS_COLORSPACE_GAMMA
                baseTextureColor = gammaToLinear(baseTextureColor);
            #endif
            baseColor *= baseTextureColor;
        #endif

        #ifdef RENDERER_ENABLE_VERTEXCOLOR
            baseColor *= v.v_color;
        #endif


        #ifdef MATERIAL_IS_ALPHA_CUTOFF
            if( baseColor.a < alphaCutoff ) {
                discard;
            }
        #endif

        #ifdef MATERIAL_HAS_ROUGHNESS_METALLIC_TEXTURE
            vec4 metalRoughMapColor = texture2D( material_RoughnessMetallicTexture, v.v_uv );
            roughness *= metalRoughMapColor.g;
            metal *= metalRoughMapColor.b;
        #endif

        #ifdef MATERIAL_HAS_SPECULAR_GLOSSINESS_TEXTURE
            vec4 specularGlossinessColor = texture2D(material_SpecularGlossinessTexture, v.v_uv );
            #ifndef ENGINE_IS_COLORSPACE_GAMMA
                specularGlossinessColor = gammaToLinear(specularGlossinessColor);
            #endif
            specularColor *= specularGlossinessColor.rgb;
            glossiness *= specularGlossinessColor.a;
        #endif


        #ifdef IS_METALLIC_WORKFLOW
            surfaceData.diffuseColor = baseColor.rgb * ( 1.0 - metal );
            surfaceData.specularColor = mix( vec3(f0), baseColor.rgb, metal );
            surfaceData.roughness = roughness;
        #else
            float specularStrength = max( max( specularColor.r, specularColor.g ), specularColor.b );
            surfaceData.diffuseColor = baseColor.rgb * ( 1.0 - specularStrength );
            surfaceData.specularColor = specularColor;
            surfaceData.roughness = 1.0 - glossiness;
        #endif

        surfaceData.roughness = max(surfaceData.roughness, getAARoughnessFactor(surfaceData.normal));

        #ifdef MATERIAL_ENABLE_CLEAR_COAT
            surfaceData.clearCoat = material_ClearCoat;
            surfaceData.clearCoatRoughness = material_ClearCoatRoughness;
            #ifdef MATERIAL_HAS_CLEAR_COAT_TEXTURE
                surfaceData.clearCoat *= (texture2D( material_ClearCoatTexture, v.v_uv )).r;
            #endif
            #ifdef MATERIAL_HAS_CLEAR_COAT_ROUGHNESS_TEXTURE
                surfaceData.clearCoatRoughness *= (texture2D( material_ClearCoatRoughnessTexture, v.v_uv )).g;
            #endif
            surfaceData.clearCoat = saturate( surfaceData.clearCoat );
            surfaceData.clearCoatRoughness = max(surfaceData.clearCoatRoughness, getAARoughnessFactor(surfaceData.clearCoatNormal));
        #endif

        #ifdef MATERIAL_IS_TRANSPARENT
            surfaceData.opacity = baseColor.a;
        #else
            surfaceData.opacity = 1.0;
        #endif

        vec3 emissiveRadiance = material_EmissiveColor;
        #ifdef MATERIAL_HAS_EMISSIVETEXTURE
            vec4 emissiveColor = texture2D(material_EmissiveTexture, v.v_uv);
            #ifndef ENGINE_IS_COLORSPACE_GAMMA
                emissiveColor = gammaToLinear(emissiveColor);
            #endif
        emissiveRadiance *= emissiveColor.rgb;
        #endif
        surfaceData.emissive = emissiveRadiance;

}

void initSurfaceData(Temp_Varyings v, out SurfaceData surfaceData, bool isFrontFacing){
    initGeometry(v, surfaceData, isFrontFacing);
    initMaterial(v, surfaceData);
}


#ifndef LIGHT_DIRECT_PBR_INCLUDED
// #define LIGHT_DIRECT_PBR_INCLUDED 1


#ifndef BRDF_INCLUDED
#define BRDF_INCLUDED 1

float F_Schlick(float f0, float dotLH) {
	return f0 + 0.96 * (pow(1.0 - dotLH, 5.0));
}

vec3 F_Schlick(vec3 specularColor, float dotLH ) {

	// Original approximation by Christophe Schlick '94
	// float fresnel = pow( 1.0 - dotLH, 5.0 );

	// Optimized variant (presented by Epic at SIGGRAPH '13)
	// https://cdn2.unrealengine.com/Resources/files/2013SiggraphPresentationsNotes-26915738.pdf
	float fresnel = exp2( ( -5.55473 * dotLH - 6.98316 ) * dotLH );

	return ( 1.0 - specularColor ) * fresnel + specularColor;

}

// Moving Frostbite to Physically Based Rendering 3.0 - page 12, listing 2
// https://seblagarde.files.wordpress.com/2015/07/course_notes_moving_frostbite_to_pbr_v32.pdf
float G_GGX_SmithCorrelated(float alpha, float dotNL, float dotNV ) {

	float a2 = pow2( alpha );

	// dotNL and dotNV are explicitly swapped. This is not a mistake.
	float gv = dotNL * sqrt( a2 + ( 1.0 - a2 ) * pow2( dotNV ) );
	float gl = dotNV * sqrt( a2 + ( 1.0 - a2 ) * pow2( dotNL ) );

	return 0.5 / max( gv + gl, EPSILON );

}

#ifdef MATERIAL_ENABLE_ANISOTROPY
    // Heitz 2014, "Understanding the Masking-Shadowing Function in Microfacet-Based BRDFs"
    // Heitz http://jcgt.org/published/0003/02/03/paper.pdf
    float G_GGX_SmithCorrelated_Anisotropic(float at, float ab, float ToV, float BoV, float ToL, float BoL, float NoV, float NoL) {
        float lambdaV = NoL * length(vec3(at * ToV, ab * BoV, NoV));
        float lambdaL = NoV * length(vec3(at * ToL, ab * BoL, NoL));
        return 0.5 / max(lambdaV + lambdaL, EPSILON);
    }
#endif

// Microfacet Models for Refraction through Rough Surfaces - equation (33)
// http://graphicrants.blogspot.com/2013/08/specular-brdf-reference.html
// alpha is "roughness squared" in Disney’s reparameterization
float D_GGX(float alpha, float dotNH ) {

	float a2 = pow2( alpha );

	float denom = pow2( dotNH ) * ( a2 - 1.0 ) + 1.0; // avoid alpha = 0 with dotNH = 1

	return RECIPROCAL_PI * a2 / pow2( denom );

}

#ifdef MATERIAL_ENABLE_ANISOTROPY
    // GGX Distribution Anisotropic
    // https://blog.selfshadow.com/publications/s2012-shading-course/burley/s2012_pbs_disney_brdf_notes_v3.pdf Addenda
    float D_GGX_Anisotropic(float at, float ab, float ToH, float BoH, float NoH) {
        float a2 = at * ab;
        highp vec3 d = vec3(ab * ToH, at * BoH, a2 * NoH);
        highp float d2 = dot(d, d);
        float b2 = a2 / d2;
        return a2 * b2 * b2 * RECIPROCAL_PI;
    }
#endif

vec3 isotropicLobe(vec3 specularColor, float alpha, float dotNV, float dotNL, float dotNH, float dotLH) {
	vec3 F = F_Schlick( specularColor, dotLH );
	float D = D_GGX( alpha, dotNH );
	float G = G_GGX_SmithCorrelated( alpha, dotNL, dotNV );

	return F * ( G * D );
}

#ifdef MATERIAL_ENABLE_ANISOTROPY
    vec3 anisotropicLobe(vec3 h, vec3 l, SurfaceData surfaceData, vec3 specularColor, float alpha, float dotNV, float dotNL, float dotNH, float dotLH) {
        vec3 t = surfaceData.anisotropicT;
        vec3 b = surfaceData.anisotropicB;
        vec3 v = surfaceData.viewDir;

        float dotTV = dot(t, v);
        float dotBV = dot(b, v);
        float dotTL = dot(t, l);
        float dotBL = dot(b, l);
        float dotTH = dot(t, h);
        float dotBH = dot(b, h);

        // Aniso parameter remapping
        // https://blog.selfshadow.com/publications/s2017-shading-course/imageworks/s2017_pbs_imageworks_slides_v2.pdf page 24
        float at = max(alpha * (1.0 + surfaceData.anisotropy), MIN_ROUGHNESS);
        float ab = max(alpha * (1.0 - surfaceData.anisotropy), MIN_ROUGHNESS);

        // specular anisotropic BRDF
    	vec3 F = F_Schlick( specularColor, dotLH );
        float D = D_GGX_Anisotropic(at, ab, dotTH, dotBH, dotNH);
        float G = G_GGX_SmithCorrelated_Anisotropic(at, ab, dotTV, dotBV, dotTL, dotBL, dotNV, dotNL);

        return F * ( G * D );
    }
#endif

// GGX Distribution, Schlick Fresnel, GGX-Smith Visibility
vec3 BRDF_Specular_GGX(vec3 incidentDirection, SurfaceData surfaceData, vec3 normal, vec3 specularColor, float roughness ) {

	float alpha = pow2( roughness ); // UE4's roughness

	vec3 halfDir = normalize( incidentDirection + surfaceData.viewDir );

	float dotNL = saturate( dot( normal, incidentDirection ) );
	float dotNV = saturate( dot( normal, surfaceData.viewDir ) );
	float dotNH = saturate( dot( normal, halfDir ) );
	float dotLH = saturate( dot( incidentDirection, halfDir ) );

    #ifdef MATERIAL_ENABLE_ANISOTROPY
        return anisotropicLobe(halfDir, incidentDirection, surfaceData, specularColor, alpha, dotNV, dotNL, dotNH, dotLH);
    #else
        return isotropicLobe(specularColor, alpha, dotNV, dotNL, dotNH, dotLH);
    #endif

}

vec3 BRDF_Diffuse_Lambert(vec3 diffuseColor) {
	return RECIPROCAL_PI * diffuseColor;
}


#endif

void diffuseLobe(SurfaceData surfaceData, vec3 irradiance, float attenuation, inout vec3 Fd){
    Fd += attenuation * irradiance * BRDF_Diffuse_Lambert( surfaceData.diffuseColor );
}

void specularLobe(SurfaceData surfaceData, vec3 incidentDirection, vec3 irradiance, float attenuation, inout vec3 Fs){
    Fs += attenuation * irradiance * BRDF_Specular_GGX( incidentDirection, surfaceData, surfaceData.normal, surfaceData.specularColor, surfaceData.roughness);
}

float clearCoatLobe(vec3 incidentDirection, vec3 color, SurfaceData surfaceData, inout vec3 Fs){
    float attenuation = 1.0;

    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        float clearCoatDotNL = saturate( dot( surfaceData.clearCoatNormal, incidentDirection ) );
        vec3 clearCoatIrradiance = clearCoatDotNL * color;

        Fs += surfaceData.clearCoat * clearCoatIrradiance * BRDF_Specular_GGX( incidentDirection, surfaceData, surfaceData.clearCoatNormal, vec3( 0.04 ), surfaceData.clearCoatRoughness );
        attenuation -= surfaceData.clearCoat * F_Schlick(0.04, surfaceData.clearCoatDotNV);
    #endif

    return attenuation;
}


vec3 getDirectRadiance(vec3 incidentDirection, vec3 color, SurfaceData surfaceData) {

    vec3 Fd = vec3(0);
    vec3 Fs = vec3(0);
    float dotNL = saturate( dot( surfaceData.normal, incidentDirection ) );
    vec3 irradiance = dotNL * color * PI;

    // ClearCoat Lobe
    float attenuation = clearCoatLobe(incidentDirection, color, surfaceData, Fs);
    // Diffuse Lobe
    diffuseLobe(surfaceData, irradiance, attenuation, Fd);
    // Specular Lobe
    specularLobe(surfaceData, incidentDirection, irradiance, attenuation, Fs);

    return Fd + Fs;

}

#ifdef SCENE_DIRECT_LIGHT_COUNT

    void addDirectionalDirectLightRadiance(DirectLight directionalLight, SurfaceData surfaceData, inout vec3 color) {
        vec3 color2 = directionalLight.color;
        vec3 direction = -directionalLight.direction;

		color += getDirectRadiance( direction, color2, surfaceData );

    }

#endif

#ifdef SCENE_POINT_LIGHT_COUNT

	void addPointDirectLightRadiance(PointLight pointLight, SurfaceData surfaceData, inout vec3 color) {

		vec3 lVector = pointLight.position - surfaceData.position;
		vec3 direction = normalize( lVector );
		float lightDistance = length( lVector );

		vec3 color2 = pointLight.color;
		color2 *= clamp(1.0 - pow(lightDistance/pointLight.distance, 4.0), 0.0, 1.0);

		color += getDirectRadiance( direction, color2, surfaceData );

	}

#endif

#ifdef SCENE_SPOT_LIGHT_COUNT

	void addSpotDirectLightRadiance(SpotLight spotLight, SurfaceData surfaceData, inout vec3 color) {

		vec3 lVector = spotLight.position - surfaceData.position;
		vec3 direction = normalize( lVector );
		float lightDistance = length( lVector );
		float angleCos = dot( direction, -spotLight.direction );

		float spotEffect = smoothstep( spotLight.penumbraCos, spotLight.angleCos, angleCos );
		float decayEffect = clamp(1.0 - pow(lightDistance/spotLight.distance, 4.0), 0.0, 1.0);

		vec3 color2 = spotLight.color;
		color2 *= spotEffect * decayEffect;

		color += getDirectRadiance( direction, color2, surfaceData );

	}


#endif

void evaluateDirectRadiance(Temp_Varyings v, SurfaceData surfaceData, inout vec3 color){
    float shadowAttenuation = 1.0;

    #ifdef SCENE_DIRECT_LIGHT_COUNT
        shadowAttenuation = 1.0;
        #ifdef SCENE_IS_CALCULATE_SHADOWS
            shadowAttenuation *= sampleShadowMap(v);
            // int sunIndex = int(scene_ShadowInfo.z);
        #endif

        DirectLight directionalLight222;
        for ( int i = 0; i < SCENE_DIRECT_LIGHT_COUNT; i ++ ) {
            // warning: use `continue` syntax may trigger flickering bug in safri 16.1.
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_DirectLightCullingMask[i])){
                directionalLight.color = scene_DirectLightColor[i];
                #ifdef SCENE_IS_CALCULATE_SHADOWS
                    if (i == 0) { // Sun light index is always 0
                        directionalLight.color *= shadowAttenuation;
                    }
                #endif
                directionalLight.direction = scene_DirectLightDirection[i];
                addDirectionalDirectLightRadiance( directionalLight, surfaceData, color );
            }
        }

    #endif

    #ifdef SCENE_POINT_LIGHT_COUNT

        PointLight pointLight;

        for ( int i = 0; i < SCENE_POINT_LIGHT_COUNT; i ++ ) {
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_PointLightCullingMask[i])){
                pointLight.color = scene_PointLightColor[i];
                pointLight.position = scene_PointLightPosition[i];
                pointLight.distance = scene_PointLightDistance[i];

                addPointDirectLightRadiance( pointLight, surfaceData, color );
            } 
        }

    #endif

    #ifdef SCENE_SPOT_LIGHT_COUNT

        SpotLight spotLight;

        for ( int i = 0; i < SCENE_SPOT_LIGHT_COUNT; i ++ ) {
            if(!isRendererCulledByLight(renderer_Layer.xy, scene_SpotLightCullingMask[i])){
                spotLight.color = scene_SpotLightColor[i];
                spotLight.position = scene_SpotLightPosition[i];
                spotLight.direction = scene_SpotLightDirection[i];
                spotLight.distance = scene_SpotLightDistance[i];
                spotLight.angleCos = scene_SpotLightAngleCos[i];
                spotLight.penumbraCos = scene_SpotLightPenumbraCos[i];

                addSpotDirectLightRadiance( spotLight, surfaceData, color );
            } 
        }

    #endif
}


#endif

// #ifndef LIGHT_INDIRECT_PBR_INCLUDED
// #define LIGHT_INDIRECT_PBR_INCLUDED 1

// ------------------------Diffuse------------------------

// sh need be pre-scaled in CPU.
vec3 getLightProbeIrradiance(vec3 sh[9], vec3 normal){
      normal.x = -normal.x;
      vec3 result = sh[0] +

            sh[1] * (normal.y) +
            sh[2] * (normal.z) +
            sh[3] * (normal.x) +

            sh[4] * (normal.y * normal.x) +
            sh[5] * (normal.y * normal.z) +
            sh[6] * (3.0 * normal.z * normal.z - 1.0) +
            sh[7] * (normal.z * normal.x) +
            sh[8] * (normal.x * normal.x - normal.y * normal.y);
    
    return max(result, vec3(0.0));

}

// ------------------------Specular------------------------

// ref: https://www.unrealengine.com/blog/physically-based-shading-on-mobile - environmentBRDF for GGX on mobile
vec3 envBRDFApprox(vec3 specularColor, float roughness, float dotNV ) {

    const vec4 c0 = vec4( - 1, - 0.0275, - 0.572, 0.022 );

    const vec4 c1 = vec4( 1, 0.0425, 1.04, - 0.04 );

    vec4 r = roughness * c0 + c1;

    float a004 = min( r.x * r.x, exp2( - 9.28 * dotNV ) ) * r.x + r.y;

    vec2 AB = vec2( -1.04, 1.04 ) * a004 + r.zw;

    return specularColor * AB.x + AB.y;

}


float getSpecularMIPLevel(float roughness, int maxMIPLevel ) {
    return roughness * float(maxMIPLevel);
}

vec3 getReflectedVector(SurfaceData surfaceData, vec3 n) {
    #ifdef MATERIAL_ENABLE_ANISOTROPY
        vec3 r = reflect(-surfaceData.viewDir, surfaceData.anisotropicN);
    #else
        vec3 r = reflect(-surfaceData.viewDir, n);
    #endif

    return r;
}

vec3 getLightProbeRadiance(SurfaceData surfaceData, vec3 normal, float roughness) {

    #ifndef SCENE_USE_SPECULAR_ENV
        return vec3(0);
    #else
        vec3 reflectVec = getReflectedVector(surfaceData, normal);
        reflectVec.x = -reflectVec.x; // TextureCube is left-hand,so x need inverse
        
        float specularMIPLevel = getSpecularMIPLevel(roughness, int(scene_EnvMapLight.mipMapLevel) );

        #ifdef HAS_TEX_LOD
            vec4 envMapColor = textureCubeLodEXT( scene_EnvSpecularSampler, reflectVec, specularMIPLevel );
        #else
            vec4 envMapColor = textureCube( scene_EnvSpecularSampler, reflectVec, specularMIPLevel );
        #endif

        #ifdef SCENE_IS_DECODE_ENV_RGBM
            envMapColor.rgb = (RGBMToLinear(envMapColor, 5.0)).rgb;
            #ifdef ENGINE_IS_COLORSPACE_GAMMA
                envMapColor = linearToGamma(envMapColor);
            #endif
        #else
             #ifndef ENGINE_IS_COLORSPACE_GAMMA
                envMapColor = gammaToLinear(envMapColor);
            #endif
        #endif
        
        return envMapColor.rgb * scene_EnvMapLight.specularIntensity;

    #endif

}


void evaluateDiffuseIBL(SurfaceData surfaceData, float diffuseAO, inout vec3 Fd){
    #ifdef SCENE_USE_SH
        vec3 irradiance = getLightProbeIrradiance(scene_EnvSH, surfaceData.normal);
        #ifdef ENGINE_IS_COLORSPACE_GAMMA
            irradiance = (linearToGamma(vec4(irradiance, 1.0))).rgb;
        #endif
        irradiance *= scene_EnvMapLight.diffuseIntensity;
    #else
       vec3 irradiance = scene_EnvMapLight.diffuse * scene_EnvMapLight.diffuseIntensity;
       irradiance *= PI;
    #endif

    Fd += diffuseAO * irradiance * BRDF_Diffuse_Lambert( surfaceData.diffuseColor );
}

float evaluateClearCoatIBL(SurfaceData surfaceData, float specularAO, inout vec3 Fs){
    float radianceAttenuation = 1.0;

    #ifdef MATERIAL_ENABLE_CLEAR_COAT
        vec3 clearCoatRadiance = getLightProbeRadiance( surfaceData, surfaceData.clearCoatNormal, surfaceData.clearCoatRoughness);
        Fs += specularAO * clearCoatRadiance * surfaceData.clearCoat * envBRDFApprox(vec3( 0.04 ), surfaceData.clearCoatRoughness, surfaceData.clearCoatDotNV);
        radianceAttenuation -= surfaceData.clearCoat * F_Schlick(0.04, surfaceData.clearCoatDotNV);
    #endif

    return radianceAttenuation;
}

void evaluateSpecularIBL(SurfaceData surfaceData, float specularAO, float radianceAttenuation, inout vec3 Fs){
    vec3 radiance = getLightProbeRadiance(surfaceData, surfaceData.normal, surfaceData.roughness);
    Fs += specularAO * radianceAttenuation * radiance * envBRDFApprox(surfaceData.specularColor, surfaceData.roughness, surfaceData.dotNV );
}


void evaluateIBL(Temp_Varyings v, SurfaceData surfaceData, inout vec3 color){
    vec3 Fd = vec3(0);
    vec3 Fs = vec3(0);
    float diffuseAO = evaluateDiffuseAO(v);
    float specularAO = evaluateSpecularAO(diffuseAO, surfaceData.roughness, surfaceData.dotNV);

    // IBL diffuse
    evaluateDiffuseIBL(surfaceData, diffuseAO, Fd);

    // IBL ClearCoat
    float radianceAttenuation = evaluateClearCoatIBL(surfaceData, specularAO, Fs);

    // IBL specular
    evaluateSpecularIBL(surfaceData, specularAO, radianceAttenuation, Fs);

    color += Fd + Fs;
}


// #endif


vec4 evaluateSurface(Temp_Varyings v, SurfaceData surfaceData){
    vec3 color = vec3(0);

    // Direct Light
    evaluateDirectRadiance(v, surfaceData, color);
    // IBL
    evaluateIBL(v, surfaceData, color);
    // Emissive
    color += surfaceData.emissive;

    return vec4(color, surfaceData.opacity);
}


// #endif



        Varyings pbrVert(Attributes attr) {
          Varyings v;

          // @todo: delete
          Temp_Attributes temp_attributes;
          Temp_Varyings temp_varyings;
          
          

          // @todo: use initVertex(attr, v);
          initVertex();

          return v;
        }

        void pbrFrag(Varyings v) {
          SurfaceData surfaceData;

          const int myArray[3] = int[3](1, 2, 3);

          // @todo: delete
          Temp_Varyings temp_varyings;
          

          initSurfaceData(temp_varyings, surfaceData, gl_FrontFacing);

          vec4 color = evaluateSurface(temp_varyings, surfaceData);
          gl_FragColor = color;

          #if SCENE_FOG_MODE != 0
              gl_FragColor = fog(gl_FragColor, v.v_positionVS);
          #endif

          #ifndef ENGINE_IS_COLORSPACE_GAMMA
              gl_FragColor = linearToGamma(gl_FragColor);
          #endif

          gl_FragData[0] = vec4(1.,2.,3.,4.);
        }

        VertexShader = pbrVert;
        FragmentShader = pbrFrag;

      }

    }
  }