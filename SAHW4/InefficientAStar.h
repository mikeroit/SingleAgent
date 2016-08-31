// InefficientAStar.h

#include <iostream>
#include <vector>


// Node class for graph
template <typename State>
class Node
{
    public:
        Node();
        Node(State &s);
        int GetHCost();
        int GetGCost();
        int GetFCost();
        void SetHCost(int h);
        void SetGCost(int g);
        State myState;

    private:
        int myHCost; 
        int myGCost;
};

template <typename State>
Node<State>::Node()
{

}

template <typename State>
Node<State>::Node(State &s)
{
    myState = State(s.xLoc, s.yLoc);
}

template <typename State>
int Node<State>::GetHCost(){return myHCost; }

template <typename State>
int Node<State>::GetGCost(){return myGCost; }

template <typename State>
int Node<State>::GetFCost(){return myGCost + myHCost; }

template <typename State>
void Node<State>::SetHCost(int h){myHCost = h; }

template <typename State>
void Node<State>::SetGCost(int g){myGCost = g; }

// ------------------------------------------------------

template <typename State, typename Action, typename Environment>
class InefficientAStar
{
    public:
        InefficientAStar(){}
        InefficientAStar(Environment e);
        void Search(State start, State goal);

    private:
        Environment myEnvironment;

        std::vector<Node<State> > myOpenList;
        std::vector<Node<State> > myClosedList;

        int myNodesExpanded;

        static int FindBestNextNodeIndex(std::vector<Node<State> > &v)
        {
            int best = (v[0].GetFCost());
            int res = 0;

            for(int i = 0; i < v.size(); i++)
            {
                if ((v[i].GetFCost()) < (v[res].GetFCost())){res = i; best = v[i].GetFCost();}
            }
            return res;
        }

        static bool ListContains(Node<State> node, std::vector<Node<State> > &v)
        {
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i].myState.xLoc == node.myState.xLoc &&
                        v[i].myState.yLoc == node.myState.yLoc)
                {
                    return true;
                }
            }

            return false;
        }
};

template <typename State, typename Action, typename Environment>
InefficientAStar<State, Action, Environment>
::InefficientAStar(Environment e)
{
    myEnvironment = e;
}


template <typename State, typename Action, typename Environment>
void InefficientAStar<State, Action, Environment>::Search(State start, State goal)
{
    std::vector<Action> actions;

    //init lists
    myNodesExpanded = 0;

    // push start 
    myOpenList.push_back(start);

    bool loopBreak = false;
    int gCost = 0;
    while(!loopBreak)
    {
        // expand best node
        Node<State> bestNode = myOpenList[FindBestNextNodeIndex(myOpenList)];
        myClosedList.push_back(Node<State>(bestNode));
        myOpenList.erase(myOpenList.begin() + FindBestNextNodeIndex(myOpenList));
        myEnvironment.GetActions(bestNode.myState, actions);

        for(int i = 0; i < actions.size(); i++ )
        {
            myEnvironment.ApplyAction(bestNode.myState, actions[i]);

            if(bestNode.myState.xLoc == goal.xLoc && bestNode.myState.yLoc == goal.yLoc)
            {
                loopBreak = true;
            }

            bestNode.SetGCost(gCost);
            bestNode.SetHCost(myEnvironment.GenerateHeuristic(bestNode.myState, goal));

            if(! (ListContains(bestNode, myClosedList) || ListContains(bestNode, myOpenList)))
            {
                myOpenList.push_back(Node<State>(bestNode));
                std::cout << bestNode.myState.xLoc << ", " << bestNode.myState.yLoc << std::endl;
                myNodesExpanded++;
            }
            myEnvironment.UndoAction(bestNode.myState, actions[i]);
        }

        gCost++;

    }

    std::cout << "Found Solution in " << myNodesExpanded << " expansions" << std::endl;

}













