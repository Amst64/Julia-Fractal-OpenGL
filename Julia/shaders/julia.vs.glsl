#version 330

layout(location = 0) in vec2 aVertexPosition;

out vec2 vFragPos;

void main()
{
    vFragPos  = aVertexPosition;
    gl_Position = vec4(aVertexPosition, 0, 1);
}