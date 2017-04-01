#version 120

attribute vec3 v_position;
attribute vec2 v_texCoord;

varying vec2 f_texCoord;

uniform mat4 modelViewProjection;

void main()
{
	gl_Position = modelViewProjection * vec4(v_position, 1);

	f_texCoord = v_texCoord;
}
