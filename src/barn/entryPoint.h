#pragma once
#include "Log.h"
extern barn::app* barn::CreateApplication();

int main(int argc , char** argv)
{
    barn::Log::init();
    _CORE_WARN("initialized engine");
    _CLIENT_INFO("hello");

    barn::app* app1 = barn::CreateApplication();
    app1->run();
    delete app1;
}