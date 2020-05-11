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

#include <memory>
#include "src/Algorithm/algorithm.h"
#include "src/API/api.h"
#include "src/LandBasedWheeled/landbasedwheeled.h"
#include "src/LandBasedTracked/landbasedtracked.h"


int main(){
    std::array<int, 2> n{};
    std::stack<std::array<int, 2>> path_stack_{};
    std::cout << "\n--------------------------------------------------------------------\n";
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky");
    fp::Algorithm algorithm;
    algorithm.Solve(wheeled);
    path_stack_ = algorithm.BackTrack(algorithm.end_goal_,algorithm.node_master_);
    std::cout << "\n----------------------------> The End <-----------------------------\n";
    int i = 0;
    while(!algorithm.path_stack_.empty()){
        n = algorithm.path_stack_.top();
        std::cout<<i<<": "<<n[0]<<","<<n[1]<<std::endl;
        algorithm.path_stack_.pop();
        i++;
    }


//    bool v = {};
//    algorithm.maze_info.East_[15][0] = true;
//    v = algorithm.DFSAlgorithm({15,0},{8,7});
//    algorithm.BackTrack({8,7}, algorithm.node_info);
//
//    int x = 1;
//    std::array<int,2> n{};
//    while(!algorithm.path_stack_.empty()){
//        n = algorithm.path_stack_.top();
//        std::cout<<""<<n[0]<<","<<n[1]<<std::endl;
//        algorithm.path_stack_.pop();
//    }
//    std::cout<<"North"<<std::endl;
//    for(auto x: algorithm.maze_info.North_){
//        for(auto y: x){
//            std::cout<<y<<"  ";
//        }
//        std::cout<<std::endl;
//    }
//
//    std::cout<<"South"<<std::endl;
//    for(auto x: algorithm.maze_info.South_){
//        for(auto y: x){
//            std::cout<<y<<"  ";
//        }
//        std::cout<<std::endl;
//    }
//    std::cout<<"West"<<std::endl;
//    for(auto x: algorithm.maze_info.West_){
//        for(auto y: x){
//            std::cout<<y<<"  ";
//        }
//        std::cout<<std::endl;
//    }
//
//    std::cout<<"East"<<std::endl;
//    for(auto x: algorithm.maze_info.East_){
//        for(auto y: x){
//            std::cout<<y<<"  ";
//        }
//        std::cout<<std::endl;
//    }


    return 0;
}