/**
 * @file DemoOverlay.hpp
 * @author BambooSlips (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "base_layer.hpp"
#include "MirageComponent.hpp"
#include "MirageTransform.hpp"
#include "MirageMeshFilter.hpp"
#include "MirageMeshRenderer.hpp"
#include "MirageObserver.hpp"
#include "MirageImage.hpp"
#include "MirageText.hpp"
#include "MirageButton.hpp"
#include <memory>

class DemoOverlay: public Mirage::BaseLayer
{
    public:
        DemoOverlay();
        DemoOverlay(std::string_view svDataDir);

        virtual ~DemoOverlay() = default;

        void OnAttach() override;

        void OnDetach() override;

        void OnUpdate() override;

        void OnEvent(Mirage::BaseEvent& rEvent) override;
    
    private:
        void CreateUIText();

        void CreateUIImage();

        void CreateUIButton();
    
    private:
        Mirage::Observer m_Observer;
        Mirage::Image    m_UIImage;
        Mirage::Text     m_UIText;
        Mirage::Button   m_UIButton;
        std::string      m_strDataDir;
};