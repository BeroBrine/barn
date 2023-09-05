#include "linuxWindow.h"
#include "Log.h"
#include "barn/Events/ApplicationEvent.h"
#include "barn/Events/KeyboardEvent.h"
#include "barn/Events/Events.h"
#include "barn/Events/MouseEvent.h"
#include <GLFW/glfw3.h>



namespace barn
{
    static bool s_GLFWinitialized = false;

    static void GLFWErrorCallBack(int error , const char* description)
    {
        _CORE_ERROR("GLFW ERROR ({0}): {1}" , error , description);
    }
    linuxWindow::linuxWindow(const windowProp& props)
    {
        init(props);
    }

    linuxWindow::~linuxWindow()
    {
        shutdown();
    }

    window* window::create(const windowProp& props)
    {
        
        return new linuxWindow(props);
    }
    
    void linuxWindow::init(const windowProp& props)
    {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        _CORE_INFO("creating window {0} ({1} , {2})" , props.title , props.width , props.height);
        if(!s_GLFWinitialized)
        {
            glfwInit();
            glfwSetErrorCallback(GLFWErrorCallBack);
            s_GLFWinitialized = true;
        }
        m_window = glfwCreateWindow((int)props.width , (int)props.height , m_data.title.c_str() , nullptr , nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window , &m_data);
        SetVSync(true);

        // glfw events
        glfwSetWindowSizeCallback(m_window , [](GLFWwindow* window , int width , int height)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            data.width = width;
            data.height = height;

            WindowResizeEvent event(width , height);
            data.EventCallBack(event);
        });

        glfwSetWindowCloseCallback(m_window , [](GLFWwindow* window)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;

            data.EventCallBack(event);

        });

        glfwSetKeyCallback(m_window , [](GLFWwindow* window , int key , int scancode , int action , int mods)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key , 0);
                    data.EventCallBack(event);
                    break;
                }   
                case GLFW_RELEASE:
                {
                    KeyReleased event(key);
                    data.EventCallBack(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key , 1);
                    data.EventCallBack(event);
                    break;
                }
                    

            }
        });

        glfwSetMouseButtonCallback(m_window , [](GLFWwindow* window , int button , int action , int mods)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            switch(action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressed event(button);
                    data.EventCallBack(event);

                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleased event(button);
                    data.EventCallBack(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_window , [](GLFWwindow* window , double x_offset , double y_offset)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)x_offset , (float)y_offset);
            data.EventCallBack(event);
        });

        glfwSetCursorPosCallback(m_window , [](GLFWwindow* window , double xPos , double yPos)
        {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xPos , (float)yPos);
            data.EventCallBack(event);

        });
    }
    void linuxWindow::shutdown()
    {
        glfwDestroyWindow(m_window);
    }
    void linuxWindow::onUpdate() const
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);

    }
    void linuxWindow::SetVSync(bool enabled)
    {
        if(enabled) glfwSwapInterval(1);
        else glfwSwapInterval(0);
        m_data.VSync = enabled;

    }
    bool linuxWindow::IsVSync() const
    {
        return m_data.VSync;
    }
}