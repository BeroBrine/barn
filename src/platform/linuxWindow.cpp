#include "linuxWindow.h"
#include "Log.h"
#include <iostream>
namespace barn
{
    static bool s_GLFWinitialized = false;


    linuxWindow::linuxWindow(const windowProp& props)
    {
        init(props);
    }

    linuxWindow::~linuxWindow()
    {
        std::cout << "destructor" << std::endl;
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
            s_GLFWinitialized = true;
        }

        m_window = glfwCreateWindow((int)props.width , (int)props.height , m_data.title.c_str() , nullptr , nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window , &m_data);
        SetVSync(true);
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