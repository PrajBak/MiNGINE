#version 330 core

out vec4 FragColor;
//in vec3 ourColor;
in vec2 ourTex;

uniform sampler2D texture1;

void main()
{
	FragColor = texture(texture1, ourTex);
	//FragColor = mix(texture(texture1, ourTex), vec4(ourColor, 1.0f), 0.4);
	//FragColor = vec4(ourColor, 1.0f);		
}