#include <iostream>
#include "SlideTile15.h"
#include <vector>
#include "BFS.h"
#include "m_dist.h"

using namespace std;

int main() {



    state board;
    board.myState = 0x1023456789abcdef;
    state goal;
    goal.myState = 0x0123456789ABCDEF;

    SlideTile15 st;
    BFS<state , action, SlideTile15> myBFS;
    if (myBFS.GetPath(st, board, goal))
        std::cout << "Goal found!\n";
    else
        std::cout << "Goal not found!\n";
    std::cout << myBFS.GetNodesExpanded() << " total nodes expanded\n";


    return 0;
}