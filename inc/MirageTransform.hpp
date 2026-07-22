/**
 * @file MirageTransform.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageComponent.hpp"
#include <memory>

namespace Mirage {
    class MIRAGE_API Transform: public Component {
        public:
            Transform(std::shared_ptr<void> spHandle);
            ~Transform();

            /**
             * @brief Get the position
             * 
             * @return vec3<float>& 
             */
            const vec3<float>& GetPosition();

            /**
             * @brief Get the rotation
             * 
             * @return vec3<float>& 
             */
            const vec3<float>& GetRotation();

            /**
             * @brief Get the scale
             * 
             * @return vec3<float>& 
             */
            const vec3<float>& GetScale();

            /**
             * @brief Set the position
             * 
             * @param rPos 
             */
            void SetPosition(const vec3<float>& rPos);

            /**
             * @brief Set the rotation
             * 
             * @param rRot 
             */
            void SetRotation(const vec3<float>& rRot);

            /**
             * @brief Set the scale
             * 
             * @param rScale 
             */
            void SetScale(const vec3<float>& rScale);

            /**
             * @brief Rotate through current tramsform
             * 
             * @param rRotVec rotation axis
             * @param fDegree rotation degree
             */
            void Rotate(const vec3<float>& rRotVec, float fDegree);

        private:
            std::shared_ptr<void> m_spHandle;
            vec3<float>           m_vPos;
            vec3<float>           m_vRot;
            vec3<float>           m_vScale;
    };
}