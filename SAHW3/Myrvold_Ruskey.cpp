//
// Created by mikeroit on 4/16/2016.
//

#include "Myrvold_Ruskey.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <cmath>
#include "SlideTileDB.h"
using namespace std;
uint8_t* Myrvold_Ruskey::Unrank15(const int &rank, int size){
//  generate a starting permutation
    uint8_t* myPermutation = generateIdentityPermutatiuon(size);

//  unrank
    unrank1(size, rank, myPermutation);

    return myPermutation;

}

int Myrvold_Ruskey::Rank15(uint8_t* permutaion, int size){
    //calculate ^-1 of permutation
    uint8_t* permutation_inverse = new uint8_t[16];

    for(int i = 0; i < size; i++){
        permutation_inverse[permutaion[i]] = -1;
    }

    for(int i = 0; i < size; i++){
        permutation_inverse[permutaion[i]] = i;
    }

    //do ranking
    int res;
    return rank1(size, permutaion, permutation_inverse);
}

//rank
int Myrvold_Ruskey::rank1(int n, uint8_t* perm, uint8_t* perm_inv){
    if(n == 1){
        return 0;
    }

     uint8_t s = perm[n - 1];
    swap(perm,n-1,perm[perm_inv[n-1]]);
    swap(perm_inv[s], perm_inv[n-1]);
    return (s + (n * rank1(n-1, perm, perm_inv)));
}

void Myrvold_Ruskey::unrank1(int n, int rank, uint8_t* perm){
    if(n > 0){
        swap(perm, n-1, rank%n);
        unrank1(n-1, floor(rank/n), perm);
    }
}

void swap(uint8_t* source, int a, int b){
    uint8_t temp = source[a];

    source[a] = source[b];
    source[b] = temp;
    return;
}

uint8_t* Myrvold_Ruskey::generateIdentityPermutatiuon(int size){
    uint8_t* returnVal = new uint8_t[size];
    for(int i = 0; i < size; i++){
        returnVal[i] = i;
    }

    return returnVal;
}

void printPerm(uint8_t* perm){
    for(int i = 0; i < 16; i++){
        cout << (unsigned int) perm[i] << "  ";
    }
    cout << endl;
}