/**
 * @file MirageApplication.hpp
 * @author BambooSlips
 * @brief Application class declaration
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "base_layer.hpp"
#include "base_app.hpp"
#include <memory>

namespace Mirage {
    /**
     * @brief functor to delete the handle 
     * 
     */
    struct MIRAGE_API AppDeleter
    {
        void operator()(void* p);
    };

    class MIRAGE_API Application: public BaseApp {
        public:
            Application(const ApplicationProps& rProps);
            virtual ~Application();

            /**
             * @brief push a layer as common layer 
             * 
             * @param upLayer 
             */
            void PushLayer(std::unique_ptr<BaseLayer> upLayer) override;

            /**
             * @brief push a layer as overlay
             * 
             * @param upLayer 
             */
            void PushOverlay(std::unique_ptr<BaseLayer> upLayer) override;
        
        private:
            /**
             * @brief Run the APP
             * 
             */
            void Run();

        private:
            std::unique_ptr<void, AppDeleter> m_upHandle;
    };
} // namespace Mirage
