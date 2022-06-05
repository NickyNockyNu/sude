#version 330 core
in vec2 t;out vec4 c;uniform sampler2D b;void main(){c=texture(b,t);}

