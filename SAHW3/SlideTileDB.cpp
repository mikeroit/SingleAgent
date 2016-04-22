//
// Created by mikeroit on 4/21/16.
//

#include "SlideTileDB.h"
#include <stdio.h>
#include <stdint.h>
#include "STP.h"
#include <vector>
#include <deque>
#include <search.h>
#include "Myrvold_Ruskey.h"

using namespace std;

STPState* SlideTileDB::permutationToFullState(uint8_t permutation[]) {
    STPState* res = new STPState;
    //loop through each critical tile
    //for each index, if the permutation element is the critical tile,
    //  then record it, otheriwse place 99
    for(int i = 0; i < 16; i++){
        res->values[i] = 99;
    }

    for(int i = 0; i < sizeOfPermutation; i++){
        res->values[permutation[i]] = myCriticalTiles[i];
    }

    //set depth
    res->hcost = 255;
    res->blank = permutation[0];

    return res;
}

uint8_t* SlideTileDB::fullStateToPermutation(STPState* state){
    uint8_t* res = new uint8_t[sizeOfPermutation];

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < sizeOfPermutation; j++){
            if(myCriticalTiles[j] == state->values[i]){
                res[j] = state->values[i];
            }
        }
    }

    return res;
}

void SlideTileDB::build() {
    int depth = 0;
    nodesExpanded = 0;
    std::deque<STPState> q;
    STPState tempState;
    uint8_t* tempPermutation = new uint8_t[sizeOfPermutation];
    Myrvold_Ruskey ranker;
    std::vector<slideDir> moves; moves.clear(); moves.resize(0);
    STP stp;

    STPState* goalPointer;
    goalPointer = permutationToFullState(myCriticalTiles);
    //cout << (unsigned int) goalPointer->values[0];
    STPState goal;
    for(int i = 0; i < 16; i++){
        goal.values[i] = goalPointer->values[i];
    }
    goal.hcost = 0;

    //Push back goal
    q.resize(0); q.push_back(goal);

    while(!q.empty()){
        //deque and save popped val
        tempState = q.front();
        q.pop_front();

        //change state to permutation
        tempPermutation = fullStateToPermutation(&tempState);

        //get actions
        stp.GetActions(tempState, moves);

        //handle moves
        for (int i = 0; i < moves.size(); i++) {
            //apply action
            stp.ApplyAction(tempState, moves[i]);
            tempState.hcost = tempState.hcost + 1;

            if (DB[ranker.Rank15(tempPermutation, sizeOfPermutation)] == 255) {

                DB[ranker.Rank15(tempPermutation, sizeOfPermutation)] = tempState.hcost;



                q.push_back(tempState);

                //undo action
                tempState.hcost = tempState.hcost - 1;
                stp.UndoAction(tempState, moves[i]);

                nodesExpanded++;
                cout << tempState.hcost << endl;

            }
            nodesExpanded++;

        }
    }






}