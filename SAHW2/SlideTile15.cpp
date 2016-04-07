//
//  created by mikeroit on 4/6/2016.
//Grid.cpp
//
#include <vector>
#include "SlideTile15.h"
#include <cassert>

using namespace std;

void SlideTile15::GetActions(state &s, std::vector<uint8_t> &actions) {
    //max number of actions: 4
    actions.resize(0);


    //find the blank tile (0-tile) and save index
    int blankIndex = 0;
    for(blankIndex; blankIndex < WIDTH * HEIGHT; blankIndex++){
        if(((s >> (60 - (blankIndex * 4))) & 0x0f) == 0){
            break;
        }

    }

    //check legal moves
    if(canMove(blankIndex, NORTH)) {
        printf("NORTH\n");
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 4))
        );
    }

    if(canMove(blankIndex, SOUTH)){
        printf("SOUTH\n");
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 4))
        );
    }

    if(canMove(blankIndex, EAST)){
        printf("EAST\n");
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 1))
        );
    }

    if(canMove(blankIndex, WEST)){
        printf("WEST\n");
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 1))
        );
    }


}


