#include "FPS.h"
FPS::FPS() {
    lastTime = glfwGetTime();
}

void FPS::count()
{
    float currentTime = glfwGetTime();
    if (currentTime - lastTime > 1.0)
    {
        totalFps += fpsNow;
        totalFpsInt += 1;
        if (min == 0)
        {
            min = fpsNow;
        }
        if (fpsNow > max)
        {
            max = fpsNow;
        }
        else if (fpsNow < min) {
            min = fpsNow;
        }
        average = totalFps / totalFpsInt;
        fps = fpsNow;
        fpsNow = 0;
        lastTime += 1.0;
        //print();
    }
    fpsNow++;
}
void FPS::print() {
    std::cout << "\r" << fps;
}
void FPS::raport() {
    std::cout <<std::endl<< "min FPS:" << min << std::endl;
    std::cout << "max FPS:" << max << std::endl;
    std::cout << "average FPS:" << average << std::endl;
}