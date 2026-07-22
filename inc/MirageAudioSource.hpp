/**
 * @file MirageAudioSource.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageComponent.hpp"
#include "mirage_result.hpp"
#include <memory>

namespace Mirage {
    class AudioBuffer;
    class MIRAGE_API AudioSource: public Component {
        public:
            AudioSource(std::shared_ptr<void> spData);
            ~AudioSource();

            /**
             * @brief Set the position of the audio source
             * 
             * @param rPos 
             */
            void SetPosition(const Mirage::vec3<float>& rPos);

            /**
             * @brief Get the position of the audio source
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetPosition();

            // void SetAudioBuffer()

            /**
             * @brief Set the audio pitch
             * 
             * @param fPitch 
             */
            void SetAudioPitch(float fPitch);

            /**
             * @brief Get the audio pitch
             * 
             * @return float 
             */
            float GetAudioPitch();

            /**
             * @brief Set the audio gain
             * 
             * @param fGain 
             */
            void SetAudioGain(float fGain);

            /**
             * @brief Get the audio gain
             * 
             * @return float 
             */
            float GetAudioGain();

            /**
             * @brief Set the Audio Velocity object
             * 
             * @param rVelocity 
             */
            void SetVelocity(const Mirage::vec3<float>& rVelocity);

            /**
             * @brief Get the velocity of the audio source
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetVelocity();

            /**
             * @brief Set the looping status
             * 
             * @param bEnable 
             */
            void SetLoopingStatus(bool bEnable);

            /**
             * @brief Get the looping status
             * 
             * @return true 
             * @return false 
             */
            bool GetLoopingStatus();

            /**
             * @brief Set the audio buffer
             * 
             * @param uBuffer 
             * @return MRGResult 
             */
            MRGResult SetBuffer(const AudioBuffer& rBuffer);

            /**
             * @brief 
             * 
             * @return MRGResult 
             */
            MRGResult PlayAudio();

            /**
             * @brief 
             * 
             * @return MRGResult 
             */
            MRGResult StopPlaying();

            /**
             * @brief 
             * 
             * @return MRGResult 
             */
            MRGResult PausePlaying();

            /**
             * @brief 
             * 
             * @return true 
             * @return false 
             */
            bool IsPlaying();

        private:
            std::shared_ptr<void> m_spHandle;
            Mirage::vec3<float>   m_vPosition;
            Mirage::vec3<float>   m_vVelocity;
            float                 m_fPitch;
            float                 m_fGain;
            bool                  m_bLooping;
    };
}