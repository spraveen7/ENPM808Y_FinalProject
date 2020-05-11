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
*  This is the header for the class Algorithm, implementing the Depth First Search and maze solver algorithm
*  in this class and navigating the robot through the maze.
*/


#ifndef FINAL_PROJECT_ALGORITHM_H
#define FINAL_PROJECT_ALGORITHM_H

#include <string>
#include<iostream>
#include "../API/api.h"
#include "../LandBasedRobot/landbasedrobot.h"
#include "../Maze/maze.h"
#include <map>
#include <stack>
#include <array>
#include <vector>
#include <utility>
#include <memory>


namespace fp{
    struct Node {
        //---> Attributes <---//
        int x_, y_, dist_;
        char direction_;
        std::array<int, 2> parent_node_;

        //---> Constructor 01: Default constructor <---//
        Node(): x_{},y_{}, dist_{}, direction_{}, parent_node_{}{}

        //---> Constructor 02: Constructor with 3 arguments as input <---//
        Node(int x, int y) :
        x_(x), y_(y), direction_{}, dist_{}, parent_node_{} {}

        //---> Destructors <---//
        ~Node()= default;
    };

    class Algorithm {
    public:
        bool path_found_;
        fp::Maze maze_info;
        int height_, width_;
        char current_direction_;
        std::array<int, 2> goal1_, goal2_, goal3_, goal4_, end_goal_;
        std::array<int, 2> previous_node_;
        std::array<int, 2> current_node_;
        std::stack<std::array <int,2> > stack_;
        std::shared_ptr<fp::LandBasedRobot> robot;
        std::stack<std::array<int, 2>> path_stack_;
        std::array<std::array<Node, 16>, 16> node_info;
        std::array<std::array<Node, 16>, 16> node_master_;
        std::array<std::array<bool, 16>, 16> visited_node_;
        std::array<std::array<bool, 16>, 16> explored_node_;


    public:
        //---> Constructor 01: Default Constructor <---//
        Algorithm(): path_found_{false}, height_{16}, width_{16}, current_direction_{'N'}, goal1_{8,7},
                     goal2_{8,8}, goal3_{7,8}, goal4_{7,7}, end_goal_{},previous_node_{}, current_node_{}, stack_{},
                     path_stack_{}, node_master_{}, visited_node_{}, explored_node_{} {
            for(int i = 0; i < height_ ; ++i)
                for (int j = 0; j < width_ ; ++j) {
                    this->node_master_[i][j] = fp::Node{i, j};
                    this->visited_node_[i][j] = false;
                }
        }
        //---> Destructor <---//
        ~Algorithm()= default;

        //---> method prototypes <---//
        /**
         * @brief takes a node as input and return true if the node visited or else false
         * @param std::array<int, 2> cur_node
         * @return Returns bool
         */
        bool IsVisited(std::array<int, 2> cur_node);

        /**
         * @brief takes a node as input and return true if the node visited or else false
         * @param std::array<int, 2> cur_node
         * @return Returns bool
         */
        bool IsExplored(std::array<int, 2> cur_node);

        /**
         * @brief finds the neighbouring nodes of a given input node and add the found neighbours to the stack
         * @param std::array<int, 2> cur_node
         * @return none
         */
        void FindNeighbours(std::array<int, 2> cur_node);

        /**
         * @brief takes start and goal nodes and implements Depth First Search algorithm
         * @param std::array<int, 2> start
         * @param std::array<int, 2> goal
         * @return none
         */
        bool DFSAlgorithm(std::array<int, 2> start);

        /**
         * @brief Back track to the start node from a given node
         * @param std::array<int, 2> start
         * @return Returns std::stack<std::array<int, 2>>
         */
        std::stack<std::array<int, 2>> BackTrack(std::array<int, 2> current_node, std::array<std::array<Node, 16>, 16>& node);

        /**
         * @brief Maze solver algorithm using given search algorithm
         * @param std::array<int, 2> start
         * @return Returns std::stack<std::array<int, 2>>
         */
        void Solve(const std::shared_ptr<fp::LandBasedRobot>& robot);

        /**
         * @brief Maze solver algorithm using given search algorithm
         * @param std::array<int, 2> start
         * @return Returns std::stack<std::array<int, 2>>
         */
        void Navigate(std::stack<std::array<int, 2>>& path);

        /**
         * @brief clear the stack
         * @param none
         * @return none
         */
        void ClearStack();
    };
}


#endif //FINAL_PROJECT_ALGORITHM_H
