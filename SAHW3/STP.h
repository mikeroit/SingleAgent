//
//  STP.h
//  HW #2
//
//  Created by Nathan Sturtevant on 4/20/16.
//  Copyright © 2016 NS Software. All rights reserved.
//

#ifndef STP_h
#define STP_h

#include <vector>
#include <iostream>

struct STPState {
	STPState();
	
	uint8_t values[16];
	int blank;
	int hcost;
};

bool operator==(const STPState &s, const STPState &t);
std::ostream &operator<<(std::ostream &out, const STPState &s);

enum slideDir {
	kUp = 1,
	kDown = 2,
	kRight = 3,
	kLeft = 4
};

class STP {
public:
	void GetActions(STPState &nodeID, std::vector<slideDir> &actions);
	void ApplyAction(STPState &s, slideDir a);
	void UndoAction(STPState &s, slideDir a);
	slideDir InvertAction(slideDir a);
	int Distance(int tile, int loc);
private:
};

struct MD {
	int hcost(const STPState &s)
	{
		return s.hcost;
	}
};


#endif /* STP_h */
