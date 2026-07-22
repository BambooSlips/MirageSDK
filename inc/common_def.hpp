/**
 * @file common_def.hpp
 * @author BambooSlips 
 * @brief 
 * @version 0.1
 * @date 2024-06-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>

#ifdef _WIN32
    #ifdef EXPORT_SHARED_LIB
        #define MIRAGE_API __declspec(dllexport)
    #else
        #define MIRAGE_API __declspec(dllimport)
    #endif
#elif defined(__GNUC__) && __GNUC__ >= 4
    #define MIRAGE_API __attribute__((visibility("default")))
#else
    #define MIRAGE_API
#endif

namespace Mirage {
    struct ApplicationArgs {
        int nCount = 0;
        char** ppArgs = nullptr;

        // const char* operator[](int nIndex) const
        // {
        //     return ppArgs[nIndex]; 
        // }
    };

    struct ApplicationProps
    {
        std::string strName = "Mirage app";
        std::string strWorkspaceDir;

        ApplicationArgs args;
    };

    template<typename T>
    struct vec2 {
        T x;
        T y;
    };

    template<typename T>
    struct vec3 {
        T x;
        T y;
        T z;
    };

    template<typename T>
    struct vec4 {
        T r;
        T g;
        T b;
        T a;
    };

    struct Vertex
    {
        vec3<float> vPos;
        vec4<float> vColor;
        vec2<float> vUV;
    };

    enum TextAlign: unsigned char
    {
        left   = 0,
        right  = 1,
        center = 2
    };

    class Application;
}
