/**
 * @file SampleLayer.cpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "SampleLayer.hpp"
#include "MirageLog.hpp"
#include "MirageFont.hpp"
#include "MirageAudioSource.hpp"
#include "MirageAudioBuffer.hpp"
#include "MirageAudioListener.hpp"
#include "MirageAudioUtils.hpp"
#include "MirageAnimation.hpp"
#include "MirageVertexBoneInfo.hpp"
#include <vector>
#include <cmath>
#include <limits>

using namespace Mirage;

SampleLayer::SampleLayer()
           : BaseLayer("SampleLayer")
           , m_cursorPos { 0 }
           , m_Model {}
           , m_AnimatedModel {}
           , m_Observer {}
           , m_TitleText {}
           , m_ImgFlower {}
{
    MRG_LOGD("IN");
    MRG_LOGD("OUT");
}

SampleLayer::~SampleLayer()
{
}

SampleLayer::SampleLayer(std::string_view svDataDir)
           : SampleLayer()
{
    MRG_LOGD("IN");
    m_strDataDir = svDataDir;

    float fRatio = 800 / 600.0f;
    Mirage::vec3<float> observerPos { 0, 0, -5 };
    Mirage::vec3<float> MainFocusVec { 0, 0, 0 };
    Mirage::vec3<float> MainTopVec { 0, 1, 0 };

    m_Observer.SetDepth(0);
    m_Observer.SetCullingMask(0x01);
    m_Observer.SetProjection(60.0f, fRatio, 1.0f, 1000.0f);
    m_Observer.SetPosition(observerPos);
    m_Observer.SetView(MainFocusVec, MainTopVec);   // must after position setting
    AudioListener::GetInstance().SetPosition(observerPos);
    AudioListener::GetInstance().SetFocusVector(MainFocusVec);
    AudioListener::GetInstance().SetTopVector(MainTopVec);

    // CreateModel();
    CreateAnimatedModel();
    CreateText();
    CreateImg();

    MRG_LOGD("OUT");
}

void SampleLayer::OnAttach()
{
    std::string strAnimation { "animation/ShibaInu.pb" };
    auto        upAnimation  { m_AnimatedModel.AddComponent<Animation>() };

    upAnimation->LoadClipFromFile(strAnimation, "ShibaInu");
    upAnimation->SetDuration("ShibaInu", 5000); // 5000 ms
    upAnimation->Play("ShibaInu");
}

void SampleLayer::OnDetach()
{

}

void SampleLayer::OnUpdate()
{
    static float fRotationAngle = 0.0f;
    InputPoint cursorPoint = { 0 };
    float fRatio = 800 / 600.0f;

    if (Mirage::IsMouseButtonPressed(Mirage::MouseButton::ButtonLeft) &&
        Mirage::IsKeyPressed(Mirage::KeyValue::LeftAlt))
    {
        GetCursorPoint(cursorPoint);
        float fDegree = m_cursorPos.x - cursorPoint.x;

        if (0 != fDegree)
        {
            vec3<float> rotAxis = { 0.0f, 1.0f, 0.0f };
            m_Observer.Rotate(rotAxis, fDegree);
            const auto& rPosition = m_Observer.GetPosition();
            MRG_LOGD("x change: rPosition = (%f, %f, %f)", rPosition.x, rPosition.y, rPosition.z);
        }
    }

    if (Mirage::IsMouseButtonPressed(Mirage::MouseButton::ButtonRight) &&
        Mirage::IsKeyPressed(Mirage::KeyValue::LeftAlt))
    {
        GetCursorPoint(cursorPoint);
        float fDegree = m_cursorPos.y - cursorPoint.y;

        if (0 != fDegree)
        {
            vec3<float> rotAxis = { 1.0f, 0.0f, 0.0f };
            static Mirage::vec3<float> vFocusVec { 0, 0, 0 };
            static Mirage::vec3<float> vTopVec { 0, 1, 0 };
            
            m_Observer.Rotate(rotAxis, fDegree);
            const auto& rPosition = m_Observer.GetPosition();

            Mirage::vec3 vector = { 
                vFocusVec.x - rPosition.x,
                vFocusVec.y - rPosition.y,
                vFocusVec.z - rPosition.z
            };

            // vTopVec.x = vTopVec.x;
            vTopVec.x = 0;
            vTopVec.y = vector.z;
            vTopVec.z = -vector.y; 
            MRG_LOGD("rPosition = (%f, %f, %f)", rPosition.x, rPosition.y, rPosition.z);

            m_Observer.SetView(vFocusVec, vTopVec);
        }
    }

    ScrollOffset scrollOffset;
    GetCursorPoint(m_cursorPos);
    GetSrollOffset(scrollOffset);

    float scale = (10 - scrollOffset.y) / 10.f;
    if (scale != 0)
    {
        vec3<float> position { 
            m_Observer.GetPosition().x * scale,
            m_Observer.GetPosition().y * scale,
            m_Observer.GetPosition().z * scale 
        };

        m_Observer.SetPosition(position);
    }
    
    auto fnRender = [&]() { 
        m_Observer.ClearView();
        // m_Model.Refresh();
        m_AnimatedModel.Refresh();
        m_TitleText.Refresh();
        m_ImgFlower.Refresh();
    };
    fnRender();
}

void SampleLayer::OnEvent(Mirage::BaseEvent& rEvent)
{

}

void SampleLayer::CreateModel()
{
    unsigned char uLayer        { 0x1 };
    Mirage::vec3<float> cubePos { 0, 0, 0 };
    std::string strMaterial     { "material/moon.mat" };
    std::string strMesh         { "model/Sphere.mesh" };

    m_Model.Configure(uLayer, strMaterial, strMesh);
    m_Model.SetPosition(cubePos);
    m_Model.SetCullFaceStatus(true);

    const unsigned int  uSize         { 800 };
    unsigned int        uFreq         { 8000 };
    unsigned int        uFormat       { MRG_AUDIO_FORMAT_MONO16 };
    bool                bLooping      { true };
    float               fMax          { std::numeric_limits<short>::max() / 4 };
    float               fRad          { 0 };
    Mirage::vec3<float> vVel          { 0, 0, 0 };
    auto                upAudioSource { m_Model.AddComponent<AudioSource>() };
    auto                upAudioData   { std::make_unique<short[]>(uSize) };
    std::string         strWarAudio   { "audio/war_bgm.wav" };
    auto                spAudioBuffer { AudioUtils::LoadAudioBuffer(strWarAudio) };

    upAudioSource->SetBuffer(*spAudioBuffer);
    upAudioSource->SetAudioPitch(1.0f);
    upAudioSource->SetAudioGain(1.0f);
    upAudioSource->SetPosition(cubePos);
    upAudioSource->SetVelocity(vVel);
    upAudioSource->SetLoopingStatus(true);

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::Left); }, [&]() {
        auto vPos = m_Model.GetPosition();
        vPos.x += 0.5f;
        m_Model.SetPosition(vPos);
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::Right); }, [&]() {
        auto vPos = m_Model.GetPosition();
        vPos.x -= 0.5f;
        m_Model.SetPosition(vPos);
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::Up); }, [&]() {
        auto vPos = m_Model.GetPosition();
        vPos.y += 0.5f;
        m_Model.SetPosition(vPos);
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::Down); }, [&]() {
        auto vPos = m_Model.GetPosition();
        vPos.y -= 0.5f;
        m_Model.SetPosition(vPos);
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::R); }, [&]() {
        const Mirage::vec3<float>& rRotation = m_Model.GetRotation();
        Mirage::vec3<float> rotVec { rRotation.x, rRotation.y + 1, rRotation.z };
        m_Model.SetRotation(rotVec);
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::P); }, [&]() {
        auto upAudioSource = m_Model.GetComponent<AudioSource>();
        if (true == upAudioSource->IsPlaying())
        {
            upAudioSource->PausePlaying();
        }
        else
        {
            upAudioSource->PlayAudio();
        }
    });

    m_Model.AddEvent([]() { return IsKeyPressed(KeyValue::S); }, [&]() {
        auto upAudioSource = m_Model.GetComponent<AudioSource>();
        upAudioSource->StopPlaying();
    });
}

void SampleLayer::CreateAnimatedModel()
{
    unsigned char uLayer         { 0x1 };
    Mirage::vec3<float> position { 0, -1, 0 };
    std::string strMaterial      { "material/ShibaInu.mat" };
    std::string strMesh          { "model/ShibaInu.mesh" };
    vec3<float> vModelRotation   { 0.f, 180.f, 0.f };
    vec3<float> vModelScale      { 0.02f, 0.02f, 0.02f };

    m_AnimatedModel.Configure(uLayer, strMaterial, strMesh, false);
    m_AnimatedModel.SetLayer(uLayer);
    m_AnimatedModel.SetPosition(position);
    m_AnimatedModel.SetScale(vModelScale);
    m_AnimatedModel.SetRotation(vModelRotation);
}

/*
*  The coordinate system:
*                    y+ 
*                    ^     z+ 
*                    |    / 
*                    |   /
*                    |  /
*                    | /
*  x+ <--------camera(0, 0)-----------
*                    |
*                    |
*                    |
*                    |
*                    |
*/
void SampleLayer::CreateText()
{
    unsigned char uLayer        { 0x1 };
    std::string strFontPath     { "font/OldEnglish/OLDENGL.TTF" };
    std::string strText         { "May it be an evening star shines down upon you." };
    vec3<float> vTextScale      { 0.005f, 0.005f, 0.0f };
    Mirage::vec3<float> vTxtPos { -3.5f, 2.0f, 0.0f };
    Mirage::vec4<float> vColors { 255.0f, 255.0f, 255.0f, 1.0f };   // RGBA

    m_TitleText.SetFontSize(72);
    m_TitleText.Configure(uLayer, strFontPath, strText, Mirage::TextAlign::left);
    m_TitleText.SetScale(vTextScale);
    m_TitleText.SetPosition(vTxtPos, false);
    m_TitleText.SetColor(vColors);
    m_TitleText.SetDepthStatus(true);
}

void SampleLayer::CreateImg()
{
    int                 nHeight     { 100 };
    int                 nWidth      { 100 };
    std::string         strMaterial { "material/flower.mat" };
    unsigned char       uLayer      { 0x1 };
    Mirage::vec3<float> vScale      { 0.01 , 0.01, 0.0 };
    Mirage::vec3<float> vImgPos     { -0.5f, -2.5, 0.0f };

    m_ImgFlower.Configure(nWidth, nHeight, uLayer, strMaterial);
    m_ImgFlower.AddMask("material/circle_mask.mat");
    m_ImgFlower.SetScale(vScale);
    m_ImgFlower.SetPosition(vImgPos);

    m_ImgFlower.AddEvent([]() { return IsKeyPressed(KeyValue::M); }, [&]() {
        m_ImgFlower.SetMaskStatus(!m_ImgFlower.IsMaskEnabled());
    });
}