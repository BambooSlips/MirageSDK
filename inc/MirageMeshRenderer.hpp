/**
 * @file MirageMeshRenderer.hpp
 * @author BambooSlips
 * @brief MeshRenderer class declaration
 * @version 0.1
 * @date 2024-07-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageComponent.hpp"
#include "MirageMaterial.hpp"
#include <memory>

namespace Mirage {

    struct MIRAGE_API RendererDeleter
    {
        void operator()(void *p);
    };

    class MIRAGE_API MeshRenderer: public Component {
        public:
            MeshRenderer(std::shared_ptr<void> spHandle);
            virtual ~MeshRenderer() override;

            /**
             * @brief Set the Material object
             * 
             * @param upMaterial up to the Material, whose ownership will transfered to m_upMaterial
             */
            void SetMaterial(std::unique_ptr<Material> upMaterial);

            /**
             * @brief Is depth enabled or not
             * 
             */
            bool IsDepthEnabled();

            /**
             * @brief Set the septh status
             * 
             * @param bEnabled 
             */
            void SetDepthStatus(bool bEnable);

            /**
             * @brief Is cull face enabled or not 
             * 
             * @return true 
             * @return false 
             */
            bool IsCullFaceEnabled();

            /**
             * @brief Set the cull face status
             * 
             * @param bEnable 
             */
            void SetCullFaceStatus(bool bEnable);

            /**
             * @brief 
             * 
             */
            void Wakeup();

            /**
             * @brief render
             * 
             */
            void Render();
        
        private:
            std::shared_ptr<void>     m_spHandle;
            std::unique_ptr<Material> m_upMaterial;
    };
}