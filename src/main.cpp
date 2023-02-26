#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//#include <GLFW/glfw3.h>
#include "GLFW/glfw3.h"


int main(int argc, const char** argv){
    std::cout << "hello" << std::endl;

    GLFWwindow* window;

    if (!glfwInit()) {
        printf("Couldn't init GLFW\n");
        return 1;
    }
    
    window = glfwCreateWindow(800, 480, "Hello World", NULL, NULL);
    if (!window) {
        printf("Couldn't open window\n");
        return 1;
    }

    unsigned char* data = new unsigned char [100 * 100 * 3];

    for(int y=25; y<75; y++){
        for(int x=25; x<75; x++){
            data[y*100*3 + x*3  ] = 0x00;
            data[y*100*3 + x*3+1] = 0x00;
            data[y*100*3 + x*3+2] = 0xff;
        }
    }

     glfwMakeContextCurrent(window);

     while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
        glfwSwapBuffers(window);

        glfwWaitEvents();
     }
     
    return 0;
}