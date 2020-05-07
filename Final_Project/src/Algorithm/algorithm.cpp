//
// Created by Sudo on 5/7/2020.
//

#include "algorithm.h"


namespace fp{
    struct Node {
        int x_, y_, dist_;
        char direction_;
        std::array<int, 2> parent_node_;
        Node(){}
        Node(int x, int y, char direction = (char) " ") : x_(x), y_(y), direction_(direction) {}
        ~Node(){}
    };

    class Algorithm {
    public:
        int height, width;
        char current_direction_;
        std::array<int, 2> goal_;
        std::array<int, 2> current_node_;
        std::stack<std::array <int,2> > stack_;
        std::stack<std::array<int, 2>> path_stack_;
        std::array<std::array<Node, 16>, 16> node_arr_;
        std::array<std::array<bool, 16>, 16> visited_node_;

    public:
        Algorithm()
        {
            for(int i = 0; i < 16 ; ++i)
                for (int j = 0; j < 16 ; ++j)
                {
                    node_arr_[i][j] = fp::Node{i, j};
                    visited_node_[i][j] = false;
                }
        }

        bool IsVisited(std::array<int, 2> cur_node)
        {
            return visited_node_.at(cur_node.at(0)).at(cur_node.at(1));
        }

        void FindNeighbours(std::array<int, 2> cur_node)
        {
            std::array<int, 2> node_N{}, node_W{}, node_S{}, node_E{};
            /* ---> Neighbour in North <--- */
            node_N[0] = cur_node[0] - 1;
            node_N[1] = cur_node[1];
            if (node_N[0] >= 0)
                if(!IsVisited(node_N))
                {
                    stack_.push(node_N);
                    node_arr_[node_N[0]][node_N[1]].parent_node_ = cur_node;
                    if (node_N == goal_) return;
                }

            /* ---> Neighbour in West <--- */
            node_W[0] = cur_node[0];
            node_W[1] = cur_node[1] - 1;
            if (node_W[1] >= 0)
                if(!IsVisited(node_W))
                {
                    stack_.push(node_W);
                    node_arr_[node_W[0]][node_W[1]].parent_node_ = cur_node;
                    if (node_N == goal_) return;
                }

            /* ---> Neighbour in South <--- */
            node_S[0] = cur_node[0] + 1;
            node_S[1] = cur_node[1];
            if (node_S[0] <= 15)
                if(!IsVisited(node_S))
                {
                    stack_.push(node_S);
                    node_arr_[node_S[0]][node_S[1]].parent_node_ = cur_node;
                    if (node_N == goal_) return;
                }

            /* ---> Neighbour in East <--- */
            node_E[0] = cur_node[0];
            node_E[1] = cur_node[1] + 1;
            if (node_E[1] <= 15)
                if(!IsVisited(node_E))
                {
                    stack_.push(node_E);
                    node_arr_[node_E[0]][node_E[1]].parent_node_ = cur_node;
                    if (node_N == goal_) return;
                }
        }

        void SearchPath(std::array<int, 2> start, std::array<int, 2> goal)
        {
            /* ---> Step 01: Add start to node <--- */
            stack_.push(start);
            node_arr_[start[0]][start[1]].parent_node_ = start;
            goal_ = goal;
            /* ---> Step 03: loop until stack_ blows <--- */
            while(!stack_.empty())
            {
                /* ---> Step 04: Set Current Node <--- */
                current_node_ = stack_.top();
                stack_.pop();
                /* ---> Step 05: check IsGoal <--- */
                if (current_node_ == goal) break;
                    /* ---> Step 06: Check Visited <--- */
                else if (!IsVisited(current_node_)) FindNeighbours(current_node_);
                /* ---> Step 07: Mark visited <--- */
                visited_node_[current_node_[0]][current_node_[1]] = true;
            }
        }

        std::stack<std::array<int, 2>> BackTrack(std::array<int, 2> current_node)
        {
            std::array<int, 2> parent_node  = node_arr_[current_node[0]][current_node[1]].parent_node_;
            path_stack_.push(current_node);
            while (!(current_node == parent_node))
            {
                current_node = parent_node;
                parent_node = node_arr_[current_node[0]][current_node[1]].parent_node_;
                path_stack_.push(current_node);
            }
        }

    };
}

