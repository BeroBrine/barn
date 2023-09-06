#include "barnpch.h"
#include "layerStack.h"
#include "layer.h"


namespace barn
{
    layerStack::layerStack()
    {
        m_layerInsert = m_layer.begin();

    }

    layerStack::~layerStack()
    {
        for(layer* layers : m_layer)
            delete layers;
    }

    void layerStack::pushLayer(layer* layer)
    {
        m_layerInsert = m_layer.emplace(m_layerInsert , layer);

    }

    void layerStack::pushOverLay(layer* overlay)
    {
        m_layer.emplace_back(overlay);

    }

    void layerStack::popOverlay(layer* overlay)
    {
        auto it = std::find(m_layer.begin() , m_layer.end() , overlay);
        {
            if(it != m_layer.end())
            {
                m_layer.erase(it);
            }
        }
    }

    void layerStack::popLayer(layer* layer)
    {
        auto it = std::find(m_layer.begin() , m_layer.end() , layer);
        
        if( it != m_layer.end() )
        {
            m_layer.erase(it);
            m_layerInsert--;
        }
    }

}


