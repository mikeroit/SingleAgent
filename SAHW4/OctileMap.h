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
    State NodeToSearchFrom;
    State NewNodeToSearch;
    Action(int x, int y)
    {
        NewNodeToSearch = State(x, y);
        NodeToSearchFrom = State(0, 0);
    }
    
    Action(int x, int y, int x2, int y2)
    {
        NewNodeToSearch = State(x, y);
        NodeToSearchFrom = State(x2, y2);
    }
};

class OctileMap
{
    public:
        OctileMap(){}
        inline OctileMap(const string fileName);
        void GetActions(State &s, vector<Action> &a);
        void ApplyAction(State &s, Action &a);
        void UndoAction(State &s, Action &a);
        int GenerateHeuristic(State &s, State &g);

    private:
        BitMap *myArenaMap;
};

OctileMap::OctileMap(const string fileName)
{
    myArenaMap = new BitMap();
    myArenaMap->ReadFromFile(fileName);
}
