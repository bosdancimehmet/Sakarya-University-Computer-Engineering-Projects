#include "glwindow.hpp"
#include<imgui/imgui.h>
#include<imgui/backends/imgui_impl_opengl3.h>
#include<imgui/backends/imgui_impl_glfw.h>
namespace graf
{
    void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        void * ptr = glfwGetWindowUserPointer(window);
        GLWindow* glWindow = (GLWindow*)ptr;
        glWindow->m_keyboardFunction(key,action);

    }
    void GLWindow::create(int width,int height)
    {
        if(!glfwInit())
        {
            glfwTerminate();
            exit(EXIT_FAILURE);

        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwSetErrorCallback(error_callback);

        m_window= glfwCreateWindow(width, height, "My Title", NULL, NULL);
        if (!m_window)
        {
            // Window or OpenGL context creation failed
        }
    

        glfwMakeContextCurrent(m_window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }  
        glfwSetKeyCallback(m_window,key_callback);
        glfwSetWindowUserPointer(m_window,this);
        glEnable(GL_DEPTH_TEST);
        
        initilizeImgui();
    }
    void GLWindow::begin()
    {
        while (!glfwWindowShouldClose(m_window))
        {
            
            
            glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);




            m_renderFunction();


            renderImgui();


            glfwSwapBuffers(m_window);
            glfwPollEvents();
        } 

        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    void GLWindow::setRenderFunction(RenderFunction function)
    {
        m_renderFunction    =   function;
    }
    void GLWindow::setGuiFunction(RenderFunction function)
    {
        m_guiFunction = function;
    }
    void GLWindow::setKeyboardFunction(KeyboardFunction function)
    {
        m_keyboardFunction= function;
    }
    void GLWindow::renderImgui()
    {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            m_guiFunction();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            ImGui::EndFrame();
    }
    void GLWindow::initilizeImgui()
    {
        ImGui::CreateContext();

        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init("#version 330");   
    }
    GLFWwindow *GLWindow::getWindow()
    {
        return m_window;
    }
}