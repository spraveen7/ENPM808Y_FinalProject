/**
* @file algorithm.cpp
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

#include "algorithm.h"


bool fp::Algorithm ::IsVisited(std::array<int, 2> cur_node){
    return visited_node_.at(cur_node.at(0)).at(cur_node.at(1));
}

void fp::Algorithm::FindNeighbours(std::array<int, 2> cur_node) {

    std::array<int, 2> node_N{}, node_W{}, node_S{}, node_E{};

    /* ---> Neighbour in North <--- */
    node_N[0] = cur_node[0] - 1;
    node_N[1] = cur_node[1];
    if (node_N[0] >= 0)
        if(!IsVisited(node_N)) {
            stack_.push(node_N);
            node_arr_[node_N[0]][node_N[1]].parent_node_ = cur_node;
            if (node_N == goal_) return;
        }

    /* ---> Neighbour in West <--- */
    node_W[0] = cur_node[0];
    node_W[1] = cur_node[1] - 1;
    if (node_W[1] >= 0)
        if(!IsVisited(node_W)) {
            stack_.push(node_W);
            node_arr_[node_W[0]][node_W[1]].parent_node_ = cur_node;
            if (node_N == goal_) return;
        }

    /* ---> Neighbour in South <--- */
    node_S[0] = cur_node[0] + 1;
    node_S[1] = cur_node[1];
    if (node_S[0] <= 15)
        if(!IsVisited(node_S)) {
            stack_.push(node_S);
            node_arr_[node_S[0]][node_S[1]].parent_node_ = cur_node;
            if (node_N == goal_) return;
        }

    /* ---> Neighbour in East <--- */
    node_E[0] = cur_node[0];
    node_E[1] = cur_node[1] + 1;
    if (node_E[1] <= 15)
        if(!IsVisited(node_E)) {
            stack_.push(node_E);
            node_arr_[node_E[0]][node_E[1]].parent_node_ = cur_node;
            if (node_N == goal_) return;
        }
}

void fp::Algorithm::SearchPath(std::array<int, 2> start, std::array<int, 2> goal) {
    /* ---> Step 01: Add start to node <--- */
    stack_.push(start);
    node_arr_[start[0]][start[1]].parent_node_ = start;
    goal_ = goal;
    /* ---> Step 03: loop until stack_ blows <--- */
    while(!stack_.empty()) {
        /* ---> Step 04: Set Current Node <--- */
        current_node_ = stack_.top();                                                                   //--> Set the top last-in node as current node
        stack_.pop();                                                                                   //--> Pop/remove the last element from the stack
        /* ---> Step 05: check IsGoal <--- */
        if (current_node_ == goal) break;
            /* ---> Step 06: Check Visited <--- */
        else if (!IsVisited(current_node_)) FindNeighbours(current_node_);
        /* ---> Step 07: Mark visited <--- */
        visited_node_[current_node_[0]][current_node_[1]] = true;
    }
}

std::stack<std::array<int, 2>> fp::Algorithm::BackTrack(std::array<int, 2> current_node) {
    std::array<int, 2> parent_node  = node_arr_[current_node[0]][current_node[1]].parent_node_;
    path_stack_.push(current_node);
    while (!(current_node == parent_node)) {
        current_node = parent_node;
        parent_node = node_arr_[current_node[0]][current_node[1]].parent_node_;
        path_stack_.push(current_node);
    }
}
