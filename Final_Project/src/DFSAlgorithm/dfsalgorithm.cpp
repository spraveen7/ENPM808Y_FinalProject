/**
* @file dfsalgorithm.cpp
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
*  This is the cpp for the class dfsalgorithm, implementing the Depth First Search algorithm
*  in this class and navigating the robot through the maze.
*/

#include "dfsalgorithm.h"
#include "../MazeFiles/mazefile.h"
#include "../API/api.h"
#include <stack>
#include <array>
#include <vector>
#include <string>
#include<iostream>
#include<memory.h>

bool fp::DFSAlgorithm::IsGoal(int x_, int y_) {
    if((x_ == 7 && y_ == 7) || (x_ == 8 && y_ == 8) || (x_ == 7 && y_ == 8) || (x_ == 8 && y_ == 7))
        std::cout << "Goal Reached";
        return true;
    return false;
}

// Implementing the Depth First Search Algorithm.
void fp::DFSAlgorithm::Solve(std::shared_ptr<fp::LandBasedRobot> robot){

    if(fp::DFSAlgorithm::IsGoal(x, y))
    {
        while (!stack_y.empty())
        {
            fp::api::setColor(stack_x.top(), stack_y.top(), 'G');
            stack_y.pop();
            stack_x.pop();
        }
        return;
    }

    maze.ReadMazeFile(x,y,direction);


    // Check South Direction
    if((maze.ReadMazeFile(x, y, direction) == false)&&(visited[x][y-1]==0)&&(y>0))
    {
        stack_y.push(y-1);
        stack_x.push(x);
        fp::DFSAlgorithm::FindPath(robot,y-1,x);
        visited[x][y-1]=true;
        y=y-1;
        x=x;
        direction='S';
        fp::DFSAlgorithm::Solve(robot);
    }

    // Check East Direction.
    else if((maze.ReadMazeFile(x, y, direction) == false)&&(visited[x+1][y]==0)&&(x<15))
    {

        stack_y.push(y);
        stack_x.push(x+1);
        fp::DFSAlgorithm::FindPath(robot,y,x+1);
        visited[x+1][y]=true;
        y=y;
        x=x+1;
        direction='E';
        fp::DFSAlgorithm::Solve(robot);
    }
        // Check North Direction.
    else if((maze.ReadMazeFile(x, y, direction) == false)&&(visited[x][y+1]==0)&&(y<15))
    {

        stack_y.push(y+1);
        stack_x.push(x);
        fp::DFSAlgorithm::FindPath(robot,y+1,x);
        visited[x][y+1]=true;
        y=y+1;
        x=x;
        direction='N';
        fp::DFSAlgorithm::Solve(robot);
    }
        // Check West Direction.
    else if((maze.ReadMazeFile(x, y, direction) == false)&&(visited[x-1][y]==0)&&(x>0))
    {

        stack_y.push(y);
        stack_x.push(x-1);
        fp::DFSAlgorithm::FindPath(robot,y,x-1);
        visited[x-1][y]=true;
        y=y;
        x=x-1;
        direction='W';
        fp::DFSAlgorithm::Solve(robot);
    }
        // Clear and update the wheeled coordinates.
    else
    {
        stack_y.pop();
        stack_x.pop();
        fp::DFSAlgorithm::FindPath(robot,stack_y.top(),stack_x.top());
        y=stack_y.top();
        x=stack_x.top();
        direction=robot->GetDirection();
        fp::DFSAlgorithm::Solve(robot);
    }
}
// Moving the wheeled through the maze.
void fp::DFSAlgorithm::FindPath(std::shared_ptr<fp::LandBasedRobot> wheeled,int y,int x)
{

    int node_x=wheeled->get_x_();
    int node_y=wheeled->get_y_();
    int node_direction=wheeled->GetDirection();
    fp::api::setColor(wheeled->get_x_(),wheeled->get_y_(),'G');
    if(!((node_y==y)&&(node_x==x)))
    {
        //Movement in North direction.
        if(y>node_y)

        {
            if(node_direction=='N')
            {wheeled->MoveForward();}
            if(node_direction=='E')
            {  wheeled->TurnLeft();
                wheeled->MoveForward();}
            if(node_direction=='W')
            {  wheeled->TurnRight();
                wheeled->MoveForward();}
            if(node_direction=='S')
            {  wheeled->TurnRight();
                wheeled->TurnRight();
                wheeled->MoveForward();}
        }
        //Movement in South Direction.
        if(y<node_y)

        {
            if(node_direction=='S')
            {wheeled->MoveForward();}
            if(node_direction=='W')
            {  wheeled->TurnLeft();
                wheeled->MoveForward();}
            if(node_direction=='E')
            {  wheeled->TurnRight();
                wheeled->MoveForward();}
            if(node_direction=='N')
            {  wheeled->TurnRight();
                wheeled->TurnRight();
                wheeled->MoveForward();}
        }
        //Movement in East Direction.
        if(x>node_x)

        {
            if(node_direction=='E')
            {wheeled->MoveForward();}
            if(node_direction=='S')
            {  wheeled->TurnLeft();
                wheeled->MoveForward();}
            if(node_direction=='N')
            {  wheeled->TurnRight();
                wheeled->MoveForward();}
            if(node_direction=='W')
            {  wheeled->TurnRight();
                wheeled->TurnRight();
                wheeled->MoveForward();}
        }
        //Movement in West Direction.
        if(x<node_x)
        {
            if(node_direction=='W')
            {wheeled->MoveForward();}
            if(node_direction=='N')
            {  wheeled->TurnLeft();
                wheeled->MoveForward();}
            if(node_direction=='S')
            {  wheeled->TurnRight();
                wheeled->MoveForward();}
            if(node_direction=='E')
            {  wheeled->TurnLeft();
                wheeled->TurnLeft();
                wheeled->MoveForward();}
        }
    }

}

