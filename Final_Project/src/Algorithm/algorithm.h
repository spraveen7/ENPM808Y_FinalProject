//
// Created by Sudo on 5/7/2020.
//

/**
* @file algorithm.h
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
*  This is the header for the class Algorithm, implementing the Depth First Search algorithm
*  in this class and navigating the robot through the maze.
*/


#ifndef FINAL_PROJECT_ALGORITHM_H
#define FINAL_PROJECT_ALGORITHM_H

#include <string>
#include<iostream>
#include "../API/api.h"
#include <map>
#include <stack>
#include <array>
#include <vector>
#include <utility>


namespace fp{
    struct Node {
        int x_, y_, dist_;
        char direction_;
        std::array<int, 2> parent_node_;
        Node(): x_{},y_{}, dist_{}, direction_{}, parent_node_{}{}
        Node(int x, int y, char direction = (char) "") : x_(x), y_(y), direction_(direction), dist_{}, parent_node_{} {}
        ~Node()= default;
    };

    class Algorithm {
    public:
        int height_, width_;
        char current_direction_;
        std::array<int, 2> goal_;
        std::array<int, 2> previous_node_;
        std::array<int, 2> current_node_;
        std::stack<std::array <int,2> > stack_;
        std::stack<std::array<int, 2>> path_stack_;
        std::array<std::array<Node, 16>, 16> node_arr_;
        std::array<std::array<bool, 16>, 16> visited_node_;

    public:
        //---> Constructor 01: Default Constructor <---//
        Algorithm(): height_{16}, width_{16}, current_direction_{'N'}, goal_{}, previous_node_{}, current_node_{}, stack_{}, path_stack_{}, node_arr_{}, visited_node_{} {
            for(int i = 0; i < height_ ; ++i)
                for (int j = 0; j < width_ ; ++j) {
                    node_arr_[i][j] = fp::Node{i, j};
                    visited_node_[i][j] = false;
                }
        }
        //---> Destructor <---//
        ~Algorithm()= default;

        //---> method prototypes <---//

        bool IsVisited(std::array<int, 2> cur_node);

        void FindNeighbours(std::array<int, 2> cur_node);

        void SearchPath(std::array<int, 2> start, std::array<int, 2> goal);

        std::stack<std::array<int, 2>> BackTrack(std::array<int, 2> current_node);

    };
}


#endif //FINAL_PROJECT_ALGORITHM_H
