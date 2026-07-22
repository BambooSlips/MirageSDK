/**
 * @file MirageMeshFilter.hpp
 * @author BambooSlips
 * @brief Mirage::MeshFilter class declaration
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "common_def.hpp"
#include <string_view>
#include <memory>
#include <vector>
#include <unordered_map>

namespace Mirage {

    typedef std::unordered_map<unsigned int, unsigned int> BoneIdxWeightMap;

    class MIRAGE_API MeshFilter {
        public:
            MeshFilter(std::shared_ptr<void> spHandle);
            ~MeshFilter();

            /**
             * @brief load a mesh
             * 
             * @param svMeshPath path to the mesh 
             */
            void LoadMesh(std::string_view svMeshPath, bool bIsStatic = true);

            /**
             * @brief Create a mesh
             * 
             * @param rVertexes 
             * @param rVertexIndexes 
             */
            void CreateMesh(
                std::vector<Vertex>&       rVertexes, 
                std::vector<unsigned int>& rVertexIndexes,
                bool                       bIsStatic = true
            );

            /**
             * @brief count the number of vertexes
             * 
             * @return int 
             */
            int CountMeshVertexes();

            /**
             * @brief Set the mesh color
             * 
             * @param rColors 
             */
            void SetMeshColor(const std::vector<vec4<float>>& rColors);

            // void SetMeshColor(std::vector<vec4<float>> vColors);

            /**
             * @brief Set the mesh color
             * 
             * @param rColor 
             */
            void SetMeshColor(const vec4<float>& rColor);

            /**
             * @brief Set the information of bones vertices follow
             * 
             * @param rVertexBoneMaps 
             */
            void SetVertexBoneMaps(
                std::vector<Mirage::BoneIdxWeightMap>&& rVertexBoneMaps
            );
        
        private:
            std::shared_ptr<void> m_spHandle;
    };
}