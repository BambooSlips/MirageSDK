/**
 * @file MirageAudioListener.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-02-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "common_def.hpp"
#include "mirage_result.hpp"

namespace Mirage
{
    class MIRAGE_API AudioListener {
        public:
            /**
             * @brief Get the instance
             * 
             * @return AudioListener& 
             */
            static AudioListener& GetInstance();

            /**
             * @brief Set the gain
             * 
             * @param fGain 
             * @return MRGResult 
             */
            MRGResult SetGain(float fGain);

            /**
             * @brief Get the gain
             * 
             * @return float 
             */
            float GetGain();

            /**
             * @brief Set the position
             * 
             * @param rPosition 
             * @return MRGResult 
             */
            MRGResult SetPosition(const Mirage::vec3<float>& rPosition);

            /**
             * @brief Get the position
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetPosition();

            /**
             * @brief Set the velocity of the audio listener
             * 
             * @param rVelocity 
             * @return MRGResult 
             */
            MRGResult SetVelocity(const Mirage::vec3<float>& rVelocity);

            /**
             * @brief Get the velocity of the audio listener
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetVelocity();

            /**
             * @brief Set the focus vector
             * 
             * @param rFocus 
             * @return MRGResult 
             */
            MRGResult SetFocusVector(const Mirage::vec3<float>& rFocus);

            /**
             * @brief Get the focus vector
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetFocusVector();

            /**
             * @brief Set the top vector
             * 
             * @param rTop 
             * @return MRGResult 
             */
            MRGResult SetTopVector(const Mirage::vec3<float>& rTop);

            /**
             * @brief Get the top vector
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetTopVector();
        
        private:
            AudioListener();
            ~AudioListener();
            AudioListener(const AudioListener& rListener) = delete;
            const AudioListener& operator=(const AudioListener& rListener) = delete;

        private:
            // float               m_fGain;
            // Mirage::vec3<float> m_vPosition;
            // Mirage::vec3<float> m_vVelocity;
            // Mirage::vec3<float> m_vFocus;
            // Mirage::vec3<float> m_vTop;

    };
    
} // namespace Mirage
