/**
 * @file MirageObserver.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "MirageModel.hpp"
#include "MirageObject.hpp"
#include "MirageCamera.hpp"
#include "MirageTransform.hpp"
#include <memory>

namespace Mirage
{
    class MIRAGE_API Observer {
        public:
            Observer();
            virtual ~Observer();

            /**
             * @brief Set depth
             * 
             * @param uDepth 
             */
            void SetDepth(unsigned short uDepth);

            /**
             * @brief Set the culling mask
             * 
             * @param uMask 
             */
            void SetCullingMask(unsigned char uMask);

            /**
             * @brief Set the view
             * 
             * @param rFocusVec 
             * @param rTopVec 
             */
            void SetView(const Mirage::vec3<float>& rFocusVec, const Mirage::vec3<float>& rTopVec);

            /**
             * @brief Set the projection
             * 
             * @param fFovDegree 
             * @param fAspectRatio 
             * @param fNearClip 
             * @param fFarClip 
             */
            void SetProjection(
                float fFovDegree,
                float fAspectRatio,
                float fNearClip,
                float fFarClip
            );

            /**
             * @brief 
             * 
             * @param fLeft 
             * @param fRight 
             * @param fTop 
             * @param fBottom 
             * @param fNear 
             * @param fFar 
             */
            void EnableOrthoView(
                float fLeft,
                float fRight,
                float fTop,
                float fBottom,
                float fNear,
                float fFar
            );

            /**
             * @brief Set the position of the observer
             * 
             * @param rPosition 
             */
            void SetPosition(const Mirage::vec3<float>& rPosition);

            /**
             * @brief Set the clear flag
             * 
             * @param uClearFlag 
             */
            void SetClearFlag(unsigned int uClearFlag);

            /**
             * @brief Get the Position object
             * 
             * @return const Mirage::vec3<float>& 
             */
            const Mirage::vec3<float>& GetPosition();

            /**
             * @brief 
             * 
             * @param rRotAxisVec 
             * @param fDegree 
             */
            void Rotate(const Mirage::vec3<float>& rRotAxisVec, float fDegree);

            const Mirage::vec3<float>& GetRotation();
            /**
             * @brief 
             * 
             */
            void ClearView();
        
        private:
            Mirage::vec3<float>                m_vFocusVec; 
            Mirage::vec3<float>                m_vTopVec;
            std::shared_ptr<Mirage::Object>    m_spObj;
            std::unique_ptr<Mirage::Camera>    m_upCamera;
            std::unique_ptr<Mirage::Transform> m_upTransform;
    };
}