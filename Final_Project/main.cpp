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
*  This is main.cpp file for the project which involves a robot moving in a maze using
*  Depth first search as a path planning algorithm and also used micro-mouse simulator as a
*  visualization tool for both maze and robot. This project is developed using object-oriented
*  programming, inheritance, and polymorphism. Here, two mobile robots are tasked to navigate
*  through a maze to reach Goal from Start.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "src/DFSAlgorithm/dfsalgorithm.h"
#include "src/API/api.h"
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"

int main(){
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>(1, "Husky", 0, 5, 5, 5, 0, 0, 0, 'N');
    fp::dfsalgorithm algo;
    algo.Solve(wheeled);
    std::cout << "Goal Reached" << std::endl;
    return 0;
}