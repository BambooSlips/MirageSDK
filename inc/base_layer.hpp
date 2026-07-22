/**
 * @file BaseLayer.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "base_event.hpp"
#include <string_view>
#include <string>

namespace Mirage {
    class BaseLayer {
        public:
            BaseLayer(std::string_view svName = "BaseLayer")
                : m_strName { svName }
            {
            }

            virtual ~BaseLayer() = default;

            virtual void OnAttach() = 0;

            virtual void OnDetach() = 0;

            virtual void OnUpdate() = 0;

            virtual void OnEvent(Mirage::BaseEvent& refEvent) = 0;
        
        protected:
            std::string m_strName;
    };
}