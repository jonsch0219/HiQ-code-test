#pragma once
#include <iostream>
using namespace std;

#ifndef HIQ_CODE_TEST_ROOM_H
#define HIQ_CODE_TEST_ROOM_H


class Room {
    public:
        // VARIABLES
        int xsize, ysize; // Room size

        // METHODS
        void setRoomSize(int x, int y);

        // CONSTRUCTOR
        Room();
};


#endif //HIQ_CODE_TEST_ROOM_H
