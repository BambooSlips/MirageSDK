/**
 * @file MirageVertexBoneInfo.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <unordered_map>
#include <string_view>
#include <vector>

namespace Mirage {
    typedef std::unordered_map<unsigned int, unsigned int> BoneIdxWeightMap;

    class VertexBoneInfo {
        public:

        VertexBoneInfo() = default;
        ~VertexBoneInfo() = default;

        void Write(std::string_view svFilePath); 

        void Read(std::string_view svFilePath); 

        inline unsigned int GetVertexNum() { return m_uVertexNum; };

        inline void SetVertexNum(unsigned int uNum) { m_uVertexNum = uNum; };

        std::vector<unsigned int>& GetBoneNum();

        std::vector<BoneIdxWeightMap>& GetVertexBoneMaps();

        void SetBoneNum(std::vector<unsigned int>&& rBoneNum);

        void SetVertexBoneMaps(std::vector<BoneIdxWeightMap>&& rMaps);
        
        private:
            unsigned int                  m_uVertexNum;
            std::vector<unsigned int>     m_vBoneNum;
            std::vector<BoneIdxWeightMap> m_vVertexBoneMaps;// 

    };

}