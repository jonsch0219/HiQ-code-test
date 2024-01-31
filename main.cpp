#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Room {
public:
    int x, y; // Room size
    void setSize(const vector<int> dims) {
        x = dims[0];
        y = dims[1];
    }
};

class Vehicle {
public:
    int x, y; // Vehicle position
    char dir; // Direction of vehicle
    void setStartPosition(vector<int> start_pos) {
        x = start_pos[0];
        y = start_pos[1];
    }
    void setDirection(char direction) {
        dir = direction;
    }
};

class User {
public:
    static vector<int> getRoomSize() {

        // Get room dimensions from user
        bool invalid_dims = true;
        int x, y;

        while (invalid_dims) {
            cout << "Enter room dimensions (x and y): ";
            cin >> x >> y;
            if (!cin) {
                cout << "Invalid dimensions!" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }
            invalid_dims = false;
        }
        vector<int> room_dims = {x, y};
        return room_dims;
    }

    static vector<int> getStartPosition() {
        // Get starting values from user - position and direction of vehicle
        vector<char> valid_dir = {'N', 'S', 'W', 'E'};
        int x, y;
        char dir;

        while (true) {
            cout << "Enter start position and heading of the vehicle (x, y and N,S,W or E): ";
            cin >> x >> y >> dir;

            if (!cin) {
                cout << "Invalid Input" << endl;
                cin.clear();
                fflush(stdin);
                continue;
            }

            if (!(count(valid_dir.begin(), valid_dir.end(), dir))) {
                cout << "Invalid Direction!" << endl;
                continue;
            }

            break;
        }
        vector<int> start_pos = {x, y, dir};
        return start_pos;
    }
};

/* TODO
vector<int> getCommands()

void executeCommand() {

}
 */


int main() {
    User newUser;
    Room newRoom;
    Vehicle newVehicle;

    vector<int> room_dims = newUser.getRoomSize();
    newRoom.setSize(room_dims);


    cout << "Room Dimensions: " << newRoom.x << " " << newRoom.y << endl;

    vector<int> start_pos = newUser.getStartPosition();
    newVehicle.setStartPosition(start_pos);
    newVehicle.setDirection(start_pos[2]);

    cout << "Starting Position: " << newVehicle.x << " " << newVehicle.y << endl;
    cout << "Direction: " << newVehicle.dir << endl;
}