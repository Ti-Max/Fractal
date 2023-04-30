#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


class Window
{
	GLFWwindow* window;
public:
	Window(const std::string & title, int width, int height);
	~Window();
	void loop();
	int width, height;
private:
	//float zoom = 1.5;
	//float direc = 0/*;*/
	int iterationsM = 600;

};

