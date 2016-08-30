// InefficientAStar.h

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

    private:
        State myState;
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
    myState = new State(s.xLoc, s.yLoc);
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
//

template <typename State, typename Action, typename Environment>
class InefficientAStar
{
    public:
        InefficientAStar(){}
        InefficientAStar(Environment e);
        void Search(State start, State goal);

    private:
        Environment myEnvironment;

        std::vector<State> myOpenList;
        std::vector<State> myClosedList;

        int myNodesExpanded;

        static int FindBestNextNodeIndex(std::vector<State> &v)
        {
            int res = (v[0].GetFCost());

            for(int i = 0; i < v.size(); i++)
            {
                if ((v[i].GetFCost()) < (v[res].GetFCost())){res = i;}
            }
            return res;
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
    std::vector<Action> actions = new std::vector<Action>();

    //init lists
    myOpenList = new std::vector<Node>();
    myClosedList = new std::vector<Node>();
    myNodesExpanded = 0;

    // push start 
    myOpenList.push_back(start);

    while(true)
    {
        actions.clear();
        // expand best node
        int bestNode = FindBestNextIndex(myOpenList);
        myEnvironment->GetActions(myOpenList[bestNode], actions);

        for(int i = 0; i < )


    }
}
