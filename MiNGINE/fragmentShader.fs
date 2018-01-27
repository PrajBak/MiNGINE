#version 330 core

out vec4 FragColor;
in vec3 ourColor;
in vec2 ourTex;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	//FragColor = texture(texture1, ourTex);
	FragColor = mix(texture(texture1, ourTex), texture(texture2, ourTex), 0.5);
	//FragColor = vec4(ourColor, 1.0f);		
}