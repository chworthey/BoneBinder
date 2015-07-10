#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texcoord;
out vec2 Texcoord;
out vec4 spriteColor;

uniform mat4 MVP;
uniform vec4 SpriteColor;

void main(){
    Texcoord = texcoord;
	spriteColor = SpriteColor;

    // Output position of the vertex, in clip space : MVP * position
    vec4 v = vec4(vertexPosition_modelspace,1);
    gl_Position = MVP * v;
}
