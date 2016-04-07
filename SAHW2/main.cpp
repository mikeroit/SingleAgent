#include <iostream>
#include "SlideTile15.h"
#include <vector>

using namespace std;

int main() {

    uint64_t board = 0x1011111111111111;
    SlideTile15 *st = new SlideTile15();
    std::vector<uint8_t> list;
    list.clear();

    st->GetActions(board, list);

    for(int i = 0; i < list.size(); i++){
        cout << (int) list.at(i) << endl;
    }

    return 0;
}