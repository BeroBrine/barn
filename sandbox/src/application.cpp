#include "allHeaders.h"
#include "iostream"

namespace barn 
{
    class Sandbox : public app
    {
        public:
            Sandbox()
            {
                std::cout << "the engine has been constructed" << std::endl;
            }
            ~Sandbox()
            {
    
            }
    };
    
    
    app* CreateApplication()
    {
        return new Sandbox();
    }
    
}