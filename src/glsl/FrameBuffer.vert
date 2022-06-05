#version 330 core
layout(location=0) in vec2 v;out vec2 t;void main(){t=(v+1)/2;gl_Position=vec4(v,0,1);}
