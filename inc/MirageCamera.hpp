/**
 * @file MirageCamera.hpp
 * @author BambooSlips
 * @brief Camera class declaration
 * @version 0.1
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageComponent.hpp"
#include <functional>

#define MRG_DEPTH_BUFFER_BIT   0x00000100
#define MRG_STENCIL_BUFFER_BIT 0x00000400
#define MRG_COLOR_BUFFER_BIT   0x00004000

namespace Mirage {
    class MIRAGE_API Camera: public Component {
        public:
            Camera(std::shared_ptr<void> spHandle);
            ~Camera() override;

            /**
             * @brief Set the view matrix
             * 
             * @param rFocusVec focus vector
             * @param rTopVec   top vector
             */
            void SetViewMat(const vec3<float>& rFocusVec, const vec3<float>& rTopVec);

            /**
             * @brief Set the projection matrix
             * 
             * @param fFovDegress 
             * @param fAspectRatio 
             * @param fNearClip 
             * @param fFarClip 
             */
            void SetProjectionMat(
                const float fFovDegress,
                const float fAspectRatio,
                const float fNearClip,
                const float fFarClip
            );

            /**
             * @brief Set the depth
             * 
             * @param uDepth depth to be set
             */
            void SetDepth(unsigned short uDepth);

            /**
             * @brief Set the clear flag
             * 
             * @param uClearFlag clear flag to be set
             */
            void SetClearFlag(unsigned int uClearFlag);

            /**
             * @brief Set the culling mask
             * 
             * @param uCullingMask culling mask to be set
             */
            void SetCullingMask(unsigned char uCullingMask);

            /**
             * @brief
             * 
             * @param fLeft 
             * @param fRight 
             * @param fTop 
             * @param fBottom 
             * @param fZNear 
             * @param fZFar 
             */
            void EnableOrtho(
                float fLeft,
                float fRight,
                float fTop,
                float fBottom,
                float fZNear,
                float fZFar
            );

            /**
             * @brief 
             * 
             */
            void Clear();

            /**
             * @brief 
             * 
             * @param fnAction 
             */
            static void Foreach(std::function<void()> fnAction);
        
        private:
            std::shared_ptr<void> m_spHandle;
    };
}