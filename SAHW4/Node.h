
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
    myGCost = 0;
        
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


