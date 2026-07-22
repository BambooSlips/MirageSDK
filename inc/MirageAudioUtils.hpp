/**
 * @file MirageAudioUtils.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-02-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "MirageAudioBuffer.hpp"
#include "common_def.hpp"
#include <memory>
#include <string_view>

namespace Mirage {
    class MIRAGE_API AudioUtils {
        public:
            static std::shared_ptr<AudioBuffer> LoadAudioBuffer(
                std::string_view svFileName
            );

        private:
    };
}
