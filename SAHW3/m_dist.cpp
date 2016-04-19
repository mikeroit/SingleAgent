 //
// Created by mikeroit on 4/8/2016.
//

#include "m_dist.h"
#include <stdio.h>
#include <vector>
#include <stdint.h>
#include <cmath>
#include "SlideTile15.h"

using namespace std;

 int m_dist::getManDist(state &a){
     uint64_t board = a.myState;
     int returnVal = 0;

     for(int y = 0; y < 4; y++){
         for(int x = 0; x < 4; x++){
             int index = (y * 4) + x;
             int value = ((board >> (60 - (index * 4))) & 0x0f);

             if (! (value == 0)) {
                 int valueX = value % 4;
                 int valueY = value / 4;

                 returnVal += (abs(x - valueX) + (abs(y - valueY)));
             }

         }
     }
     return returnVal;
 }
