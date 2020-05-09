/**
* @file landbasedtracked.h
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
*  This is main.cpp file for the project which involves a robot moving in a maze using
*  Depth first search as a path planning algorithm and also used micro-mouse simulator as a
*  visualization tool for both maze and robot. This project is developed using object-oriented
*  programming, inheritance, and polymorphism. Here, two mobile robots are tasked to navigate
*  through a maze to reach Goal from Start.
*/

#include "src/Algorithm/algorithm.h"
#include "src/API/api.h"
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"

void FollowActionPath(const std::shared_ptr<fp::LandBasedRobot>& robot,
                      const std::vector<std::string> &vec, const std::string& obj);
//--Implementation
void FollowActionPath(const std::shared_ptr<fp::LandBasedRobot>& robot,
                      const std::vector<std::string> &vec, const std::string& obj){

    int x{robot->get_x_()};                             //--should be 1 for wheeled and 2 for tracked
    int y{robot->get_y_()};                             //--should be 4 for wheeled and 3 for tracked

    for (const auto& s: vec){
        if (s=="forward")
            robot->MoveForward(x,y);
        else if (s=="right")
            robot->TurnRight(x,y);
        else if (s=="left")
            robot->TurnLeft(x,y);
        else if (s=="pickup")
            robot->PickUp(obj);
        else if (s=="release")
            robot->Release(obj);
    }
}

int main(){
    std::cout << "\n--------------------------------------------------------------------\n";
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky",1,4);
    std::vector<std::string> action_path_wheeled {"forward","pickup","left","right","release"};
    FollowActionPath(wheeled,action_path_wheeled,"book");
    std::cout << "--------------------------------------------------------------------\n";

    std::shared_ptr<fp::LandBasedRobot> tracked = std::make_shared<fp::LandBasedTracked>("LT2-F",2,3);
    std::vector<std::string> action_path_tracked {"forward","pickup","left","right","release"};
    FollowActionPath(tracked,action_path_tracked,"cube");
    std::cout << "--------------------------------------------------------------------\n";
    
    return 0;
}