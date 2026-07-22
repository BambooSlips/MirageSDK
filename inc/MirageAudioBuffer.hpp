/**
 * @file MirageAudioBuffer.hpp
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
// #include "MirageComponent.hpp"
#include "mirage_result.hpp"
#include <memory>

/** Unsigned 8-bit mono buffer format. */
#define MRG_AUDIO_FORMAT_MONO8                          0x1100
/** Signed 16-bit mono buffer format. */
#define MRG_AUDIO_FORMAT_MONO16                         0x1101
/** Unsigned 8-bit stereo buffer format. */
#define MRG_AUDIO_FORMAT_STEREO8                        0x1102
/** Signed 16-bit stereo buffer format. */
#define MRG_AUDIO_FORMAT_STEREO16                       0x1103

namespace Mirage {
    class AudioSource;
    class MIRAGE_API AudioBuffer {
        public:
            AudioBuffer();
            AudioBuffer(std::shared_ptr<void> spHandle);
            ~AudioBuffer();

            // MRGResult LoadAudioData(
            //     // std::unique_ptr<uint8_t[]> upData,
            //     // std::unique_ptr<void>      upData,
            //     std::unique_ptr<uint8_t>      upData,
            //     unsigned int               uFormat,
            //     unsigned int               uSize,
            //     unsigned int               uFreq     
            // );

        private:
            std::shared_ptr<void> m_spHandle;
            friend AudioSource;
    };
}