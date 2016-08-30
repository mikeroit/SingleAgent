// OctileMap.h

#include <vector>
#include "BitMap.h"


struct State
{
    int xLoc;
    int yLoc;
    
    State(){}
    State(int x, int y)
    {
        xLoc = x;
        yLoc = y;
    }
};

struct Action
{
    State NewNodeToSearch;
    Action(int x, int y)
    {
        NewNodeToSearch = State(x, y);
    }
};

class OctileMap
{
    public:
        inline OctileMap(const string fileName);
        void GetActions(State &s, vector<Action> &a);
        void ApplyAction(State &s, Action &a);
        void UndoAction(State &s, vector<Action> &a);

    private:
        BitMap *myArenaMap;
};

OctileMap::OctileMap(const string fileName)
{
    myArenaMap = new BitMap();
    myArenaMap->ReadFromFile(fileName);
}
