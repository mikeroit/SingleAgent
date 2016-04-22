//
//  STP.cpp
//  HW #2
//
//  Created by Nathan Sturtevant on 4/20/16.
//  Copyright © 2016 NS Software. All rights reserved.
//

#include <stdio.h>
#include "STP.h"

STPState::STPState()
{
	for (int x = 0; x < 16; x++)
		values[x] = x;
	blank = 0;
	hcost = 255;
}

std::ostream &operator<<(std::ostream &out, const STPState &s)
{
	out << "Blank: " << s.blank << "; h: " << s.hcost << "\n";
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			out << s.values[4*y+x]/10 << s.values[4*y+x]%10 << " ";
		}
		out << "\n";
	}
	return out;
}

bool operator==(const STPState &s, const STPState &t)
{
	for (int x = 0; x < 16; x++)
		if (s.values[x] != t.values[x])
			return false;
	return true;
}



void STP::GetActions(STPState &nodeID, std::vector<slideDir> &actions)
{
	actions.resize(0);
	switch (nodeID.blank)
	{
		case 0:
			actions.push_back(kDown);
			actions.push_back(kRight);
			break;
		case 1:
		case 2:
			actions.push_back(kDown);
			actions.push_back(kRight);
			actions.push_back(kLeft);
			break;
		case 3:
			actions.push_back(kDown);
			actions.push_back(kLeft);
			break;
		case 4:
		case 8:
			actions.push_back(kDown);
			actions.push_back(kUp);
			actions.push_back(kRight);
			break;
		case 5:
		case 6:
		case 9:
		case 10:
			actions.push_back(kDown);
			actions.push_back(kUp);
			actions.push_back(kRight);
			actions.push_back(kLeft);
			break;
		case 7:
		case 11:
			actions.push_back(kUp);
			actions.push_back(kDown);
			actions.push_back(kLeft);
			break;
		case 12:
			actions.push_back(kUp);
			actions.push_back(kRight);
			break;
		case 13:
		case 14:
			actions.push_back(kUp);
			actions.push_back(kRight);
			actions.push_back(kLeft);
			break;
		case 15:
			actions.push_back(kUp);
			actions.push_back(kLeft);
			break;
	}
}

void STP::ApplyAction(STPState &s, slideDir a)
{
	switch (a)
	{
		case kUp:
			//s.hcost -= Distance(s.values[s.blank-4], s.blank-4);
			//s.hcost += Distance(s.values[s.blank-4], s.blank);

			s.values[s.blank] = s.values[s.blank-4];
			s.values[s.blank-4] = 0;
			s.blank -= 4;
			break;
		case kDown:
			//s.hcost -= Distance(s.values[s.blank+4], s.blank+4);
			//s.hcost += Distance(s.values[s.blank+4], s.blank);

			s.values[s.blank] = s.values[s.blank+4];
			s.values[s.blank+4] = 0;
			s.blank += 4;
			break;
		case kLeft:
			//s.hcost -= Distance(s.values[s.blank-1], s.blank-1);
			//s.hcost += Distance(s.values[s.blank-1], s.blank);

			s.values[s.blank] = s.values[s.blank-1];
			s.values[s.blank-1] = 0;
			s.blank -= 1;
			break;
		case kRight:
			//s.hcost -= Distance(s.values[s.blank+1], s.blank+1);
			//s.hcost += Distance(s.values[s.blank+1], s.blank);

			s.values[s.blank] = s.values[s.blank+1];
			s.values[s.blank+1] = 0;
			s.blank += 1;
			break;
	}
}

slideDir STP::InvertAction(slideDir a)
{
	switch (a) // invert action
	{
		case kUp: return kDown; break;
		case kDown: return kUp; break;
		case kLeft: return kRight; break;
		case kRight: return kLeft; break;
	}
}

void STP::UndoAction(STPState &s, slideDir a)
{
	ApplyAction(s, InvertAction(a));
}


int STP::Distance(int tile, int loc)
{
	static int values[16][16] =
			{
					{0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6}, // 0
					{1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4, 4, 3, 4, 5}, // 1
					{2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3, 5, 4, 3, 4}, // 2
					{3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2, 6, 5, 4, 3}, // 3
					{1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5}, // 4
					{2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3, 3, 2, 3, 4}, // 5
					{3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2, 4, 3, 2, 3}, // 6
					{4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1, 5, 4, 3, 2}, // 7
					{2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3, 1, 2, 3, 4}, // 8
					{3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2, 2, 1, 2, 3}, // 9
					{4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1, 3, 2, 1, 2}, // 10
					{5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0, 4, 3, 2, 1}, // 11
					{3, 4, 5, 6, 2, 3, 4, 5, 1, 2, 3, 4, 0, 1, 2, 3}, // 12
					{4, 3, 4, 5, 3, 2, 3, 4, 2, 1, 2, 3, 1, 0, 1, 2}, // 13
					{5, 4, 3, 4, 4, 3, 2, 3, 3, 2, 1, 2, 2, 1, 0, 1}, // 14
					{6, 5, 4, 3, 5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0}
			};
	return values[tile][loc];
}
