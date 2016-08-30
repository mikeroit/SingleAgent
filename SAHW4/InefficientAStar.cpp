// InefficientAStar.cpp


#include "InefficientAStar.h"

Template <typename State, typename Action, typename Environment>
InefficientAStar::InefficientAStar(Environment e)
{
    myEnvironment = e;
}


int InefficientAStar<State, Action, Environment>::FindBestNextNodeIndex(std::vector &v)
{
    int res = (v[0].GetFCost());

    for(int i = 0; i < v.size(); i++)
    {
        if ((v[i].GetFCost()) < (v[res].GetFCost())){res = i;}
    }
    return res;
}


void InefficientAStar<State, Action, Environment>::Search(State start, State goal)
{
    std::vector<Action> actions = new std::vector<Action>();

    //init lists
    myOpenList = new std::vector<State>();
    myClosedList = new std::vector<State>();
    myNodesExpanded = 0;

    // push start 
    myOpenList.push_back(start);

    while(true)
    {
        actions.clear();
        // expand best node
        int bestNode = FindBestNextIndex();
        myEnvironment->GetActions(myOpenList);


    }
}
