/**
* @file dfsalgorithm.h
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
#include <memory>

namespace fp
{

    class DFSAlgorithm
    {
    private:

        fp::MazeFile maze;
        int x ;
        int y ;
        char direction  = 'N';
        std::stack<int> stack_x;
        std::stack<int> stack_y;
        std::array<std::array<int, 16>, 16> visited;


    public:
        /**
        * @brief This is a no parameter constructor of Algorithm class.
        * It is used to initialize the required stacks and arrays.
        * @param none
        * @return none
        */
        DFSAlgorithm(){
            y =0;
            x=0;
            direction = 'N';
            visited={0};
            visited[y][x]= 1;
            stack_y.push(y);
            stack_x.push(x);

        }
        /**
        * @brief -This is a boolean function to check if the Goal is reached.
        * @param x-coordinate of the robot.
        * @param y-coordinate of the robot.
        * @return It returns True if the goal is reached and False otherwise.
        */
        bool IsGoal(int, int);

        /**
        * @brief This is a function that implements Depth First Search Algorithm.
        * @param Shared pointer to the robot class.
        * @return none
        */
        void Solve(std::shared_ptr<fp::LandBasedRobot>);
        /**
        * @brief This function is used to move the robot through the maze.
        * @param Shared pointer to the robot class.
        * @param Robot x-coordinate.
        * @param Robot y- coordinate.
        * @return none
        */
        void FindPath(std::shared_ptr<fp::LandBasedRobot> robot,int y,int x);

    };

}
