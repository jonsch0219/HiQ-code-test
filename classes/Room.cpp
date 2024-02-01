#include "Room.h"

void Room::setRoomSize(int x, int y) {
    xsize = x;
    ysize = y;
    cout << "Room size: " << xsize << "x" << ysize << endl;
}

// CONSTRUCTOR
Room::Room() {
    xsize = 0;
    ysize = 0;
}
