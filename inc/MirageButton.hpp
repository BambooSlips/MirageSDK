/**
 * @file MirageButton.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-01-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "MirageModel.hpp"
#include "MirageImage.hpp"
#include "MirageText.hpp"
#include <memory>

namespace Mirage
{
    class MIRAGE_API Button: public Model {
        public:
            Button();
            virtual ~Button();

            /**
             * @brief Set the layer the button belongs to 
             * 
             * @param uLayer layer code
             */
            virtual void SetLayer(unsigned char uLayer) override;

            /**
             * @brief Set the size of the button
             * 
             * @param fWidth 
             * @param fHeight 
             */
            virtual void SetSize(float fWidth, float fHeight);

            /**
             * @brief Set the scale of the button
             * 
             * @param rScale scale to be set
             */
            virtual void SetScale(const Mirage::vec3<float>& rScale) override;

            /**
             * @brief Set the position of the button
             * 
             * @param rPosition position
             * @param bOnOverlay on overlay or not
             */
            virtual void SetPosition(
                const Mirage::vec3<float>& rPosition,
                bool                       bOnOverlay = false
            ) override;

            /**
             * @brief 
             * 
             * @param nWidth          width of the button
             * @param nHeight         height of the buttton
             * @param uLayer          layer code
             * @param svButtonText    text on the button
             * @param svBgImgMaterial background image material of the button 
             * @param svTextFont      font of the button text
             * @param uFontSize       font size of the button text
             */
            virtual void Configure(
                int              nWidth,
                int              nHeight,
                unsigned char    uLayer,
                std::string_view svButtonText = "Button",
                std::string_view svBgImgMaterial = "",
                std::string_view svTextFont = "",
                unsigned short   uFontSize = 12
            );

            /**
             * @brief fill the button with a gradually changing color
             * 
             * @param rColors color to be set
             */
            virtual void FillButton(const std::vector<vec4<float>>& rColors);

            /**
             * @brief fill the button with a certain color
             * 
             * @param rColor color to be set
             */
            virtual void FillButton(const vec4<float>& rColor);

            /**
             * @brief Fill the button with a image
             * 
             * @param svMaterial image material to be set
             */
            virtual void FillButton(std::string_view svMaterial);

            /**
             * @brief Set the text color, which can be a gradually changing color
             * 
             * @param rColors color to be set
             */
            virtual void SetTextColor(const std::vector<vec4<float>>& rColors);

            /**
             * @brief Set the text color, which can only be a pure color
             * 
             * @param rColor color to be set
             */
            virtual void SetTextColor(const vec4<float>& rColor);

            /**
             * @brief Set the click callback function
             * 
             * @param fnCallback 
             */
            virtual void SetClickCallback(std::function<void()> fnCallback);

            /**
             * @brief refresh the button
             * 
             */
            virtual void Refresh() override;
        
        private:
            float                          m_fWidth; 
            float                          m_fHeight; 
            float                          m_fViewWidth;
            float                          m_fViewHeight;
            bool                           m_bOnOverlay;
            bool                           m_bMaskEnabled;
            bool                           m_bClicked;
            Mirage::vec3<float>            m_vPosition;
            Mirage::vec3<float>            m_vScale;
            std::unique_ptr<Mirage::Image> m_upImg;
            std::unique_ptr<Mirage::Text>  m_upText;
            std::function<void()>          m_fnCallback;
    };
}