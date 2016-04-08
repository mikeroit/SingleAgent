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
        printf("%d\n", ((blankIndex << 4) | (blankIndex - 4)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 4))
        );
    }

    if(canMove(blankIndex, SOUTH)){
        printf("%d\n", ((blankIndex << 4) | (blankIndex + 4)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 4))
        );
    }

    if(canMove(blankIndex, EAST)){
        printf("%d\n", ((blankIndex << 4) | (blankIndex - 1)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex - 1))
        );
    }

    if(canMove(blankIndex, WEST)){
        printf("%d\n", ((blankIndex << 4) | (blankIndex + 1)));
        actions.push_back(
                (uint8_t) ((blankIndex << 4) | (blankIndex + 1))
        );
    }


}

void SlideTile15::ApplyAction(state &s, uint8_t a) {

    //fetch starting and ending locations
    int startLoc = ((a >> 4) & 0x0f); int endLoc = (a & 0x0f);
    startLoc = 60 - (startLoc * 4); endLoc = 60 - (endLoc * 4);

    //fetch value at those locations
    uint64_t fetchMask = 0xf000000000000000;

    uint8_t first = (((fetchMask >> (startLoc * 4) & s) >> (60 - (startLoc * 4))));
    uint8_t second = (((fetchMask >> (endLoc) * 4) & s) >> (60 - (endLoc * 4)));

    printf("%d, %d", startLoc, endLoc);

    if(! (first == 0 || second == 0)){
        printf("Can only swap with the blank tile (tile #0)");
    }

    //swap values
    unsigned int x =  ((s >> startLoc) ^ (s >> endLoc)) & ((1U << 4) - 1);
    s = s ^ ((x << startLoc) | (x << endLoc));

}

void SlideTile15::UndoAction(state &s, uint8_t a){
    //fetch starting and ending locations
    int startLoc = ((a >> 4) & 0x0f); int endLoc = (a & 0x0f);

    //fetch value at those locations
    uint64_t fetchMask = 0xf000000000000000;

    uint8_t first = (((fetchMask >> startLoc) & s) >> (60 - (startLoc * 4)));
    uint8_t second = (((fetchMask >> endLoc) & s) >> (60 - (endLoc * 4)));
    if(! (first == 0 || second == 0)){
        printf("Can only swap with the blank tile (tile #0)");
    }

    //swap values
    unsigned int x =  ((s >> startLoc) ^ (s >> endLoc)) & ((1U << 4) - 1);
    s = s ^ ((x << startLoc) | (x << endLoc));
}


