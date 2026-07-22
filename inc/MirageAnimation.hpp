/**
 * @file MirageAnimation.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-04-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "common_def.hpp"
#include "mirage_result.hpp"
#include <memory>

namespace Mirage {
    class MIRAGE_API Animation {
        public:
            Animation(std::shared_ptr<void> spData);
            ~Animation();

            /**
             * @brief Load a animation clip form a file and name it 
             * 
             * @param svFilePath 
             * @param svAliasName 
             * @return MRGResult 
             */
            MRGResult LoadClipFromFile(
                std::string_view svFilePath,
                std::string_view svAliasName
            );
            
            /**
             * @brief Play the animation clip named svClipName 
             * 
             * @param svClipName 
             * @return MRGResult 
             */
            MRGResult Play(std::string_view svClipName);

            /**
             * @brief If the animation is being played 
             * 
             * @return true 
             * @return false 
             */
            // bool IsPlaying();
    
            /**
             * @brief Set the duration of a animation clip named svClipName
             * 
             * @param svClipName 
             * @param fDuration 
             */
            void SetDuration(std::string_view svClipName, float fDuration);

            /**
             * @brief Get the name of the current animation clip
             * 
             * @return std::string_view 
             */
            inline std::string_view GetCurrClipName() { return m_strCurrClipName; };

        private:
            std::shared_ptr<void> m_spHandle;
            std::string           m_strCurrClipName;
    };
}