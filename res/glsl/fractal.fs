#version 460 core


in  vec2 pos;

out vec4 color;

uniform double zoom;
uniform double direction;
uniform int iterations;

void main (){
	double newX = pos.x * zoom + direction;
	double newY = pos.y * zoom;
	
	double x = newX;
	double y = newY;
	double xTemp, yTemp;

	int iterator = 0; //счетчик
	while (iterator < iterations && x*x + y*y < 4)
	{
		xTemp = (x * x - y * y + newX);  
		yTemp = (2 * x * y + newY);
		x = xTemp;
		y = yTemp;
		iterator++;
	}
	if (iterator == iterations)
		color = vec4(0.0, 0.0, 0.0,1.0);
	else{
		if(iterator <=20){
			color = vec4(0.0, 0.0, iterator*0.05,1.0);
		}else{
		color = vec4(1.0, iterator*0.05 -1, 1.0 ,1.0);
		}
	}


}