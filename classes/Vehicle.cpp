#include "Vehicle.h"

void Vehicle::setRoom(Room obj) {
    RoomObj = obj;
}

void Vehicle::setStartPosition(int x, int y, char dir) {
    // Set start position of car given from user

    // Check if the vehicle can be placed in given position
    if (x > RoomObj.xsize or y > RoomObj.ysize) {
        cout << "Cannot place vehicle at this position!" << endl;
    }
    else {
        //Set start position
        xpos = x;
        ypos = y;
        direction = dir;
    }
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

void Vehicle::executeCommands(vector<char> commands) {
    bool crash = false;

    for (char i: commands) {
        switch(i) {
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
        if (xpos > RoomObj.xsize or ypos > RoomObj.ysize) {
            crash = true;
            cout << "Car has crashed trying to enter (" << xpos << ", " << ypos << ") which is out of bounds!" << endl;
            break;
        }
    }
    if (!crash) {
        cout << "Commands executed successfully!" << endl;
    }
}