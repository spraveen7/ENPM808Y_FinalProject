/**
* @file api.h
* @authors Group 4
*
* Karan Sutradhar (117037272)
* Sudharsan Balasubramani (116298636)
* Sai Bhamidipati (117023640)
* Ashwin Prabhakaran (117030402)
* Girish Ethirajan
*
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
*  This is the header for the class api, it is used as an Application Programmable Interface
*  between the micro-mouse simulator and the user defined functions.
*/

#pragma once
#include <string>
namespace  fp {

    class api {

    public:

        static int mazeWidth();

        static int mazeHeight();

        static bool wallFront();

        static bool wallRight();

        static bool wallLeft();

        static void moveForward();

        static void turnRight();

        static void turnLeft();

        static void setWall(int x, int y, char direction);

        static void clearWall(int x, int y, char direction);

        static void setColor(int x, int y, char color);

        static void clearColor(int x, int y);

        static void clearAllColor();

        static void setText(int x, int y, const std::string &text);

        static void clearText(int x, int y);

        static void clearAllText();

        static bool wasReset();

        static void ackReset();

        api();

        ~api();

    };
}