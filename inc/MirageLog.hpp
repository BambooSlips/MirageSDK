/**
 * @file MirageLog.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include <string_view>
#include <functional>

#ifndef MIRAGE_LOG_TAG
#define MIRAGE_LOG_TAG "MIRAGE"
#endif

static unsigned char g_uLogLevel = 0;

void MIRAGE_API MRG_CONFIG_LOG(unsigned char uLogLevel);

void MIRAGE_API MRG_CONFIG_LOG(unsigned char uLogLevel, std::function<void(std::string_view)> fnPrint);

/**
 * @brief
 * 
 */
void MIRAGE_API LOGV(const char* pTag, const char* pFileName, const char* pFnName, int nLineNum, const char *fmt, ...);

/**
 * @brief 
 * 
 */
void MIRAGE_API LOGI(const char* pTag, const char* pFileName, const char* pFnName, int nLineNum, const char *fmt, ...);

/**
 * @brief 
 * 
 */
void MIRAGE_API LOGD(const char* pTag, const char* pFileName, const char* pFnName, int nLineNum, const char *fmt, ...);

/**
 * @brief 
 * 
 */
void MIRAGE_API LOGE(const char* pTag, const char* pFileName, const char* pFnName, int nLineNum, const char *fmt, ...);

/**
 * @brief log that is always enabled 
 * 
 */
void MIRAGE_API LOGA(const char* pTag, const char* pFileName, const char* pFnName, int nLineNum, const char *fmt, ...);

#define MRG_LOGV(fmt, ...) LOGV(MIRAGE_LOG_TAG, __FILE_NAME__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define MRG_LOGD(fmt, ...) LOGD(MIRAGE_LOG_TAG, __FILE_NAME__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define MRG_LOGI(fmt, ...) LOGI(MIRAGE_LOG_TAG, __FILE_NAME__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define MRG_LOGE(fmt, ...) LOGE(MIRAGE_LOG_TAG, __FILE_NAME__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define MRG_LOGA(fmt, ...) LOGA(MIRAGE_LOG_TAG, __FILE_NAME__, __func__, __LINE__, fmt, ##__VA_ARGS__)