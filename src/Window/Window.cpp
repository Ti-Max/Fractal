#include "Window.h"
#include "Shader/Shader.h"
#include "VAO/VAO.h"
#include<iostream>
#include "FPS/FPS.h"
//#include "Text/mText.h"
bool plus = false;
bool minus = false;
double zoom = 1.5;
int iter = 0;
double direc = -0.5;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

Window::Window(const std::string& title, int width, int height)
{
	glfwWindowHint(GLFW_SAMPLES, 4);

	this->height = height;
	this->width = width;
	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowPos(window, 1900 - width, 40);



	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to connect GLEW" << std::endl;
	}
	glViewport(0, 0, width, height);
}

Window::~Window()
{
	glfwDestroyWindow(window);
}

void Window::loop()
{
	
	//mText text(width, height);
	//Shader textShader("text");


	Shader fracS("fractal");
	fracS.use();
	fracS.setDouble("zoom", 0.1);
	fracS.setDouble("direction", -1.f);
	fracS.setInt("iterations", 600);


	GL::VAO fractal;
	fractal.addBufferData({
		{-1.0f,  1.0f,  1.0f},
		{-1.0f, -1.0f,  1.0f},
		{ 1.0f, -1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f}
		});
	fractal.addEBO({
		0, 1, 2,
		2, 3, 0
		});

	FPS fps;

	iter = 600;
	float zoomLevel = 1.0f;
	float direction = -0.5f;
	while (!glfwWindowShouldClose(window))
	{
		fps.count();
		glfwPollEvents();
		glClearColor(0.1, 0.1, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		fracS.use();
		zoomLevel *= 0.99;
		direction = -1.55;
		iter += 100;
		fracS.setDouble("zoom", zoomLevel);
		fracS.setInt("iterations", iter);
		fracS.setDouble("direction", direction);
		fractal.draw();


		glfwSwapBuffers(window);
	}
	fps.raport();
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}