#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texcoord;
layout(location = 3) in vec3 normal;

uniform mat4 MVP;
uniform vec4 DiffuseColor;
uniform mat4 WorldOnly;
uniform mat4 WorldInverseTranspose;
uniform vec3 EyePosition;
uniform int SpecularPower;
uniform vec3 EmissiveColor;
uniform vec3 SpecularColor;

uniform vec3 DirLight0Direction;
uniform vec3 DirLight0DiffuseColor;
uniform vec3 DirLight0SpecularColor;
uniform vec3 DirLight1Direction;
uniform vec3 DirLight1DiffuseColor;
uniform vec3 DirLight1SpecularColor;
uniform vec3 DirLight2Direction;
uniform vec3 DirLight2DiffuseColor;
uniform vec3 DirLight2SpecularColor;

out vec4 diffuseO;
out vec2 texcoordO;
out vec3 positionWSO;
out vec3 normalWSO;
 
void main()
{
	vec4 v = vec4(position,1);
	gl_Position = MVP * v;

	positionWSO = vec3(v * WorldOnly);
	normalWSO = normalize(vec3(vec4(normal, 0) * WorldInverseTranspose));	
	texcoordO = texcoord;
	diffuseO = vec4(color, DiffuseColor.a);
}
