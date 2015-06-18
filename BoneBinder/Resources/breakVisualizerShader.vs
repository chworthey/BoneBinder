#version 330 core
in vec3 vertexPosition_modelspace;
in vec3 vertexColor;

uniform mat4 MVP;

out vec3 colorV;
 
void main(){
 
    // Output position of the vertex, in clip space : MVP * position
    vec4 v = vec4(vertexPosition_modelspace + vertexColor * 0.00000001,1);
    gl_Position = MVP * v;
    colorV = vertexColor;
}
