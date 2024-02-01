#pragma once
#include "Room.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef HIQ_CODE_TEST_VEHICLE_H
#define HIQ_CODE_TEST_VEHICLE_H


class Vehicle {
    public:
        // Variables
        Room RoomObj;
        int xpos, ypos; // Vehicle position (x, y)
        char direction; // Direction of vehicle N, S, W or E

        // METHODS
        void setRoom(Room obj);
        void setStartPosition(int x, int y, char dir);
        void driveForward();
        void driveBack();
        void driveLeft();
        void driveRight();
        void executeCommands(vector<char> commands);

        //CONSTRUCTOR
        Vehicle() {
            xpos = -1;
            ypos = -1;
            direction = '-';
        }
};


#endif //HIQ_CODE_TEST_VEHICLE_H
