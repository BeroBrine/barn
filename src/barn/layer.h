#pragma once
#include "Events/Events.h"

namespace barn
{
    class layer
    {
        public:

            layer(const std::string& name = "layer");
            virtual ~layer() {};

            virtual void onAttach() {}
            virtual void onDetach() {}
            virtual void onUpdate() {}

            virtual void onEvent(Event& event) {} 

            inline const std::string GetName() const { return m_debugName;}

        protected:
            std::string m_debugName;
    };

}