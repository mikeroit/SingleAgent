//
// Created by mikeroit on 4/21/16.
//

#ifndef SAHW3_SLIDETILEDB_H
#define SAHW3_SLIDETILEDB_H

#include <iostream>
#include <vector>
#include <stdint.h>
#include "STP.h"


class SlideTileDB {
public:
    //constructor
    SlideTileDB(uint8_t tiles[], int size){
        myCriticalTiles = new uint8_t[size];
        for(int i = 0; i < size; i++){
            myCriticalTiles[i] = tiles[i];
        }
        sizeOfPermutation = size;
        sizeOfDB = 1;
        for(int i = 0; i < sizeOfPermutation; i++){
            sizeOfDB *= 16-i;
        }

        DB = new uint8_t[sizeOfDB];
        for(int i = 0; i < sizeOfDB; i++){
            DB[i] = 255;
        }
    }



    void build();


    //Need to be able to send data to STP class
    STPState* permutationToFullState(uint8_t permutation[]);
    uint8_t* fullStateToPermutation(STPState *state);




    //keep track of:
    //  size of db
    unsigned long sizeOfDB;

    //  db itself
    uint8_t* DB;

    //  size of permutation (which elemets we keep)
    //    must contain zero
    int sizeOfPermutation;

    //  permutation itself
    uint8_t* myCriticalTiles;

    //  nodes that are expanded in construction
    unsigned long nodesExpanded;

};


#endif //SAHW3_SLIDETILEDB_H
