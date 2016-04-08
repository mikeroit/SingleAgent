//
// Created by mikeroit on 4/8/2016.
//

#include "m_dist.h"
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <cmath>

using namespace std;

 int m_dist::getManDist(uint64_t &board){
     int returnVal = 0;

     for(int y = 0; y < 4; y++){
         for(int x = 0; x < 4; x++){
             int index = (y * 4) + x;
             int value = ((board >> (60 - (index * 4))) & 0x0f);

             int valueX = value % 4;
             int valueY = value / 4;

             returnVal += (abs(x - valueX) + (abs(y - valueY)));

         }
     }
     return returnVal;
 }
