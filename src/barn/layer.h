#pragma once

#include "barn/Events/Events.h"

namespace hazel
{
    class layer
    {
        layer(const std::string name = "layer");
        virtual ~layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event& event) {} 

        inline const std::string GetName() const { return m_debugName;}

        protected:
            std::string m_deugName;
    }

}