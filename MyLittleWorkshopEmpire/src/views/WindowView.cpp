#include "WindowView.h"

WindowView::~WindowView()
{
    std::cout << "WindowView is destroyed!\n";
}

void WindowView::Run()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Failed to init glfw!\n";
        return;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 680, "My Workshop", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Failed to create the window!\n";
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
}
