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
#include "../API/api.h"

//---> Method Definitions <---//
/**
 * @brief it is the implementation of fp::LandBasedWheeled::GetDirection() method that gets the direction of the robot in the maze
 * @param none
 * @return Returns none
 */
char fp::LandBasedWheeled::GetDirection() {
    std::cout << "LandBasedWheeled::GetDirection is called\n";
    return this->direction_;
}

/**
 * @brief it is the implementation of fp::LandBasedWheeled::MoveForward() method to moves the robot forward in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedWheeled::MoveForward(int x, int y) {
    std::cout << "LandBasedWheeled::MoveForward is called\n";
//    fp::API::moveForward();
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnLeft() method to rotates the robot 90°counter-clockwise in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedWheeled::TurnLeft(int x, int y) {
    std::cout << "LandBasedWheeled::TurnLeft is called\n";
//    fp::API::turnLeft();
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::TurnRight() method to rotates the robot 90°clockwise in the maze
 * @param int x
 * @param int y
 * @return Returns none
 */
void fp::LandBasedWheeled::TurnRight(int x, int y) {
    std::cout << "LandBasedWheeled::TurnRight is called\n";
//    fp::api::turnRight();
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::PickUp() method
 * @param string
 * @return Returns none
 */
void fp::LandBasedWheeled::PickUp(std::string string) {
    std::cout << "LandBasedTracked::Pickup the payload is called\n"<<string<<std::endl;
}

/**
 * @brief it is the implementation of fp::LandBasedTracked::Release() method
 * @param string
 * @return Returns none
 */
void fp::LandBasedWheeled::Release(std::string string) {
    std::cout << "LandBasedTracked::Release payload is called\n"<<string<<std::endl;
}

//---> Accessors <---//
/**
 * @brief it is a getter method for robot wheels number
 * @param none
 * @return Returns int wheel_number_
 */
int fp::LandBasedWheeled::getWheelNumber() const {
    return this->wheel_number_;
}

//---> Mutators <---//
/**
 * @brief it is a setter method for the Wheel Number
 * @param int wheelNumber
 * @return Returns none
 */
void fp::LandBasedWheeled::setWheelNumber(int wheelNumber) {
    this->wheel_number_ = wheelNumber;
}

