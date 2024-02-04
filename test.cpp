#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Define a callback that is called every time the window is resized by the user.
// This ensures OpenGL is always working with the correct window size.
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

// Process user input so we can close the window with a keypress.
void processInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}

int main(){
    glfwInit();

    // Set OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Restrict GLFW functionality to OpenGL core profile.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Make a GLFW Window
    int window_width = 800;
    int window_height = 600;
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "window title", NULL, NULL);
    if(window == nullptr){
        std::cout << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    // Communicate the size of the window to OpenGL.
    // This is needed to define a mapping from 2D coordinates in the range [-1, 1] used by OpenGL to pixel coordinates.
    glViewport(0, 0, window_width, window_height);

    // Attach the callback to window resizing.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Now create a render loop so the program does not instantly close itself.
    // Render loop.
    while(!glfwWindowShouldClose(window)){
        
        // Process user inputs.
        processInput(window);

        // Do interesting rendering here.
        // Set the OpenGL clear color state.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // Clear the color of the buffer. Here we use the state set above.
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the buffers, and check/call events.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up all of GLFW's resources.
    glfwTerminate();

    return 0;
}
