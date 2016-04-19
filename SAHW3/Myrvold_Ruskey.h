//
// Created by mikeroit on 4/16/2016.
//

#ifndef SAHW3_MYRVOLD_RUSKEY_H
#define SAHW3_MYRVOLD_RUSKEY_H

#include <stdint.h>
#include <stdint-gcc.h>

void swap(uint8_t* source, int a, int b);

class Myrvold_Ruskey{
public:
    int Rank15(uint8_t* permutaion, int size);
    uint8_t* Unrank15(const int &rank, int size);

    void unrank1(int n, int rank, uint8_t* perm);
    int rank1(int n, uint8_t* perm, uint8_t* perm_inv);



    uint8_t* generateIdentityPermutatiuon(int size);

    void printPerm(uint8_t* perm);
};


#endif //SAHW3_MYRVOLD_RUSKEY_H






