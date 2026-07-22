/**
 * @file DemoOverlay.cpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "common_def.hpp"
#include "DemoOverlay.hpp"
#include "MirageLog.hpp"
#include "MirageFont.hpp"

DemoOverlay::DemoOverlay()
           : BaseLayer("DemoOverlay")
           , m_Observer {}
           , m_UIImage {}
           , m_UIText {}
           , m_UIButton {}
{

}

DemoOverlay::DemoOverlay(std::string_view svDataDir)
           : DemoOverlay()
{
    m_strDataDir = svDataDir;

    Mirage::vec3<float> vCamFocusVec { 0, 0, 0 };
    Mirage::vec3<float> vCamTopVec   { 0, 1, 0 };
    Mirage::vec3<float> vCamTransPos { 0, 0, -1 };

    m_Observer.SetDepth(1);
    m_Observer.SetCullingMask(0x02);
    m_Observer.SetClearFlag(MRG_DEPTH_BUFFER_BIT);
    m_Observer.EnableOrthoView(-400.0f, 400.0f, 300.0f, -300.0f, 0.01f, 100.0f);
    m_Observer.SetPosition(vCamTransPos);
    m_Observer.SetView(vCamFocusVec, vCamTopVec);

    CreateUIText();
    CreateUIImage();
    CreateUIButton();
}

void DemoOverlay::OnAttach()
{

}

void DemoOverlay::OnDetach()
{

}

void DemoOverlay::OnUpdate()
{
    auto fnRender = [&]() { 
        m_Observer.ClearView();
        m_UIImage.Refresh();
        m_UIText.Refresh();
        m_UIButton.Refresh();
    };
    fnRender();
}

void DemoOverlay::OnEvent(Mirage::BaseEvent& rEvent)
{

}

void DemoOverlay::CreateUIText()
{
    unsigned char uLayer        { 0x2 };
    std::string strFontPath     { "font/OldEnglish/OLDENGL.TTF" };
    std::string strText         { "UI Text" };
    // TODO: remove the hard code
    float fViewWidth            { 800 };
    float fViewHeight           { 600 };
    float x                     { 0 };
    float y                     { 0 };
    Mirage::vec3<float> vTxtPos { 0, 0, 0 };
    Mirage::vec4<float> vTxtColor { 255, 215, 0, 1 };   // RGBA

    m_UIText.SetFontSize(60);
    // m_UIText.Configure(uLayer, strFontPath, strText);
    m_UIText.Configure(uLayer, strFontPath, strText, Mirage::TextAlign::left);

    x       = m_UIText.GetPitch() / 2;
    y       = fViewHeight / 2.0f;
    vTxtPos = { x, y, 0 };
    m_UIText.SetPosition(vTxtPos, true);
    m_UIText.SetColor(vTxtColor);
}

void DemoOverlay::CreateUIImage()
{
    int                 nHeight     { 100 };
    int                 nWidth      { 100 };
    std::string         strMaterial { "material/flower.mat" };
    unsigned char       uLayer      { 0x2 };
    // // TODO: remove the hard code
    float               fViewWidth  { 800 };
    float               fViewHeight { 600 };
    float               x           { fViewWidth - nWidth / 2 };
    float               y           { fViewHeight / 2 };
    Mirage::vec3<float> vScale      { 1.0 , 1.0, 1.0 };
    Mirage::vec3<float> vImgPos     { x, y, 0.0f };

    m_UIImage.Configure(nWidth, nHeight, uLayer, strMaterial);
    // m_UIImage.Configure(nWidth, nHeight, uLayer);
    m_UIImage.SetScale(vScale);
    m_UIImage.SetPosition(vImgPos, true);
    m_UIImage.AddMask("material/circle_mask.mat");
}

void DemoOverlay::CreateUIButton()
{
    int                 nWidth      { 40 };
    int                 nHeight     { 30 };
    unsigned char       uLayer      { 0x2 };
    // // TODO: remove the hard code
    float               fViewWidth  { 800 };
    float               fViewHeight { 600 };
    // Mirage::vec4<float> vTxtColor   { 255, 255, 255, 1 };   // RGBA
    float               x           { fViewWidth - nWidth / 2 };
    float               y           { fViewHeight / 2 - 100 };
    Mirage::vec3<float> vScale      { 1.0 , 1.0, 1.0 };
    Mirage::vec3<float> vButtonPos  { x, y, 0.0f };

    m_UIButton.Configure(nWidth, nHeight, uLayer);
    m_UIButton.SetScale(vScale);
    m_UIButton.SetPosition(vButtonPos, true);
    // m_UIButton.SetTextColor(vTxtColor);
    m_UIButton.SetClickCallback([&]() {
        bool bEnableMask = m_UIImage.IsMaskEnabled();
        m_UIImage.SetMaskStatus(!bEnableMask);
    });
}