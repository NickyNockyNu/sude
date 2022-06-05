#version 330 core

in  vec2 pos;
out vec4 colour;

uniform sampler2D buffer;

void main() 
{
  colour = texture(buffer, pos);
 }

