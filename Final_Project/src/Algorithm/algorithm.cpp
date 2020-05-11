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
*  This is implementation of Maze solver and Depth first search algorithm.
*/

#include "algorithm.h"
#include "../API/api.h"
#include "../Maze/maze.h"

/**
 * @brief clear the stack
 * @param none
 * @return none
 */
void fp::Algorithm::ClearStack() {
    while(!this->stack_.empty()) this->stack_.pop();
}

/**
 * @brief takes a node as input and return true if the node visited or else false
 * @param std::array<int, 2> cur_node
 * @return Returns int
 */
bool fp::Algorithm ::IsVisited(std::array<int, 2> cur_node){
    return this->visited_node_.at(cur_node.at(0)).at(cur_node.at(1));
}

/**
 * @brief takes a node as input and return true if the node explored or else false
 * @param std::array<int, 2> cur_node
 * @return Returns int
 */
bool fp::Algorithm ::IsExplored(std::array<int, 2> cur_node){
    return this->explored_node_.at(cur_node.at(0)).at(cur_node.at(1));
}

/**
 * @brief finds the neighbouring nodes of a given input node and add the found neighbours to the stack
 * @param std::array<int, 2> cur_node
 * @return none
 */
void fp::Algorithm::FindNeighbours(std::array<int, 2> cur_node) {
    std::array<int, 2> node_N{}, node_W{}, node_S{}, node_E{};

    /* ---> Neighbour in South <--- */
    node_S[0] = cur_node[0] + 1;
    node_S[1] = cur_node[1];
    if (node_S[0] <= 15)
        if(!IsExplored(node_S) && !this->maze_info.South_[cur_node[0]][cur_node[1]]) {
            this->stack_.push(node_S);
            if(!IsVisited(node_S)) this->node_master_[node_S[0]][node_S[1]].parent_node_ = cur_node;
            this->node_info[node_S[0]][node_S[1]].parent_node_ = cur_node;

            if (node_S == this->goal1_) return;
            else if (node_S == this->goal2_) return;
            else if (node_S == this->goal3_) return;
            else if (node_S == this->goal4_) return;
        }

    /* ---> Neighbour in East <--- */
    node_E[0] = cur_node[0];
    node_E[1] = cur_node[1] + 1;
    if (node_E[1] <= 15)
        if(!IsExplored(node_E) && !this->maze_info.East_[cur_node[0]][cur_node[1]]) {
            this->stack_.push(node_E);
            if(!IsVisited(node_E)) this->node_master_[node_E[0]][node_E[1]].parent_node_ = cur_node;
            this->node_info[node_E[0]][node_E[1]].parent_node_ = cur_node;

            if (node_E == this->goal1_) return;
            else if (node_E == this->goal2_) return;
            else if (node_E == this->goal3_) return;
            else if (node_E == this->goal4_) return;
        }

    /* ---> Neighbour in North <--- */
    node_N[0] = cur_node[0] - 1;
    node_N[1] = cur_node[1];
    if (node_N[0] >= 0)
        if(!IsExplored(node_N) && !this->maze_info.North_[cur_node[0]][cur_node[1]]) {
            this->stack_.push(node_N);
            if(!IsVisited(node_N)) this->node_master_[node_N[0]][node_N[1]].parent_node_ = cur_node;
            this->node_info[node_N[0]][node_N[1]].parent_node_ = cur_node;

            if (node_N == this->goal1_) return;
            else if (node_N == this->goal2_) return;
            else if (node_N == this->goal3_) return;
            else if (node_N == this->goal4_) return;
        }

    /* ---> Neighbour in West <--- */
    node_W[0] = cur_node[0];
    node_W[1] = cur_node[1] - 1;
    if (node_W[1] >= 0)
        if(!IsExplored(node_W) && !this->maze_info.West_[cur_node[0]][cur_node[1]]) {
            this->stack_.push(node_W);
            if(!IsVisited(node_W)) this->node_master_[node_W[0]][node_W[1]].parent_node_ = cur_node;
            this->node_info[node_W[0]][node_W[1]].parent_node_ = cur_node;

            if (node_W == this->goal1_) return;
            else if (node_W == this->goal2_) return;
            else if (node_W == this->goal3_) return;
            else if (node_W == this->goal4_) return;
        }
}

/**
 * @brief takes start and goal nodes and implements Depth First Search algorithm
 * @param std::array<int, 2> start
 * @param std::array<int, 2> goal
 * @return none
 */
bool fp::Algorithm::DFSAlgorithm(std::array<int, 2> start) {
    //---> Reset Stack and exploration History <---//
    this->ClearStack();
    this->explored_node_={};

    /* ---> Step 01: Add start to node <--- */
    this->stack_.push(start);
    /* ---> Step 02: Initialize and assign parent node to start node <--- */
    this->node_info = std::array<std::array<Node, 16>, 16>();
    this->node_info[start[0]][start[1]].parent_node_ = start;
    /* ---> Step 03: loop until stack_ exhausts <--- */
    while(!this->stack_.empty()) {
        /* ---> Step 04: Set Current Node <--- */
        this->current_node_ = stack_.top();                                                                   //--> Set the top last-in node as current node
        this->stack_.pop();                                                                                   //--> Pop/remove the last element from the stack
        /* ---> Step 05: check IsGoal <--- */
        if (this->current_node_ == this->goal1_) {
            this->end_goal_ = this->goal1_;
            return true;
        }
        else if (this->current_node_ == this->goal2_) {
            this->end_goal_ = this->goal2_;
            return true;
        }
        else if (this->current_node_ == this->goal3_) {
            this->end_goal_ = this->goal3_;
            return true;
        }
        else if (this->current_node_ == this->goal4_) {
            this->end_goal_ = this->goal4_;
            return true;
        }
        /* ---> Step 06: Check Visited <--- */
        else if (!IsVisited(this->current_node_) || !IsExplored(this->current_node_))
            FindNeighbours(this->current_node_);
        /* ---> Step 07: Mark visited <--- */
        this->visited_node_[current_node_[0]][current_node_[1]] = true;
        this->explored_node_[current_node_[0]][current_node_[1]] = true;
    }
    return false;
}

