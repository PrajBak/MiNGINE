#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 texCord;

out vec3 ourColor;
out vec2 ourTex;

void main()
{
	gl_Position = vec4(aPos, 1.0f);
	ourColor = aColor;
	ourTex = vec2(texCord.x, texCord.y);
}