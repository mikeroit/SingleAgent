//
//  created by mikeroit on 4/6/2016.
//Grid.cpp
//
#include <vector>
#include "SlideTile15.h"
#include <cassert>
#include <stdint.h>

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
        //printf("%d\n", ((blankIndex << 4) | (blankIndex - 4)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 4))
        );
    }

    if(canMove(blankIndex, SOUTH)){
        //printf("%d\n", ((blankIndex << 4) | (blankIndex + 4)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 4))
        );
    }

    if(canMove(blankIndex, EAST)){
        //printf("%d\n", ((blankIndex << 4) | (blankIndex - 1)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 1))
        );
    }

    if(canMove(blankIndex, WEST)){
        //printf("%d\n", ((blankIndex << 4) | (blankIndex + 1)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 1))
        );
    }


}

uint64_t swapBits(uint64_t x, uint64_t p1, uint64_t p2, uint64_t n)
{
    uint64_t set1 =  (x >> p1) & ((1U << n) - 1);

    uint64_t set2 =  (x >> p2) & ((1U << n) - 1);

    uint64_t xo = (set1 ^ set2);
    xo = (xo << p1) | (xo << p2);

    uint64_t result = x ^ xo;

    return result;
}

void SlideTile15::ApplyAction(uint64_t &s, uint8_t a) {
    //fetch starting and ending locations
    int startLoc = ((a >> 4) & 0x0f); int endLoc = (a & 0x0f);
    startLoc = 60 - (startLoc * 4); endLoc = 60 - (endLoc * 4);
    //swap values
    unsigned int x =  ((((s >> startLoc) & ((1U << 4) - 1)) ^ ((s >> endLoc) & ((1U << 4) - 1))));
    s = swapBits(s, startLoc, endLoc, 4);

}

void SlideTile15::UndoAction(state &s, uint8_t a){
	ApplyAction(s, a);

}


