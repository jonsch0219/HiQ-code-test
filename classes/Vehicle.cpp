#include "Vehicle.h"

void Vehicle::setRoom(Room obj) {
    RoomObj = obj;
}

int Vehicle::setStartPosition(int x, int y, char dir) {
    // Set start position of car given from user

    // Check if the vehicle can be placed in given position
    if (x > RoomObj.xsize or y > RoomObj.ysize) {
        cout << "Cannot place vehicle at this position!" << endl;
        return 0; // Position invalid and therefore not set return 0
    }

    //Set start position
    xpos = x;
    ypos = y;
    direction = dir;
    cout << "Vehicle position and direction (x, y, direction): (" << xpos << ", " << ypos << ", " << direction << ")" << endl;
    return 1;
}

void Vehicle::driveForward() {
    switch(direction) {
        case 'N':
            ypos += 1;
            cout << "Vehicle moved from: (" << xpos << ", " << ypos - 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'S':
            ypos -= 1;
            cout << "Vehicle moved from: (" << xpos << ", " << ypos + 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'W':
            xpos -= 1;
            cout << "Vehicle moved from: (" << xpos + 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'E':
            xpos += 1;
            cout << "Vehicle moved from: (" << xpos - 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        default:
            break;
    }
}

void Vehicle::driveBack() {
    switch(direction) {
        case 'N':
            ypos -= 1;
            direction = 'S';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos + 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'S':
            ypos += 1;
            direction = 'N';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos - 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'W':
            xpos += 1;
            direction = 'E';
            cout << "Vehicle moved from: (" << xpos - 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'E':
            xpos -= 1;
            direction = 'W';
            cout << "Vehicle moved from: (" << xpos + 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        default:
            break;
    }
}

void Vehicle::driveLeft() {
    switch(direction) {
        case 'N':
            xpos -= 1;
            direction = 'W';
            cout << "Vehicle moved from: (" << xpos + 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'S':
            xpos += 1;
            direction = 'E';
            cout << "Vehicle moved from: (" << xpos - 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'W':
            ypos -= 1;
            direction = 'S';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos + 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'E':
            ypos += 1;
            direction = 'N';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos - 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        default:
            break;
    }
}

void Vehicle::driveRight() {
    switch(direction) {
        case 'N':
            xpos += 1;
            direction = 'E';
            cout << "Vehicle moved from: (" << xpos - 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'S':
            xpos -= 1;
            direction = 'W';
            cout << "Vehicle moved from: (" << xpos + 1 << ", " << ypos << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'W':
            ypos += 1;
            direction = 'N';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos - 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        case 'E':
            ypos -= 1;
            direction = 'S';
            cout << "Vehicle moved from: (" << xpos << ", " << ypos + 1 << ") to (" << xpos << ", " << ypos << ")" << endl;
            break;
        default:
            break;
    }
}

int Vehicle::executeCommands(vector<char> commands) {

    for (char i: commands) {
        switch (i) {
            case 'F':
                cout << "Driving forward..." << endl;
                driveForward();
                break;
            case 'B':
                cout << "Driving backward..." << endl;
                driveBack();
                break;
            case 'L':
                cout << "Driving left..." << endl;
                driveLeft();
                break;
            case 'R':
                cout << "Driving right..." << endl;
                driveRight();
                break;
            default:
                break;
        }

        if (xpos > RoomObj.xsize or ypos > RoomObj.ysize or xpos < 0 or ypos < 0) {
            cout << "Car has crashed trying to enter (" << xpos << ", " << ypos << ") which is out of bounds!" << endl;
            return 0; // car has crashed return 0
        }
    }
    cout << "Commands executed successfully!" << endl;
    return 1; // car has completed commands without crashing
}

Vehicle::Vehicle() {
        xpos = 0;
        ypos = 0;
        direction = '-';
}