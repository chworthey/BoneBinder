#version 330 core
out vec3 color;

in vec3 colorV;

void main()
{
	if (colorV.r > 0.99)
		color = vec3(1.0, 0.0, 0.0);
	else
		color = vec3(0.0, 0.0, 1.0);
}