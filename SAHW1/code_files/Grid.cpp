//
//Created by mikeroit on 3/29/2016.
//

#include <stdint.h>
#include "Grid.h"

//Constructors generic- implemented in "Grid.h"

//-------------------------------------------------------------------------
//Public Methods:

void Grid::GetActions(uint32_t &nodeID, std::vector<uint32_t> &actions){

//  fetch x and y coord of current state
    uint32_t x, y;
    x = getX(nodeID);
    y = getY(nodeID);

//  test to see if moving up/right is legal, add legal moves
    if(x + 1 < sideLen){
        actions.push_back( ((x + 1) << 16) | y );
    }
    if((y + 1) < sideLen){
        actions.push_back(nodeID + 1);
    }
}

void Grid::ApplyAction(uint32_t &state, int action){
    state += action;
}

void Grid::UndoAction(uint32_t &state, int action){
    state -= action;
}

//-------------------------------------------------------------------------

//Private methods:

//Converts ID to x coord
int Grid::getX(uint32_t &nodeID){
    return (nodeID >> 16);
}

//Converts ID to y coord
int Grid::getY(uint32_t &nodeID){
    return (nodeID & 0x0000ffff);
}

