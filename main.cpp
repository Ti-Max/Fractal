#include <iostream>
#include "src/Window/Window.h"

#include "src/GLFW/GLFW.h"

int main() {
	GLFW glfw;
	Window window("Fractal", 970, 970);
	window.loop();
	return 0;
}