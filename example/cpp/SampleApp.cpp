/**
 * @file SampleApp.cpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "MirageApplication.hpp"
#include "MirageLog.hpp"
#include "SampleLayer.hpp"
#include "DemoOverlay.hpp"
#include <memory>
#include <string>
#include <filesystem>

class SampleApp: public Mirage::Application
{
    public:
        SampleApp(const Mirage::ApplicationProps& rProps)
            : Mirage::Application(rProps)
        {
            PushLayer(std::make_unique<SampleLayer>(rProps.strWorkspaceDir));
            PushOverlay(std::make_unique<DemoOverlay>(rProps.strWorkspaceDir));
        }

        ~SampleApp()
        {

        }
};

std::unique_ptr<Mirage::BaseApp> 
CreateApp(Mirage::ApplicationArgs& refArgs)
{
    Mirage::ApplicationProps appProps;

    appProps.strName = "SampleApp";
    appProps.strWorkspaceDir = APP_WORKSPACE;
    appProps.args = refArgs;

    return std::make_unique<SampleApp>(appProps);
}