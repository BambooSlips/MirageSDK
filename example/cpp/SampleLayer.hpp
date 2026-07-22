/**
 * @file SampleLayer.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "base_layer.hpp"
#include "base_event.hpp"
#include "MirageObserver.hpp"
#include "MirageInput.hpp"
#include "MirageText.hpp"
#include "MirageImage.hpp"
#include "MirageModel.hpp"
#include <string_view>
#include <memory>
#include <string>

class SampleLayer: public Mirage::BaseLayer
{
    public:
        SampleLayer();
        SampleLayer(std::string_view svDataDir);

        virtual ~SampleLayer() override;

        void OnAttach() override;

        void OnDetach() override;

        void OnUpdate() override;

        void OnEvent(Mirage::BaseEvent& rEvent) override;

    private:
        void CreateModel();

        void CreateAnimatedModel();

        void CreateText();

        void CreateImg();
    
    private:
        Mirage::InputPoint                    m_cursorPos;
        Mirage::Model                         m_Model;
        Mirage::Model                         m_AnimatedModel;
        Mirage::Observer                      m_Observer;
        Mirage::Text                          m_TitleText;
        Mirage::Image                         m_ImgFlower;
        std::string                           m_strDataDir;
};