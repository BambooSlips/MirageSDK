/**
 * @file MirageObject.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "common_def.hpp"
#include "MirageComponent.hpp"
#include "MirageTransform.hpp"
#include "MirageMeshFilter.hpp"
#include "MirageMeshRenderer.hpp"
#include "MirageCamera.hpp"
#include "MirageAudioSource.hpp"
#include "MirageAnimation.hpp"
#include <memory>
#include <string_view>


namespace Mirage {

    class MIRAGE_API Object {
        public:
            Object(std::string_view svName);
            virtual ~Object();

            /**
             * @brief Add a component
             * 
             * @tparam T 
             * @tparam U 
             * @return std::unique_ptr<T> 
             */
            template <class T, class U> std::unique_ptr<T> AddComponent();

            /**
             * @brief Add a component
             * 
             * @tparam T 
             * @return std::unique_ptr<T> 
             */
            template <class T> std::unique_ptr<T> AddComponent();

            /**
             * @brief Get the component
             * 
             * @tparam T 
             * @return std::unique_ptr<T> 
             */
            template <class T> std::unique_ptr<T> GetComponent();

            /**
             * @brief Get the layer the object belongs to.
             * 
             * @return unsigned char 
             */
            unsigned char GetLayer();

            /**
             * @brief Set the layer the object belongs to.
             * 
             * @param uLayer 
             */
            void SetLayer(unsigned char uLayer);

            /**
             * @brief Get the name of the object
             * 
             * @return std::string_view 
             */
            std::string_view GetName();

            /**
             * @brief Set the name of the object
             * 
             * @param svName 
             */
            void SetName(std::string_view svName);

            /**
             * @brief If mask enabled or not.
             * 
             * @return true 
             * @return false 
             */
            bool IsMaskEnabled();

            /**
             * @brief Enable the mask.
             * 
             */
            void EnableMask();

            /**
             * @brief Disable the mask.
             * 
             */
            void DisableMask();

        private:
            std::shared_ptr<void> m_spHandle;
    };

}