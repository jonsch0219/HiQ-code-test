#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Room {
public:
    unsigned int xsize, ysize; // Room size
    void setRoomSize() {
        // Get room dimensions from user
        int x, y;

        while (true) {
            cout << "Enter room dimensions (x and y): ";
            cin >> x >> y;
            if (!cin or x <= 0 or y <= 0) {
                cout << "Invalid dimensions!" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }
            break;
        }

        xsize = x;
        ysize = y;
    }
    Room() {
        xsize = 0;
        ysize = 0;
    }
};

class Vehicle {
public:
    Room RoomObj;
    unsigned int xpos, ypos; // Vehicle position
    char direction; // Direction of vehicle
    void setRoom(Room obj) {
        RoomObj = obj;
    }
    void setStartPosition() {

        vector<char> valid_dir = {'N', 'S', 'W', 'E'};
        int x = 0, y = 0;
        char dir = '-';

        while (true) {
            if (RoomObj.ysize == 0 and RoomObj.ysize == 0) {
                cout << "No room set!" << endl;
                break;
            }
            cout << "Enter start position and heading of the vehicle (x, y and N,S,W or E): ";
            cin >> x >> y >> dir;
            // Checks for invalid types and directions and negative values and if starting position is available
            if (!cin or !(count(valid_dir.begin(), valid_dir.end(), dir)) or x < 0 or y < 0 or x > RoomObj.xsize or y > RoomObj.ysize) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }
            break;
        }
        xpos = x;
        ypos = y;
        direction = dir;
    }
};


/* TODO
vector<int> getCommands()

void executeCommand() {

}
 */


int main() {
    Room RoomObj;
    Vehicle VehicleObj;

    RoomObj.setRoomSize();
    cout << "Room size: " << RoomObj.xsize << "x" << RoomObj.ysize << endl;

    VehicleObj.setRoom(RoomObj);
    VehicleObj.setStartPosition();
    cout << "Vehicle Position and Direction: (x:" << VehicleObj.xpos << ", y:" << VehicleObj.ypos << ") " << VehicleObj.direction << endl;

}