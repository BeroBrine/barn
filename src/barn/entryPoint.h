#pragma once

extern barn::app* barn::CreateApplication();

int main(int argc , char** argv)
{
    barn::app* app1 = barn::CreateApplication();
    app1->run();
    delete app1;
}