#include <GL/glew.h> /* order of including matters*/
#include <GLFW/glfw3.h>
#include <iostream>
//#include <windows.h> {READ NOTE AT wWinMain}

void GSWarn() {
    std::cout << std::endl;
}
template<typename FirstGsWarn, typename ... RestGsWarn>
void GSWarn(FirstGsWarn arg, const RestGsWarn&... rest) {
    std::cout << arg << " ";
    GSWarn(rest...);
}


int __cdecl main(void)
{
    GLFWwindow* window;

    /* Initialize the library */

    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        GSWarn("[UI Init] glewInit() failed with status", glewInit());

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

/* removes console window [NOTE: change SUBSYSTEM in linker->system
to not set while i figure this out 
#ifdef WIN32
int WINAPI wWinMain(
    __in HINSTANCE hInstance,
    __in_opt HINSTANCE hPrevInstance,
    __in LPWSTR lpCmdLine,
    __in int nShowCmd
) {
    main();
}
#endif
*/
