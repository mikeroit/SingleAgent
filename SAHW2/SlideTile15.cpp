//
//  created by mikeroit on 4/6/2016.
//Grid.cpp
//

#include "Grid.h"
#include <cassert>

bool operator==(const coordinate &c1, const coordinate &c2)
{
    return c1.x == c2.x && c1.y == c2.y;
}


Grid::Grid(int w)
        :width(w) {}

void Grid::GetActions(coordinate &nodeID, std::vector<gridAction> &actions)
{
    actions.clear();
    if (nodeID.x < width)
        actions.push_back(kRight);
    if (nodeID.y < width)
        actions.push_back(kUp);
}

void Grid::ApplyAction(coordinate &s, gridAction a)
{
    switch (a)
    {
        case kRight: s.x++; break;
        case kUp: s.y++; break;
        default: assert(false);
    }
}

void Grid::UndoAction(coordinate &s, gridAction a)
{
    switch (a)
    {
        case kRight: s.x--; break;
        case kUp: s.y--; break;
        default: assert(false);
    }
}
