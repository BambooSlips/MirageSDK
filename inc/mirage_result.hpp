/**
 * @file mirage_result.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


enum MRGResult: int
{
    Success       = 0,
    InvalidParam  = 1,
    OOM           = 2,
    Failed        = 3,
    Unsupported   = 4,
};