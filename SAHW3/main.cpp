#include <iostream>
#include "Myrvold_Ruskey.h"
#include <stdint.h>
#include <stdlib.h>
#include "Myrvold_Ruskey.h"
#include <cmath>

using namespace std;

void testRanking(){
    Myrvold_Ruskey *ranker = new Myrvold_Ruskey;

    uint8_t myPermutation[] = {2,0,1,3};
    uint8_t myInverse[4];
    for(int i = 0; i < 4; i++){
        myInverse[myPermutation[i]];
    }
    cout << "Generating ranking:" << endl;

    cout << ranker->Rank15(myPermutation, 4) << endl;
}

void testUnranking(){
    Myrvold_Ruskey *ranker = new Myrvold_Ruskey;

    uint8_t** myPermutations = new uint8_t*[24];
    for(int i = 0; i < 24; i++){
        myPermutations[i] = ranker->Unrank15(i, 4);
    }
    cout << "Generating unranking's for 0-23:" << endl;

    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 4; j++){
            cout << (unsigned int)  myPermutations[i][j] << ", ";
        }
        cout << endl;
    }
}

int main() {


    testRanking();

}