/**
 * @brief Back track to the start node from a given node
 * @param std::array<int, 2> start
 * @return Returns std::stack<std::array<int, 2>>
 */
std::stack<std::array<int, 2>> fp::Algorithm::BackTrack(std::array<int, 2> current_node, std::array<std::array<Node, 16>, 16>& node) {
    std::array<int, 2> parent_node  = node[current_node[0]][current_node[1]].parent_node_;
    this->path_stack_.push(current_node);
    while (!(current_node == parent_node)) {
        current_node = parent_node;
        parent_node = node[current_node[0]][current_node[1]].parent_node_;
        this->path_stack_.push(current_node);
    }
    return this->path_stack_;
}

/**
 * @brief Maze solver algorithm using given search algorithm
 * @param std::array<int, 2> start
 * @return Returns std::stack<std::array<int, 2>>
 */
void fp::Algorithm::Solve(const std::shared_ptr<fp::LandBasedRobot>& robot) {
    bool path = false;
    this->robot = robot;
    char curr_direction{};
    std::array<int,2> curr_node{};
    std::array<int,2> next_node{};
    std::stack<std::array<int, 2>> local_path;

    curr_direction = robot->get_direction_();
    curr_node = {robot->get_x_(), robot->get_y_()};
    this->node_master_[curr_node[0]][curr_node[1]].parent_node_ = curr_node;
    this->node_master_[curr_node[0]][curr_node[1]].direction_ = curr_direction;

    while(true){
        //---> Step 01: Clear all tile color <---//
        fp::API::clearAllColor();
        //---> Step 02: Get robot current cell info <---//
        curr_direction = robot->get_direction_();
        curr_node = {robot->get_x_(), robot->get_y_()};
        //---> Step 03: Check for goal <---//
        if (curr_node == this->goal1_) return;
        else if (curr_node == this->goal2_) return;
        else if (curr_node == this->goal3_) return;
        else if (curr_node == this->goal4_) return;
        //---> Step 04: Read walls around the robot <---//
        this->maze_info.ReadMaze(curr_node, curr_direction);
        //---> Step 05: Generate Path using DFS Algorithm <---//
        path = this->DFSAlgorithm(curr_node);
        if(!path) return;
        //---> Step 06: BackTrack the current path <---//
        local_path = this->BackTrack(this->end_goal_, this->node_info);
        //---> Step 07: Navigate to next node <---//
        this->Navigate(local_path);
    }
    std::cout<<"Path Doesn't Exist";
}

/**
 * @brief Maze solver algorithm using given search algorithm
 * @param std::array<int, 2> start
 * @return Returns std::stack<std::array<int, 2>>
 */
void fp::Algorithm::Navigate(std::stack<std::array<int, 2>>& local_path) {
    int x{},y{};
    char curr_direction{};
    char direction_togo{};
    std::array<int, 2> node_curr{}, node_next{};

    //---> Step 01: Extract the current Node and Next Node <---//
    node_curr = local_path.top();
    local_path.pop();
    node_next = local_path.top();
    local_path.pop();

    //---> Step 02: Compute the togo direction <---//
    x = node_next[0] - node_curr[0];
    y = node_next[1] - node_curr[1];
    curr_direction = this->robot->get_direction_();

    if(x==-1 && y == 0) direction_togo = 'N';
    else if(x == 1 && y == 0) direction_togo = 'S';
    else if(x == 0 && y ==-1) direction_togo = 'W';
    else if(x == 0 && y == 1) direction_togo = 'E';

    //---> Step 03: Navigate the Robot and update new location and direction info <---//
    if(curr_direction =='N'){
        if(direction_togo == 'N') {
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'S') {
            fp::API::turnLeft();
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'E') {
            fp::API::turnRight();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'W') {
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
    }
    else if(curr_direction =='S') {
        if(direction_togo == 'N') {
            fp::API::turnLeft();
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'S') {
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'E') {
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'W') {
            fp::API::turnRight();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
    }
    else if(curr_direction =='E') {
        if(direction_togo == 'N') {
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'S') {
            fp::API::turnRight();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'E') {
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'W') {
            fp::API::turnLeft();
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
    }
    else if(curr_direction =='W') {
        if(direction_togo == 'N') {
            fp::API::turnRight();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'S') {
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'E') {
            fp::API::turnLeft();
            fp::API::turnLeft();
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
        else if(direction_togo == 'W') {
            fp::API::moveForward();
            this->robot->set_x_(node_next[0]);
            this->robot->set_y_(node_next[1]);
            this->robot->set_direction_(direction_togo);
        }
    }
}

