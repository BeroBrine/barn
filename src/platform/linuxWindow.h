#pragma once

#include "../barn/window.h"
#include "barnpch.h"


namespace barn
{
    class linuxWindow : public window
    {
        public:
            linuxWindow(const windowProp& props);
            virtual ~linuxWindow();
            void onUpdate() const override;

            inline unsigned int GetWidth() const override {return m_data.width;}
            inline unsigned int GetHeight() const override {return m_data.height;}

            inline void SetEventCallBack(const EventCallBackFn& callback) override {m_data.EventCallBack = callback;}
            void SetVSync(bool enabled) override;
            bool IsVSync() const override;

        private:
            virtual void init(const windowProp& props);
            virtual void shutdown();
        private:
            GLFWwindow* m_window = nullptr;

            struct windowData
            {
                std::string title;
                unsigned int width;
                unsigned int height;
                bool VSync;

                EventCallBackFn EventCallBack;
            };
            windowData m_data;
    };
}