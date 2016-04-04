//
// Created by mikeroit on 4/1/2016.
//

//
//Created by mikeroit on 3/29/2016.
//

#include <stdint.h>
#include <cmath>
#include "N_array.h"

//Constructors generic- implemented in "Grid.h"

//-------------------------------------------------------------------------
//Public Methods:

void N_array::GetActions(uint32_t &nodeID, std::vector<uint32_t> &actions){

   for(int i = 0; i < b; i++){
       uint32_t temp = b * nodeID + i;
       if(temp < pow(b, d)) actions.push_back(temp);
   }

}

void N_array::ApplyAction(uint32_t &state, int action){
    state += action;
}

void N_array::UndoAction(uint32_t &state, int action){
    state -= action;
}

//-------------------------------------------------------------------------


