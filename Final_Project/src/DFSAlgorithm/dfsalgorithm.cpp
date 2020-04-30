/**
* @file dfsalgorithm.cpp
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
*  This is the cpp for the class dfsalgorithm, implementing the Depth First Search algorithm
*  in this class and navigating the robot through the maze.
*/

#include "dfsalgorithm.h"
#include <stack>
#include <array>
#include <vector>
#include <string>
#include<iostream>

int fp::dfsalgorithm::IsGoal(int x_, int y_) {
    if((x_ == 7 && y_ == 7) || (x_ == 8 && y_ == 8) || (x_ == 7 && y_ == 8) || (x_ == 8 && y_ == 7))
        std::cout << "Goal Reached";
        return 1;
    return 0;
}

void fp::dfsalgorithm::Solve(std::shared_ptr<fp::LandBasedRobot>) {

    if(fp::Algorithm::IsGoal(x_, y_)) == 1
    {
        while (!stack_y.empty())
        {
            fp::api::setColor(stack_y.top(), stack_x.top(), 'Y');
            stack_y.pop();
            stack_x.pop();
        }
        return;
    }
    }
}

void fp::dfsalgorithm::FindPath(std::shared_ptr<fp::LandBasedRobot> robot, int x_, int y_) {

}

