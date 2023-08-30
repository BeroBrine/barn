#include <allHeaders.h>

class Sandbox : public barn::app
{
    public:
        Sandbox()
        {
            
        }
        ~Sandbox()
        {

        }
};


barn::app* barn::CreateApplication()
{
    return new Sandbox();
}

