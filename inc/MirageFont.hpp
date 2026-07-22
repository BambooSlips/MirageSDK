/**
 * @file MirageFont.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-08-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include <memory>
#include <string_view>
#include <vector>

namespace Mirage {
    struct MIRAGE_API TextureDeleter
    {
        void operator()(void *p);
    };

    class MIRAGE_API Font {
        public:
            Font(std::shared_ptr<void> spData);
            ~Font();

            /**
             * @brief 
             * 
             * @param c 
             */
            void LoadChar(char c);

            /**
             * @brief Create a text texture
             * 
             * @param svText text in the texture
             * @param rRatio aspect ratio
             * @param rVertexes vertexes of the texture
             * @param rVertexIndexes vertexes indexes of the texture
             * @param eAlign text align in the texture
             * @param uMaxWidth max width of the texture
             * @param uMaxHeight max height of the texture
             * @return std::unique_ptr<void, TextureDeleter> 
             */
            std::unique_ptr<void, TextureDeleter> CreateTextTexture(
                std::string_view           svText,
                float&                     rRatio,
                std::vector<Vertex>&       rVertexes,
                std::vector<unsigned int>& rVertexIndexes,
                TextAlign                  eAlign     = TextAlign::left,
                unsigned int               uMaxWidth  = 0,
                unsigned int               uMaxHeight = 0
            );

            /**
             * @brief Get the width of the texture
             * 
             * @return unsigned int 
             */
            unsigned int GetWidth();

            /**
             * @brief Get the height of the texture
             * 
             * @return unsigned int 
             */
            unsigned int GetHeight();

            /**
             * @brief Get the pitch of the texture
             * 
             * @return unsigned int 
             */
            unsigned int GetPitch();

            /**
             * @brief Get the scanline of the texture
             * 
             * @return unsigned int 
             */
            unsigned int GetScanline();

        public:
            /**
             * @brief load the font form a file
             * 
             * @param svFilePath 
             * @param uFtSize 
             * @return std::shared_ptr<Font> 
             */
            static std::shared_ptr<Font> LoadFontFromFile(
                std::string_view svFilePath,
                unsigned short   uFtSize
            );

        private:
            std::shared_ptr<void> m_spHandle;

    };
}