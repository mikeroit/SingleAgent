//
// Created by mikeroit on 4/6/2016.
//

#ifndef SlideTile15_h
#define SlideTile15_h

#include <stdio.h>
#include <vector>
#include <stdint.h>

enum gridAction {
    Up,
    Right,
    Down,
    Left

};

struct coordinate {
    int x, y;
};

bool operator==(const coordinate &c1, const coordinate &c2);

class Grid {
public:
    Grid(int w);
    void GetActions(coordinate &nodeID, std::vector<gridAction> &actions);
    void ApplyAction(coordinate &s, gridAction a);
    void UndoAction(coordinate &s, gridAction a);
private:
    const size_t WIDTH = 4;

};


#endif /* Grid_h */
