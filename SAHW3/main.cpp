#include <iostream>
//#include "Myrvold_Ruskey.h"
//#include <stdint.h>
//#include <stdlib.h>
//#include "Myrvold_Ruskey.h"
//#include <cmath>
#include "SlideTileDB.h"
using namespace std;


int main() {

    uint8_t tiles[] = {0, 1, 4, 5};
    SlideTileDB* DB1 = new SlideTileDB(tiles, 4);
    DB1->build(); cout << DB1->nodesExpanded;
}


