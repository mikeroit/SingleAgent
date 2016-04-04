//
// Created by mikeroit on 4/1/2016.
//

//Roitman Algorithm Library

//Implementations:
//  Breadth-First search
//  Iterative-Deppening Depth-First search

#ifndef HW1_RAL_H
#define HW1_RAL_H

#endif //HW1_RAL_H
#include <iostream>
#include <cstdint>
#include <vector>
#include "simpleQ.h"
#include <algorithm>

using namespace std;

//------------------------------------------   ***   Breadth First   ***   ------------------------------------------
//----------------------------------------------------------------------------------------------
template <typename environment>
class BFS{
public:
//  constructor
    BFS(environment *e, int goal);

private:

//  queues to manage space complexity during pathfinding
    simpleQ<uint32_t>* openList;
    simpleQ<uint32_t>* closedList;

//  total  number of expansions made during previous GetPath call
    uint64_t nodesExpanded;
};
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
BFS<environment>::BFS(environment *e, int goal){

//  initialize open/closed lists, nodesExpanded, start state
    openList = new simpleQ<uint32_t>();
    closedList = new simpleQ<uint32_t>();
    nodesExpanded = 0; openList->Add(0);

//  run BFS algorithm
    uint32_t stateToExpand = 0;
    std::vector<uint32_t> expandedNodes = {};

    while((openList->IsEmpty()) == false){

//      remove head of list and add to closed
        openList->Remove(stateToExpand); nodesExpanded++;
        //openList->Print();
        //cout << endl;
        closedList->Add(stateToExpand);
        if(stateToExpand == goal) break;

//      expand removed node and add children to open
        std::vector<uint32_t> moves = {}; e->GetActions(stateToExpand, moves);
        for(int move : moves){
            if(std::find(expandedNodes.begin(), expandedNodes.end(), move) == expandedNodes.end()){
                openList->Add( move );
                expandedNodes.push_back(move);
            }
        }
    }

    cout << "Found goal after expanding " << nodesExpanded << " nodes (BFS)" << endl;
};
//----------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------


//-------------------------------------------   ***   Depth First   ***   -------------------------------------------

//----------------------------------------------------------------------------------------------
//Depth - First iterative deepening algorithm
template <typename environment>
class DFID{
public:
//  constructor
    DFID(environment *e, uint32_t goal);

private:

    void DLS(environment *e, uint32_t state, uint32_t goal, int depth, bool &found);

//  queues to manage space complexity during pathfinding
    simpleQ<uint32_t>* depthStack;


//  total  number of expansions made during previous GetPath call
    uint64_t nodesExpanded;
};

//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
DFID<environment>::DFID(environment *e, uint32_t goal){

    nodesExpanded = 0;
    int x = 1;
    bool found = false;
    uint32_t temp = 0;
    while(!found){
        DLS(e, 0, goal, x, found);
        x++;
    }

    cout << "Found goal after expanding " << nodesExpanded << " nodes (DFID)" << endl;

}
//----------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
template <typename environment>
void DFID<environment>::DLS(environment *e, uint32_t state, uint32_t goal, int depth, bool &found){
    uint32_t stateX = (state >> 16);
    uint32_t stateY = (state & 0x0000ffff);
    nodesExpanded++;

    if(depth <= 0 || state == goal){
        if(state == goal){
            found = true;
        }
        return;


    }
    else if(depth > 0){


        std::vector<uint32_t> moves = {};
        e->GetActions(state, moves);

        for(int move: moves){
            DLS( e, move, goal, depth-1, found);
            if(found == true) {
                return;
            }
        }
    }
}

//----------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------




















