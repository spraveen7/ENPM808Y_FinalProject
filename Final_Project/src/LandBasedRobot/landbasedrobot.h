/**
* @file landbasedrobot.h
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
*  This is an abstract class implementation and two different derived classes
*  (landbasedtracked and landbasedwheeled) share the attributes
*  and methods of this base class
*/

#pragma once
#include <string>
#include<iostream>

namespace fp {
    class LandBasedRobot {

    protected:
        //--attributes
        std::string name_;      //--Name of the robot
        double speed_;      //--Driving speed of the robot
        double width_;      //--Width of the base of the robot
        double length_;     //--Length of the base of the robot
        double height_;     //--Height of the base of the robot
        double capacity_;      //--Payload of the arm
        int x_;     //--X coordinate of the robot in the maze
        int y_;     //--Y coordinate of the robot in the maze
        char direction_;        //--Direction that the robot is facing in the maze

        //--methods prototypes

        //--Get the direction of the robot in the maze

        //--Moves the robot forward

        //--Rotates the robot 90°counter-clockwise

        //--Rotates the robot 90°clockwise

    protected:
        //--constructor
        /**
         * @brief it is a constructor of the class LandBasedRobot
         * @param string name_
         * @param double speed_
         * @param double width_
         * @param double length_
         * @param double height_
         * @param double capacity_
         * @param int x_
         * @param int y_
         * @param char direction_
         * @return Returns none
         */
        LandBasedRobot(std::string name, double speed, double width, double length, double height, double capacity, int x, int y, char direction){
            name_ =  name;
            speed_ = speed;
            width_ = width;
            length_ = length;
            height_ = height;
            capacity_ = capacity;
            direction_ = direction;
            x_ = x;
            y_ = y;
        }

        //--destructor

        /**
         * @brief it is a destructor of the class landbasedrobot and deletes the objects created
         * @param none
         * @return Returns none
         */
        ~LandBasedRobot(){}

    public:
        //--mutators

        /**
         * @brief it is a setter method for the x-axis
         * @param int x
         * @return Returns none
         */
        void set_x(int x){
            x_ = x;
        }

        /**
         * @brief it is a setter method for the y-axis
         * @param int y
         * @return Returns none
         */
        void set_y(int y){
            y_ = y;
        }


        //--accessors

        /**
         * @brief it is a getter method for the x-axis
         * @param none
         * @return Returns int x
         */
        int get_x_() const{
            return x_;
        }

        /**
         * @brief it is a getter method for the y-axis
         * @param none
         * @return Returns int y
         */
        int get_y_() const{
            return y_;
        }

        /**
             * @brief it is a pure virtual method that gets the direction of the robot in the maze
             * @param string
             * @return Returns none
             */
        virtual char GetDirection() = 0 ;

        /**
             * @brief it is a pure virtual method that moves the robot forward in the maze
             * @param int x_
             * @param int y_
             * @return Returns none
             */
        virtual void MoveForward() = 0;

        /**
             * @brief it is a pure virtual method that rotates the robot 90°counter-clockwise in the maze
             * @param int x_
             * @param int y_
             * @return Returns none
             */
        virtual void TurnLeft() = 0;

        /**
             * @brief it is a pure virtual method that rotates the robot 90°clockwise in the maze
             * @param int x_
             * @param int y_
             * @return Returns none
             */
        virtual void TurnRight() = 0;
    };//--Class LandBasedRobot
}//--namespace fp
