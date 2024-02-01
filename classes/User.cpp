#include "User.h"

vector<int> User::getStartPosition() {
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

vector<char> User::getCommands() {
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

vector<int> User::getRoomSize() {
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
