/**
* @file Maze.cpp
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
*  This is the cpp for the class Maze, this is used to read maze files
*  generated by micro-mouse simulator
*/

#include "maze.h"
#include <vector>
#include "../API/api.h"

/**
 * @brief It updates the 'N','S','E','W' 2d array.
 * @param x
 * @param y
 * @param direction
 */
 void fp::Maze::ReadMaze(std::array<int, 2> curr_node, char direction) {
    int x{curr_node[0]},y{curr_node[1]};

    if(direction == 'N'){
        if(API::wallFront()){
            API::setWall(x,15-y,'N');
            this->North_[x][y] = true;
        }
        if(API::wallRight()){
            API::setWall(x,15-y,'E');
            this->East_[x][y] = true;
        }
        if(API::wallLeft()){
            API::setWall(x,15-y,'W');
            this->West_[x][y] = true;
        }
    }
    if(direction == 'E'){
        if(API::wallFront()){
            API::setWall(x,15-y,'E');
            this->East_[x][y] = true;
        }
        if(API::wallRight()){
            API::setWall(x,15-y,'S');
            this->South_[x][y] = true;
        }
        if(API::wallLeft()){
            API::setWall(x,15-y,'N');
            this->North_[x][y] = true;
        }
    }
    if(direction == 'W'){
        if(API::wallFront()){
            API::setWall(x,15-y,'W');
            this->West_[x][y] = true;
        }
        if(API::wallRight()){
            API::setWall(x,15-y,'N');
            this->North_[x][y] = true;
        }
        if(API::wallLeft()){
            API::setWall(x,15-y,'S');
            this->South_[x][y] = true;
        }
    }
    if(direction == 'S'){
        if(API::wallFront()){
            API::setWall(x,15-y,'S');
            this->South_[x][y] = true;
        }
        if(API::wallRight()){
            API::setWall(x,15-y,'W');
            this->West_[x][y] = true;
        }
        if(API::wallLeft()){
            API::setWall(x,15-y,'E');
            this->East_[x][y] = true;
        }
    }
}

/**
 * @brief Adds color to the tiles of the maze grid.
 * @param &X
 * @param &Y
 */
void fp::Maze::ColorPath(std::vector<int> &X, std::vector<int> &Y) {
    for(unsigned int i=0 ; i<X.size() ; i++)
        API::setColor(X[i],Y[i],'b'); //Sets color to the path x,y as blue by calling the API function.
}
