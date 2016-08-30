// OctileMap.cpp

#include <iostream>
#include "OctileMap.h"


void OctileMap::GetActions(State &s, vector<Action> &a)
{
    //Check all 8 possible moves
    

    // north -> current location y value must be greater than zero
    //      northwest -> xLoc greater than zero
    //      northeast -> xLoc less than width
    if(s.yLoc > 0 && (myArenaMap->GetCell(s.xLoc, s.yLoc-1) == '.'))
    {
        a.push_back(Action(s.xLoc, s.yLoc-1));
        std::cout << "push" << std::endl;

        // northwest
        if(s.xLoc > 0 && (myArenaMap->GetCell(s.xLoc-1, s.yLoc-1) == '.'))
        {
            a.push_back(Action(s.xLoc-1, s.yLoc-1));
            std::cout << "push" << std::endl;
        }

        // northeast
        if((s.xLoc < myArenaMap->GetWidth()) && (myArenaMap->GetCell(s.xLoc+1, s.yLoc-1) == '.'))
        {
            a.push_back(Action(s.xLoc+1, s.yLoc-1));
            std::cout << "push" << std::endl;
        }
    }

    // south -> current location y value must be less than height - 1
    //      southwest -> xLoc greater than zero
    //      southeast -> xLoc less than width
    if(s.yLoc < (myArenaMap->GetHeight() - 1) && (myArenaMap->GetCell(s.xLoc, s.yLoc+1) == '.'))
    {
        a.push_back(Action(s.xLoc, s.yLoc+1));
        std::cout << "push" << std::endl;

        // northwest
        if(s.xLoc > 0 && (myArenaMap->GetCell(s.xLoc-1, s.yLoc+1) == '.'))
        {
            a.push_back(Action(s.xLoc-1, s.yLoc+1));
            std::cout << "push" << std::endl;
        }
        

        // northeast
        if(s.xLoc < (myArenaMap->GetWidth() - 1) && (myArenaMap->GetCell(s.xLoc+1, s.yLoc+1) == '.'))
        {
            a.push_back(Action(s.xLoc+1, s.yLoc+1));
            std::cout << "push" << std::endl;
        }
    }

    // west
    if(s.xLoc > 0 && (myArenaMap->GetCell(s.xLoc-1, s.yLoc) == '.'))
    {
        a.push_back(Action(s.xLoc-1, s.yLoc));
        std::cout << "push" << std::endl;
    }

    // east
    if(s.xLoc < (myArenaMap->GetWidth() - 1) && (myArenaMap->GetCell(s.xLoc+1, s.yLoc) == '.'))
    {
        a.push_back(Action(s.xLoc+1, s.yLoc));
        std::cout << "push" << std::endl;
    }

}
 
void OctileMap::ApplyAction(State &s, Action &a)
{
    s.xLoc = a.NewNodeToSearch.xLoc;
    s.yLoc = a.NewNodeToSearch.yLoc;

}

void OctileMap::UndoAction(State &s, vector<Action> &a)
{
    //Don't need to do anything
}
