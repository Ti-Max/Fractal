#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
class FPS
{
	int fpsNow = 0;
	int totalFps = 0;
	int totalFpsInt = 0;
	float lastTime;
public:
	int average;
	int min = 0;
	int max = 0;
	FPS();
	int fps = 0;


	void count();
	void print();
	void raport();
	//int min();
	//int max();
	//int averge();
};

