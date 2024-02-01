//
// Created by jonas on 2024-02-01.
//

#include "Room.h"

void Room::setRoomSize(int x, int y) {
    xsize = x;
    ysize = y;
}

// CONSTRUCTOR
Room::Room() {
    xsize = 0;
    ysize = 0;
}
