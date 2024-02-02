#include "Room.h"

void Room::setRoomSize(int x, int y) {
    // x and y are given as 1-n index and xsize and ysize are 0-n index
    xsize = x - 1;
    ysize = y - 1;
    cout << "Room size: " << x << "x" << y << endl;
}

// CONSTRUCTOR
Room::Room() {
    xsize = 0;
    ysize = 0;
}
