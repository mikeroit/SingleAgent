#include <iostream>
#include "SlideTile15.h"
#include <vector>
#include "BFS.h"
#include "m_dist.h"

using namespace std;

int main() {



    uint64_t board = 0x1023456789ABCDEF;
    uint64_t goal = 0x0123456789ABCDEF;

    m_dist manhattan;
    printf("%d", manhattan.getManDist(board));
/*
    SlideTile15 st;
    BFS<uint64_t , uint8_t, SlideTile15> myBFS;
    if (myBFS.GetPath(st, board, goal))
        std::cout << "Goal found!\n";
    else
        std::cout << "Goal not found!\n";
    std::cout << myBFS.GetNodesExpanded() << " total nodes expanded\n";
*/

    return 0;
}