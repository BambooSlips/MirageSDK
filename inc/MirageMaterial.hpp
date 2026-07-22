#pragma once

#include "common_def.hpp"
#include <string_view>
#include <memory>
#include <vector>

namespace Mirage {
    class MeshRenderer;
    struct TextureDeleter;

    struct MIRAGE_API MaterialDeleter
    {
        void operator()(void *p);
    };

    class MIRAGE_API Material {
        public:
            Material();
            ~Material();

            /**
             * @brief 
             * 
             * @param svMaterialPath 
             */
            void Parse(std::string_view svMaterialPath);

            /**
             * @brief get the number of the textures
             * 
             * @return unsigned int 
             */
            int GetTextureNum();

            /**
             * @brief add a texture
             * 
             * @param svProp 
             * @param upTexture texture to be added 
             */
            void AddTexture(
                std::string_view                      svProp, 
                std::unique_ptr<void, TextureDeleter> upTexture
            );

            /**
             * @brief set a new texture
             * 
             * @param svProp 
             * @param upTexture the new texture to be set
             */
            void SetTexture(
                std::string_view                      svProp, 
                std::unique_ptr<void, TextureDeleter> upTexture
            );
        
        private:
           std::unique_ptr<void, MaterialDeleter> m_upHandle;
           friend MeshRenderer;
    };
}