/**
* @file landbasedtracked.cpp
* @authors Group 4
*
* Karan Sutradhar (117037272)
* Sudharsan Balasubramani (116298636)
* Sai Bhamidipati (117023640)
* Ashwin Prabhakaran (117030402)
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
*  This is implementation for the LandBasedWheeled class methods.
*/

#include "landbasedwheeled.h"
#include <iostream>
#include "../API/api.h"

/**
 * @brief it is the implementation of fp::LandBasedWheeled::GetDirection() method that gets the direction of the robot in the maze
 * @param string
 * @return Returns none
 */

char fp::LandBasedWheeled::GetDirection() {
    std::cout << "LandBasedWheeled::GetDirection is called\n";
    return direction_;
}

/**
 * @brief it is the implementation of fp::LandBasedWheeled::MoveForward() method to moves the robot forward in the maze
 * @param int x_
 * @param int y_
 * @return Returns none
 */

void fp::LandBasedWheeled::MoveForward() {
    std::cout << "LandBasedWheeled::MoveForward is called\n";
    if (fp::LandBasedWheeled::GetDirection() == 'N')
    {
        x_ = x_;
        y_ = y_ + 1;
    }
    if (fp::LandBasedWheeled::GetDirection() == 'E')
    {
        x_ = x_ + 1;
        y_ = y_ ;
    }
    if (fp::LandBasedWheeled::GetDirection() == 'W')
    {
        x_ = x_ - 1;
        y_ = y_;
    }
    if (fp::LandBasedWheeled::GetDirection() == 'S')
    {
        x_ = x_;
        y_ = y_ - 1;
    }
    fp::api::moveForward();
}
/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnLeft() method to rotates the robot 90°counter-clockwise in the maze
 * @param int x_
 * @param int y_
 * @return Returns none
 */

void fp::LandBasedWheeled::TurnLeft() {
    std::cout << "LandBasedWheeled::TurnLeft is called\n";
    {
        if(fp::LandBasedWheeled::GetDirection() == 'N')
            direction_ = 'W';

        if(fp::LandBasedWheeled::GetDirection() == 'E')
            direction_ = 'N';

        if(fp::LandBasedWheeled::GetDirection() == 'W')
            direction_ = 'S';

        if(fp::LandBasedWheeled::GetDirection() == 'S')
            direction_ = 'E';

        fp::api::turnLeft();
    }
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnRight() method to rotates the robot 90°clockwise in the maze
 * @param int x_
 * @param int y_
 * @return Returns none
 */

void fp::LandBasedWheeled::TurnRight() {
    std::cout << "LandBasedWheeled::TurnRight is called\n";
    {
        if(fp::LandBasedWheeled::GetDirection() == 'N')
            direction_ = 'E';

        if(fp::LandBasedWheeled::GetDirection() == 'E')
            direction_ = 'S';

        if(fp::LandBasedWheeled::GetDirection() == 'W')
            direction_ = 'N';

        if(fp::LandBasedWheeled::GetDirection() == 'S')
            direction_ = 'W';

        fp::api::turnRight();
    }
}
