/**
 * @file MirageText.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-11-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageModel.hpp"
#include "MirageObject.hpp"
#include <memory>
#include <string_view>

namespace Mirage
{
    class MIRAGE_API Text: public Model {
        public:
            Text();
            virtual ~Text();

            /**
             * @brief Set the layer the text belongs to
             * 
             * @param uLayer layer code
             */
            virtual void SetLayer(unsigned char uLayer) override;

            /**
             * @brief Set the font size
             * 
             * @param uFontSize font size
             */
            virtual void SetFontSize(unsigned int uFontSize);

            /**
             * @brief Get the font size
             * 
             * @return unsigned int 
             */
            virtual unsigned int GetFontSize();
            
            /**
             * @brief Set the size of the text area
             * 
             * @param fWidth  width of the text area
             * @param fHeight height of the text area
             */
            virtual void SetSize(float fWidth, float fHeight);

            /**
             * @brief Set the text
             * 
             * @param svText text to be set
             */
            virtual void SetText(std::string_view svText);

            /**
             * @brief Set the scale of the text area
             * 
             * @param rScale the scale to be set
             */
            virtual void SetScale(const Mirage::vec3<float>& rScale) override;

            /**
             * @brief Set the position
             * 
             * @param rPosition  the position of the text area to be set
             * @param bOnOverlay on overlay or not 
             */
            virtual void SetPosition(
                const Mirage::vec3<float>& rPosition,
                bool                       bOnOverlay = false
            );

            /**
             * @brief Set the font path
             * 
             * @param svFontPath font path to be set
             */
            virtual void SetFont(std::string_view svFontPath);

            /**
             * @brief Set the text color
             * 
             * @param rColors color to be set
             */
            virtual void SetColor(const std::vector<vec4<float>>& rColors);

            /**
             * @brief Set the text color
             * 
             * @param rColor color to be set
             */
            virtual void SetColor(const vec4<float>& rColor);

            /**
             * @brief Get the width of the text area
             * 
             * @return float 
             */
            virtual float GetWidth() { return m_fWidth; }

            /**
             * @brief Get the height of the text area
             * 
             * @return float 
             */
            virtual float GetHeight() { return m_fHeight; }

            /**
             * @brief Get the pitch of the text area
             * 
             * @return float 
             */
            virtual float GetPitch() { return m_fPitch; }

            /**
             * @brief Get the scanline of the text area
             * 
             * @return float 
             */
            virtual float GetScanline() { return m_fScanline; }

            /**
             * @brief configure the text area 
             * 
             * @param uLayer     layer code to be set
             * @param svFontPath font path of the text uses
             * @param svText     text to be set
             * @param eAlign     align of the text in the text area
             * @param fWidth     width of the text area
             * @param fHeight    height of the text area
             */
            virtual void Configure(
                unsigned char            uLayer,
                std::string_view         svFontPath,
                std::string_view         svText,
                TextAlign                eAlign  = TextAlign::left,
                float                    fWidth  = 0,
                float                    fHeight = 0
            );

            /**
             * @brief is depth enabled
             * 
             * @return true 
             * @return false 
             */
            virtual bool IsDepthEnabled();

            /**
             * @brief Set the depth status
             * 
             * @param bEnable enable or disable the depth
             */
            virtual void SetDepthStatus(bool bEnable);

            /**
             * @brief refresh the text area 
             * 
             */
            virtual void Refresh() override;
        
        private:
            float                                 m_fWidth;
            float                                 m_fHeight;
            float                                 m_fPitch;
            float                                 m_fScanline;
            float                                 m_fViewWidth;
            float                                 m_fViewHeight;
            unsigned int                          m_uFontSize;
            unsigned char                         m_uLayer;
            bool                                  m_bOnOverlay;
            std::string                           m_strFontPath;
            std::string                           m_strText;
            Mirage::vec3<float>                   m_vPosition;
            Mirage::vec3<float>                   m_vScale;
    };
}