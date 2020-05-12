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
*  This is implementation for the LandBasedTracked class methods.
*/


#include "landbasedtracked.h"
#include "../API/api.h"

/**
 * @brief it is the implementation of fp::LandBasedWheeled::GetDirection() method that gets the direction of the robot in the maze
 * @param string
 * @return Returns none
 */
char fp::LandBasedTracked::GetDirection() {
    std::cerr << "LandBasedWheeled::GetDirection is called\n";
    return this->direction_;
}

/**
 * @brief it is the implementation of fp::LandBasedWheeled::MoveForward() method to moves the robot forward in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedTracked::MoveForward() {
    std::cerr << "LandBasedWheeled::MoveForward is called\n";
    fp::API::moveForward();
}


/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnLeft() method to rotates the robot 90°counter-clockwise in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedTracked::TurnLeft() {
    std::cerr << "LandBasedTracked::TurnLeft is called\n";
    fp::API::turnLeft();
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnRight() method to rotates the robot 90°clockwise in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedTracked::TurnRight() {
    std::cerr << "LandBasedTracked::TurnRight is called\n";
    fp::API::turnRight();
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::PickUp() method
 * @param string
 * @return Returns none
 */
void fp::LandBasedTracked::PickUp(std::string string) {
    std::cerr << "LandBasedTracked::Pickup the payload is called\n"<<string<<std::endl;
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::Release() method
 * @param string
 * @return Returns none
 */
void fp::LandBasedTracked::Release(std::string string) {
    std::cerr << "LandBasedTracked::Release payload is called\n"<<string<<std::endl;
}
