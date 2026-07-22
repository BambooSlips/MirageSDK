/**
 * @file MirageInput.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-07-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageInputCode.hpp"

namespace Mirage {

    typedef struct __tag_INPUT_POINT_2D {
        double x;
        double y;
    } InputPoint;

    typedef struct __tag_SCROLL_OFFSET_2D {
        double x;
        double y;
    } ScrollOffset;

    /**
     * @brief Is mouse button `eMouseButton` pressed
     * 
     * @param eMouseButton button code
     * @return true 
     * @return false 
     */
    bool MIRAGE_API IsMouseButtonPressed(Mirage::MouseButton eMouseButton);

    /**
     * @brief Is key pressed 
     * 
     * @param eKeyValue key code
     * @return true 
     * @return false 
     */
    bool MIRAGE_API IsKeyPressed(Mirage::KeyValue eKeyValue);

    /**
     * @brief Is key repeated
     * 
     * @param eKeyValue  key code
     * @return true 
     * @return false 
     */
    bool MIRAGE_API IsKeyRepeated(Mirage::KeyValue eKeyValue);
 
    /**
     * @brief Get the Cursor position
     * 
     * @param rCursorPoint cursor point
     */
    void MIRAGE_API GetCursorPoint(Mirage::InputPoint& rCursorPoint);

    /**
     * @brief Get the sroll offset
     * 
     * @param rSrollOffset scroll offset
     */
    void MIRAGE_API GetSrollOffset(Mirage::ScrollOffset& rSrollOffset);
}