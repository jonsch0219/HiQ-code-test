#include "./classes/Room.h"
#include "./classes/User.h"
#include "./classes/Vehicle.h"

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