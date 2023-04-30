#version 460 core
layout(location = 0) in vec3 aPos;

out vec2 pos;
out int iterations;



void main(){
	gl_Position = vec4(aPos, 1.0f);
	pos = aPos.xy;
	//-1.50177 смещение //0.0002
}