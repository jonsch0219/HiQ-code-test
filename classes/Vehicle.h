#pragma once
#include "Room.h"
#include <iostream>
#include <vector>
using namespace std;

#ifndef HIQ_CODE_TEST_VEHICLE_H
#define HIQ_CODE_TEST_VEHICLE_H


class Vehicle {
    private:
        // Variables
        Room RoomObj;
        int xpos, ypos; // Vehicle position (x, y) 0-n index
        char direction; // Direction of vehicle N, S, W or E

    public:
        // METHODS
        void setRoom(Room obj);
        int setStartPosition(int x, int y, char dir);
        void driveForward();
        void driveBack();
        void driveLeft();
        void driveRight();
        int executeCommands(vector<char> commands);

        //CONSTRUCTOR
        Vehicle();
};


#endif //HIQ_CODE_TEST_VEHICLE_H
