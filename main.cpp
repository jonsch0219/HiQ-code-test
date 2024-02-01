#include "./classes/Room.h"
#include "./classes/User.h"
#include "./classes/Vehicle.h"

int main() {

    User UserObj;
    Room RoomObj;
    Vehicle VehicleObj;

    vector<int> room_size = UserObj.getRoomSize();
    RoomObj.setRoomSize(room_size[0], room_size[1]);

    VehicleObj.setRoom(RoomObj);

    vector<int> start_pos = UserObj.getStartPosition();
    VehicleObj.setStartPosition(start_pos[0], start_pos[1], char(start_pos[2]));

    while (VehicleObj.xpos == -1) {
        start_pos = UserObj.getStartPosition();
        VehicleObj.setStartPosition(start_pos[0], start_pos[1], char(start_pos[2]));
    }

    vector<char> commands = UserObj.getCommands();
    VehicleObj.executeCommands(commands);
}