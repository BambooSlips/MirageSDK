/**
 * @file MirageModel.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-11-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "MirageObject.hpp"
#include "MirageTransform.hpp"
#include "MirageMeshFilter.hpp"
#include "MirageMeshRenderer.hpp"
#include "MirageAudioSource.hpp"
#include <functional>
#include <unordered_map>

namespace Mirage
{
    class MIRAGE_API Model {
        public:
            Model();
            virtual ~Model();

            /**
             * @brief 
             * 
             */
            virtual void Refresh();

            /**
             * @brief Set the layer
             * 
             * @param uLayer 
             */
            virtual void SetLayer(unsigned char uLayer);

            /**
             * @brief Get the layer
             * 
             */
            virtual unsigned char GetLayer(); 

            /**
             * @brief Set the size
             * 
             * @param fWidth 
             * @param fHeight 
             */
            // virtual void SetSize(float fWidth, float fHeight) override;

            /**
             * @brief Set the position
             * 
             * @param rPosition 
             * @param bOnOverlay 
             */
            virtual void SetPosition(
                const Mirage::vec3<float>& rPosition,
                bool                       bOnOverlay = false
            );

            /**
             * @brief Get the position
             * 
             * @return const vec3<float>& 
             */
            virtual const Mirage::vec3<float>& GetPosition();

            /**
             * @brief Set the rotation
             * 
             * @param rRot 
             */
            void SetRotation(const vec3<float>& rRot);

            /**
             * @brief Get the rotation
             * 
             * @return vec3<float>& 
             */
            virtual const Mirage::vec3<float>& GetRotation();

            /**
             * @brief Get the scale
             * 
             * @return vec3<float>& 
             */
            virtual const Mirage::vec3<float>& GetScale();

            /**
             * @brief Set the scale
             * 
             * @param rScale 
             */
            virtual void SetScale(const Mirage::vec3<float>& rScale);

            /**
             * @brief Set the material
             * 
             * @param svMaterial 
             */
            virtual void SetMaterial(std::string_view svMaterial);

            /**
             * @brief Set the mesh
             * 
             * @param svMesh 
             */
            virtual void SetMesh(std::string_view svMesh, bool bIsStaic = true);

            /**
             * @brief Create a mesh
             * 
             * @param rVertexes 
             * @param rVertexIndexes 
             */
            virtual void CreateMesh(
                std::vector<Vertex>&       rVertexes, 
                std::vector<unsigned int>& rVertexIndexes,
                bool                       bIsStatic = true
            );
            
            /**
             * @brief Set the information of bones vertices follow
             * 
             * @param rVertexBoneMaps 
             */
            virtual void SetVertexBoneMaps(
                std::vector<Mirage::BoneIdxWeightMap>&& rVertexBoneMaps
            );

            /**
             * @brief 
             * 
             */
            virtual void Wakeup();

            /**
             * @brief Enable or disable cull face
             * 
             * @param bEnable 
             */
            virtual void SetCullFaceStatus(bool bEnable);

            /**
             * @brief 
             * 
             * @param fnTrigger event trigger
             * @param fnAction  event action
             * @return unsigned long 
             */
            virtual unsigned long AddEvent(
                std::function<bool()> fnTrigger,
                std::function<void()> fnAction
            );

            /**
             * @brief Configure the model
             * 
             * @param uLayer 
             * @param svMaterial 
             * @param svMesh 
             */
            virtual void Configure(
                unsigned char    uLayer,
                std::string_view svMaterial,
                std::string_view svMesh,
                bool             bIsStatic = true
            );

            /**
             * @brief Add a component
             * 
             * @tparam T 
             */
            template<class T> std::unique_ptr<T> AddComponent();

            /**
             * @brief Get the component
             * 
             * @tparam T 
             * @return std::unique_ptr<T> 
             */
            template<class T> std::unique_ptr<T> GetComponent();
        
        private:
            virtual void Render();
        
        protected:
            std::shared_ptr<Mirage::Object>       m_spObject; 
            std::unique_ptr<Mirage::Transform>    m_upTransform;
            std::unique_ptr<Mirage::MeshFilter>   m_upMeshFilter;
            std::unique_ptr<Mirage::MeshRenderer> m_upMeshRenderer;

        private:
            bool                                  m_bOnOverlay;
            Mirage::vec3<float>                   m_vPosition;
            Mirage::vec3<float>                   m_vRotation;
            Mirage::vec3<float>                   m_vScale;
            std::unordered_map<
                unsigned long, 
                std::pair<
                    std::function<bool()>, 
                    std::function<void()>
                >
            >                                     m_EventMap;
    };

    template<class T> std::unique_ptr<T> Model::AddComponent()
    {
        return m_spObject->AddComponent<T>();
    }

    template<class T> std::unique_ptr<T> Model::GetComponent()
    {
        return m_spObject->GetComponent<T>();
    }
} // namespace Mirage