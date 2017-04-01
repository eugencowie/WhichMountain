#version 120

varying vec2 f_texCoord;

uniform sampler2D texture_diffuse0;

void main()
{
	gl_FragColor = texture2D(texture_diffuse0, f_texCoord);
}
