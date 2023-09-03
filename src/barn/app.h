#pragma once

#include "window.h"
#include "../barnpch.h"
extern barn::app* barn::CreateApplication();

namespace barn
{

    class app 
    {
        public:

            void run();
    };
    app* CreateApplication();
}
