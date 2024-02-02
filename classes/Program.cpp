#include "Program.h"

void Program::runProgram() {
    // Declare Objects
    User UserObj;
    Room RoomObj;
    Vehicle VehicleObj;

    // Create room object
    vector<int> room_size;
    while(room_size.empty()) // Loop until valid room size is inputed by user
        room_size = UserObj.getRoomSize();
    RoomObj.setRoomSize(room_size[0], room_size[1]);

    //Assign Room to Vehicle
    VehicleObj.setRoom(RoomObj);

    // Assign start position and direction of vehicle
    vector<int> start_pos;
    int valid_start;

    while (true) { // Loop until valid start position and direction is inputed from user
        start_pos = UserObj.getStartPosition();
        if(start_pos.empty())
            continue;

        // Checks if the start position given is in room or out of bounds
        valid_start = VehicleObj.setStartPosition(start_pos[0], start_pos[1], char(start_pos[2]));
        if (valid_start == 0)
            continue;
        break;
    }

    // Get and execute commands given from user
    vector<char> commands;
    while (commands.empty()) //Loop until valid commands are inputed by user
        commands = UserObj.getCommands();
    VehicleObj.executeCommands(commands);
}