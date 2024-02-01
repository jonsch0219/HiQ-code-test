#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Room {
public:
    // VARIABLES
    unsigned int xsize, ysize; // Room size

    // METHODS
    void setRoomSize(int x, int y) {
        xsize = x;
        ysize = y;
    }

    // CONSTRUCTOR
    Room() {
        xsize = 0;
        ysize = 0;
    }
};

class Vehicle {
public:
    // Variables
    Room RoomObj;
    unsigned int xpos, ypos; // Vehicle position (x, y)
    char direction; // Direction of vehicle N, S, W or E

    // METHODS
    void setRoom(Room obj) {
        RoomObj = obj;
    }

    void setStartPosition(int x, int y, char dir) {
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

    void driveForward() {
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
    void driveBack() {
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

    void driveLeft() {
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

    void driveRight () {
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

    void executeCommands(vector<char> commands) {
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
};


class User {
public:
    // METHODS
    vector<int> getStartPosition() {
        vector<char> valid_dir = {'N', 'S', 'W', 'E'};
        int x = 0, y = 0;
        char dir = '-';

        while (true) {
            // Get starting position and direction from user
            cout << "Enter start position and heading of the vehicle (x, y and N,S,W or E): ";
            cin >> x >> y >> dir;

            // Checks for invalid types and directions and negative values and if starting position is available in the given room
            if (!cin or !(count(valid_dir.begin(), valid_dir.end(), dir)) or x < 0 or y < 0) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }
            vector<int> start_pos = {x, y, dir};
            return start_pos;
        }
    }

    vector<char> getCommands() {
        vector<char> valid_com = {'F', 'B', 'L', 'R'};
        string input_com;

        // Get commands from user and check for invalid input
        while (true) {
            bool invalid_value = false;
            cout << "Enter commands in order left to right (F, B, L or R): ";
            cin >> input_com;
            vector<char> commands(input_com.begin(), input_com.end()); //Split string into vector of chars

            // Loop through vector and make sure all commands are valid
            for (char i: commands) {
                if (!(count(valid_com.begin(), valid_com.end(), i))) {
                    cin.clear();
                    fflush(stdin);
                    invalid_value = true;
                    break;
                }
            }

            if (invalid_value) {
                cout << "Invalid command found!" << endl;
                continue;
            }
            return commands;
        }
    }

    vector<int> getRoomSize() {

        // Get room dimensions from user
        int x, y;

        while (true) {
            cout << "Enter room dimensions (x and y): ";
            cin >> x >> y;
            // Check for invalid types or negative values
            if (!cin or x <= 0 or y <= 0) {
                cout << "Invalid dimensions!" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }
            vector<int> room_size = {x, y};
            return room_size;
        }
    }

};



int main() {

    User UserObj;
    Room RoomObj;
    Vehicle VehicleObj;

    vector<int> room_size = UserObj.getRoomSize();
    vector<int> start_pos = UserObj.getStartPosition();

    RoomObj.setRoomSize(room_size[0], room_size[1]);

    VehicleObj.setRoom(RoomObj);
    cout << "Room size: " << VehicleObj.RoomObj.xsize << "x" << VehicleObj.RoomObj.ysize << endl;
    VehicleObj.setStartPosition(start_pos[0], start_pos[1], char(start_pos[2]));
    cout << "Vehicle position and direction (x, y, direction): (" << VehicleObj.xpos << ", " << VehicleObj.ypos << ", " << VehicleObj.direction << ")" << endl;

    vector<char> commands = UserObj.getCommands();
    VehicleObj.executeCommands(commands);
}