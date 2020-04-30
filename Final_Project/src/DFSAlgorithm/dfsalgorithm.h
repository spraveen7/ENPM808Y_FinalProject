/**
* @file dfsalgorithm.h
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
*  This is the header for the class dfsalgorithm, implementing the Depth First Search algorithm
*  in this class and navigating the robot through the maze.
*/

#pragma once
#include <string>
#include<iostream>
#include "../LandBasedWheeled/landbasedwheeled.h"
#include "../LandBasedTracked/landbasedtracked.h"
#include "../API/api.h"
#include <array>
#include "../MazeFiles/mazefile.h"
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <map>


namespace fp{
    class dfsalgorithm {
    public:
        int x_;
        int y_;
        char direction_;
        std::stack<int> stack_x;
        std::stack<int> stack_y;
        std::array<std::array<bool, 16>, 16> visited;

        int IsGoal(int, int);
        void Solve(std::shared_ptr<fp::LandBasedRobot>);
        void FindPath(std::shared_ptr<fp::LandBasedRobot> robot,int x_,int y_);

    };
}