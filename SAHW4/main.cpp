// main.cpp

#include <stdio.h>
#include <iostream>
#include "OctileMap.h"
//#include "InefficientAStar.h"
#include "BinHeap.h"
//#include "Node.h"

using namespace std;

bool TestDecode()
{
    BitMap bm;
    bm.SetWidth(4); bm.SetHeight(20);
    Point p = Point(0, 0);

    bm.DecodeMapIndex(8, p);

    std::cout << p.xLoc << ", " << p.yLoc << std::endl;

    return true;

}

bool TestEncode()
{
    BitMap bm;
    bm.SetWidth(4); bm.SetHeight(20);
    Point p = Point(0, 0); 

    bm.DecodeMapIndex(20, p);

    return bm.EncodeMapPosition(p) == 20; 
}

bool TestBitMapConstructor()
{
    BitMap *bm = new BitMap(8, 6);

    return
        bm -> GetHeight() == 8 && bm -> GetWidth() == 6;

}

bool TestReadFromFile()
{
    BitMap *bm = new BitMap();
    bm -> ReadFromFile("./res/arena.map");

    for(int i = 0; i < bm->GetHeight(); i++)
    {
        for(int j = 0; j < bm->GetWidth(); j++)
        {
            std::cout << bm -> GetCell(i, j);
        }
        std::cout << std::endl;
    }
    std::cout << "height: " << (bm -> GetHeight()) << std::endl;
    std::cout << "width: " << (bm -> GetWidth()) << std::endl;

    return true;
}

bool TestGetActions()
{
    OctileMap *om = new OctileMap("./res/arena.map");
    vector<Action> v;
    State st = State(3, 1);
    om->GetActions(st, v);
    for (int i = 0; i < v.size(); i++)
    {
        Action ac = v[i];
        std::cout << ac.NewNodeToSearch.xLoc << ", " << ac.NewNodeToSearch.yLoc  << std::endl;
    }
}

bool TestApplyAction()
{
    State s = State(5, 4);
    Action a = Action(6, 5);
    std::cout << "start: "<< std::endl;
    std::cout << s.xLoc << ", " << s.yLoc << std::endl;
    OctileMap *om = new OctileMap("./res/arena.map");
    om->ApplyAction(s, a);

    std::cout << "end: "<< std::endl;
    std::cout << s.xLoc << ", " << s.yLoc << std::endl;
}

bool TestSearch()
{
    //InefficientAStar<State, Action, OctileMap>* searchAlg;

    //searchAlg = new InefficientAStar<State, Action, OctileMap>(OctileMap("./res/den401d.map"));

    //searchAlg->Search(State(7, 7), State(60, 50));

    return true;
}

bool TestBinHeapConstructor()
{
	Node<State>* myNode = new Node<State>();
	BinHeap<State>* myHeap = new BinHeap<State>(myNode);

	return true;
}

bool TestHeapOps()
{
	//Allocate room for 10 nodes
	Node<State>* myNodes = new Node<State>[10];
	
	//Make 10 states
	State* myStates = new State[10];

	//Make 10 nodes
	for(int i = 0; i < 10; i++)
	{
		myStates[i] = State();
		myNodes[i] = Node<State>(myStates[i]);
		myNodes[i].SetGCost(10 - i);
		myNodes[i].SetHCost(10 - i);
	}

	//make a heap
	BinHeap<State> myHeap = BinHeap<State>(&myNodes[0]);

	for(int i = 1; i < 10; i++)
	{
		myHeap.Push(myNodes[i]);
	}


	for(int i = 1; i < 9; i++)
	{
		Node<State>& res = myHeap.Pop();
		std::cout << res.GetFCost() << std::endl;
	}

	return true;
}

int main()
{
    if(TestHeapOps())
    {
        std::cout<< "Passed" << std::endl;
    }
    else std::cout<< "Failed" << std::endl;

    return 0;
}
