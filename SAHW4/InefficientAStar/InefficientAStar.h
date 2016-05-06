//InefficientAStar.h
//HW4
//Michael Roitman
//  4/27/2016

#include <vector>
#include <stdint.h>
#include <deque>

#ifndef InefficientAStar_h
#define InefficientAStar_h

//-----------------------------------------------------------------------------------
template <typename state, typename action, typename environment, typename heuristic>
class InefficientAStar
{
public:

	//GetPath return if the goal was found
	bool GetPath(environment &e, state &start, state &goal, heuristic &h);

	//GetSolution returns the nodes expanded to get to the solution in previous call of GetPath
	uint64_t GetNodesExpanded();

private:

	//Struct for AStar to use
	struct ANode
	{
		//state
		state myState;

		//gcost, hcost
		int gCost, hCost;

		//fcost --> function
		int fCost()
		{
			return gCost + hCost;
		}
	};
	
	//keep track of nodes expanded
	uint64_t nodesExpanded;
};
//-----------------------------------------------------------------------------------

template <typename state, typename action, typename environment, typename heuristic>
bool InefficientAStar<state, action, environment, heuristic>
		::GetPath(environment &e, state &start, state &goal, heuristic &h)
{
	
	//Init
	nodesExpanded = 0;
	std::deque<ANode> q;
	std::vector<ANode> closedList;
	std::vector<action> moves;

	//init q
	q.push_back(start);

	//A*
	while(!q.empty())
	{
		//store best item
		ANode next = q.front();
		int termToRemove = 0;
		for(int i = 0; i < q.size(); i++)
		{
			ANode node = q[i];

			//check to see if this node is a better node to expand
			if(node.fcost() < next.fcost())
			{
				termToRemove = i;
				next = node;
			}
		}

		//found goal?
		if(next.myState == goal)
		{
			return true;
		}
		
		//check if this exists on closed list
		bool alreadyExpanded = false;
		for(int i = 0; i < closedList.length; i++)
		{
			//if already expanded, check to update gCost
			if(closedList[i].myState == next.myState)
			{
				alreadyExpanded = true;
				closedList[i].gCost = MIN(closedList[i].gCost, next.gCost);
			}
		}

		//if not expanded yet, add to closed list
		if(!alreadyExpanded)
		{
			closedList.push_back(next);	
		}
		
		//get children and add to open list
		e.GetActions(next, moves);
		for(int i = 0; i < moves.length; i++)
		{
			ANode a = moves[i];
			e.ApplyAction(next, a);
			q.push_back(next);
			e.UndoAction(next, a);
		}
	}
}
//-----------------------------------------------------------------------------------
#endif // InefficientAStar_h

