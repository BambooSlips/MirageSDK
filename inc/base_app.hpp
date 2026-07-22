/**
 * @file base_app.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "base_layer.hpp"
#include <memory>

int main(int argc, char** argv);

namespace Mirage { class BaseApp; }
void Launch(std::unique_ptr<Mirage::BaseApp> upApp);

namespace Mirage
{
    class BaseApp {
        public:
            BaseApp() = default;
            virtual ~BaseApp() = default;

            virtual void PushLayer(std::unique_ptr<Mirage::BaseLayer> upLayer) = 0;
            virtual void PushOverlay(std::unique_ptr<Mirage::BaseLayer> upLayer) = 0;

        private:
            virtual void Run() = 0;
            friend void ::Launch(std::unique_ptr<Mirage::BaseApp> upApp);
    };

    using BaseAppPtr = std::unique_ptr<Mirage::BaseApp>;
    
} // namespace Mirage
