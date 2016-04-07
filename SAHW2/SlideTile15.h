//
// Created by mikeroit on 4/6/2016.
//

#ifndef SLIDETILE15_H
#define SLIDETILE15_H

#include <stdio.h>
#include <vector>
#include <stdint.h>

using namespace std;

typedef uint64_t state;

enum cardinal{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

class SlideTile15 {
public:


    SlideTile15(){}
    void GetActions(state &s, std::vector<uint8_t> &actions);
    //void ApplyAction(coordinate &s, gridAction a);
    //void UndoAction(coordinate &s, gridAction a);
private:
    const size_t WIDTH = 4;
    const size_t HEIGHT = 4;

    bool canMove(int ti, cardinal direction) {
        switch (direction) {
            case NORTH:
                return (ti - 4 >= 0);
            case SOUTH:
                return (ti + 4 < 16);
            case EAST:
                return ( (ti / WIDTH) == ((ti - 1) / WIDTH) );
            case WEST:
                return ( (ti / WIDTH) == ((ti + 1) / WIDTH) );
        }
    }
};


#endif /* SlideTile15_h */
