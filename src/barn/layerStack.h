#pragma once

#include "layer.h"
#include <vector>

naemspace barn
{
    class layerStack
    {
        public:
            layerStack();
            ~layerStack(); 

            void pushLayer(layer* layer);
            void pushOverLay(layer* overlay);
            void popLayer(layer& layer);
            void popOverlay(layer* overlay);

            std::vector<layer*>::iterator begin() {return m_layers.begin;}
            std::vector<layer*>::iterator end() {return m_layers.end;}
        private:
            std::vector<layer*> m_layer;
            std::vector<layer*>::iterator m_layerInsert;
    }
}