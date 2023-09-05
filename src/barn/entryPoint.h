#pragma once
#include <memory>
#include "Log.h"
#include "window.h"
#include "barn/Events/ApplicationEvent.h"
namespace barn
{

    class app 
    {
        public:
            app();
            void run();
            void onEvent(Event&);

        private:
            std::unique_ptr<window> m_window;
            bool OnWindowClose(WindowCloseEvent& e);

            bool m_running = true;
    };

    app* CreateApplication();
}



int main(int argc , char** argv)
{
    barn::Log::init();
    _CORE_WARN("initialized engine");
    _CLIENT_INFO("hello");

    barn::app* app1 = barn::CreateApplication();
    app1->run();
    delete app1;
}
