#pragma once
#include <iostream>
using namespace std;

#ifndef HIQ_CODE_TEST_ROOM_H
#define HIQ_CODE_TEST_ROOM_H


class Room {
    private:
        // VARIABLES
        int xsize, ysize; // Room size values from 1-n
    public:
        // METHODS
        void setRoomSize(int x, int y);
        int getRoomSizeX();
        int getRoomSizeY();
        // CONSTRUCTOR
        Room();
};


#endif //HIQ_CODE_TEST_ROOM_H
