//
//  BFS.h
//  HW #1
//
//  Created by Nathan Sturtevant on 4/6/16.
//  Copyright Â© 2016 NS Software. All rights reserved.
//

#ifndef BFS_h
#define BFS_h
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <deque>

template <typename state, typename action, typename environment>
class BFS
{
public:
    // GetPath returns if the goal was found
    bool GetPath(environment &e, state &start, state &goal);
    // Returns the total nodes expanded by the last GetPath call.
    uint64_t GetNodesExpanded();
private:
    bool BoundedDFS(environment &e, state &s, int depth);
    uint64_t nodesExpanded;
    int currentBound;
    state g;
};


template <typename state, typename action, typename environment>
bool BFS<state, action, environment>::GetPath(environment &e, state &start, state &goal)
{
    nodesExpanded = 0;
    std::deque<state> q;
    std::vector<action> moves;

    q.push_back(start);
    while (!q.empty())
    {
        state next = q.front();
        q.pop_front();
        if (next == goal)
            return true;

        e.GetActions(next, moves);
        nodesExpanded++;
        for (auto a : moves)
        {
            printf("%X",a);
            e.ApplyAction(next, a);
            q.push_back(next);
            e.UndoAction(next, a);
        }
    }
    return false;
}

template <typename state, typename action, typename environment>
uint64_t BFS<state, action, environment>::GetNodesExpanded()
{
    return nodesExpanded;
}



#endif /* BFS_h */
//
//  BFS.h
//  HW #1
//
//  Created by Nathan Sturtevant on 4/6/16.
//  Copyright Â© 2016 NS Software. All rights reserved.
//

#ifndef BFS_h
#define BFS_h
#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <vector>
#include <deque>

template <typename state, typename action, typename environment>
class BFS
{
public:
	// GetPath returns if the goal was found
	bool GetPath(environment &e, state &start, state &goal);
	// Returns the total nodes expanded by the last GetPath call.
	uint64_t GetNodesExpanded();
private:
	bool BoundedDFS(environment &e, state &s, int depth);
	uint64_t nodesExpanded;
	int currentBound;
	state g;
};


template <typename state, typename action, typename environment>
bool BFS<state, action, environment>::GetPath(environment &e, state &start, state &goal)
{
	nodesExpanded = 0;
	std::deque<state> q;
	std::vector<action> moves;

	q.push_back(start);
	while (!q.empty())
	{
		state next = q.front();
		q.pop_front();
		if (next == goal)
			return true;

		e.GetActions(next, moves);
		nodesExpanded++;
		for (auto a : moves)
		{
			e.ApplyAction(next, a);
			q.push_back(next);
			e.UndoAction(next, a);
		}
	}
	return false;
}

template <typename state, typename action, typename environment>
uint64_t BFS<state, action, environment>::GetNodesExpanded()
{
	return nodesExpanded;
}



#endif /* BFS_h */
