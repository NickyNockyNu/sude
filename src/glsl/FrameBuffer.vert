#version 330 core

layout (location = 0) in vec2 vec;
out vec2 pos;

void main()
{
  pos = (v + 1) / 2;
  gl_Position = vec4(v, 0, 1);
}
