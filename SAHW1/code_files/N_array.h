//
// Created by mikeroit on 4/1/2016.
//

#ifndef HW1_N_ARRAY_H
#define HW1_N_ARRAY_H

//
// Created by mikeroit on 3/29/2016.

//IMPLICIT implementation of 2d grid domain

#ifndef SINGLEAGENTHW1_GRID_H
#define SINGLEAGENTHW1_GRID_H

#endif //SINGLEAGENTHW1_GRID_H
#include <iostream>
#include <stdint.h>
#include <vector>

//N_array class implements all elements of the implicit exponential domain


//-------------------------------------------------------------------------
class N_array {

public:
//  Default constructor will generate a 100x100 grid
    N_array(){b = 2; d = 100;}
//  Given size param, this constructor sets the given sideLen
    N_array(int bf, int df){b = bf; d = df;}

//  public functions utilized by algorithm
    void GetActions(uint32_t &nodeID, std::vector<uint32_t> &actions);
    void ApplyAction(uint32_t &state, int action);
    void UndoAction(uint32_t &state, int action);

    int getB(){return b;}
    int getD(){return d;}

private:
//  Given the implicit nature of the problem, the only required info
//  to describe the domain is a side length (square domains only)
    int b, d;
    int maxState = pow(b, d);

};
//-------------------------------------------------------------------------







#endif //HW1_N_ARRAY_H
