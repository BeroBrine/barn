#pragma once
#include <vector>

#include "layer.h"

namespace barn
{
    class layerStack
    {
        public:
            layerStack();
            virtual ~layerStack(); 

            void pushLayer(layer* layer);
            void pushOverLay(layer* overlay);
            void popLayer(layer* layer);
            void popOverlay(layer* overlay);

            std::vector<layer*>::iterator begin() {return m_layer.begin();}
            std::vector<layer*>::iterator end() {return m_layer.end();}
        private:
            std::vector<layer*> m_layer;
            std::vector<layer*>::iterator m_layerInsert;
    };
}