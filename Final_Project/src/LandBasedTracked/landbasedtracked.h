/**
* @file landbasedtracked.h
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
*  This is the header for the LandBasedTracked class which is a concrete class and inherits
*  the base class LandBasedRobot and declares the necessary attributes
*  and method prototypes.
*/


#pragma once
#include <string>
#include<iostream>
#include "../LandBasedRobot/landbasedrobot.h"

namespace fp {
    class LandBasedTracked : public LandBasedRobot{
    protected:
        //--attributes
        std::string track_type_;       //--Type of track mounted on the robot

    protected:
        //--methods prototypes
        /**
         * @brief it is a pure virtual method that gets the direction of the robot in the maze
         * @param string
         * @return Returns none
         */
        virtual char GetDirection(std::string) override;       //--Get the direction of the robot in the maze

        /**
         * @brief it is a pure virtual method that moves the robot forward in the maze
         * @param int x_
         * @param int y_
         * @return Returns none
         */
        virtual void MoveForward(int x_, int y_) override;     //--Moves the robot forward

        /**
         * @brief it is a pure virtual method that rotates the robot 90°counter-clockwise in the maze
         * @param int x_
         * @param int y_
         * @return Returns none
         */
        virtual void TurnLeft(int x_, int y_) override;       //--Rotates the robot 90°counter-clockwise

        /**
         * @brief it is a pure virtual method that rotates the robot 90°clockwise in the maze
         * @param int x_
         * @param int y_
         * @return Returns none
         */
        virtual void TurnRight(int x_, int y_) override;      //--Rotates the robot 90°clockwise

    public:
        //--constructor

        /**
         * @brief it is a constructor of the class LandBasedTracked
         * @param string name_
         * @param double speed_
         * @param double width_
         * @param double length_
         * @param double height_
         * @param double capacity_
         * @param int x_
         * @param int y_
         * @param char direction_
         * @param string track_type_
         * @return Returns none
         */

        LandBasedTracked(std::string track_type_, std::string name_, double speed_, double width_, double length_, double height_, double capacity_, int x_, int y_, char direction_): LandBasedRobot(name_, speed_, width_, length_, height_, capacity_, x_, y_, direction_), track_type_{}{
            name_ =  name_;
            speed_ = speed_;
            width_ = width_;
            length_ = length_;
            height_ = height_;
            capacity_ = capacity_;
            direction_ = direction_;
            x_ = x_;
            y_ = y_;
            track_type_ = track_type_;
        }

        //--destructor
        /**
         * @brief it is a destructor of the class LandBasedTracked and deletes the objects created
         * @param none
         * @return Returns none
         */

        ~LandBasedTracked(){}

    public:
        //--mutators

        /**
         * @brief it is a setter method for the x-axis
         * @param int x_
         * @return Returns none
         */
        void set_x_(int x_){
            x_ = x_;
        }

        /**
         * @brief it is a setter method for the y-axis
         * @param int y_
         * @return Returns none
         */
        void set_y_(int y_){
            y_ = y_;
        }


        //--accessors

        /**
         * @brief it is a getter method for the x-axis
         * @param none
         * @return Returns int x_
         */
        int get_x_() const{
            return x_;
        }
        /**
         * @brief it is a getter method for the y-axis
         * @param none
         * @return Returns int y_
         */
        int get_y_() const {
            return y_;
        }

    };//--Class LandBasedTracked
}//--namespace fp