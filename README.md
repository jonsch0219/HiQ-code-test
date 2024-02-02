# Note to reviewer
In total I spent around 8 hours on this project which includes setting up the environment, developing, refactoring, testing and documenting.

## Assumptions made
During the process of completing this test I made assumptions about the program asked to be implemented. First of I assumed that only one vehicle could be in a single room at a time, if this weren't the case I would have to implement a
1-N relationship between the Room and Vehicle class. Which would mean each Room object would contain a list of vehicles. This also implies that the only crashes i need to handle are the ones where the vehicle drives out of bounds (hits a wall).

When entering the commands LEFT or RIGHT I assumed that the vehicle should rotate and drive in that direction instead of just rotating in its place. This is something I realized later on could possibly be a missunderstanding on my part but chose to keep
the feature anyway. Also when entering the command BACK the vehicle does not reverse it instead changes direction 180 degrees and drives in that direction, which is as mentioned before something I may have misunderstood but chose to keep anyway.

## Classes
My program is divided into 4 classes **Program**, **Room**, **Vehicle** and **User**. 

**Program** Contains the code necessary to run the program in a smooth way and handling invalid inputs and contradictions that may arise. 

**Room** class is used to store the size of the room given in 1-n index (a 1x1 room is 1 block).

**Vehicle** Contains the position of the vehicle which is given in 0-n index (if a vehicle is placed in a block inside a 1x1 room its position will be (0, 0)) and the direction (N: north, S: south, W: west, E: east). 
A vehicle also contains a Room object which specifies in what room the vehicle is placed in and will execute the given commands in.

**User** consists of methods that get input data from the users. The different methods have code that checks for invalid inputs and signals this by signaling with a specific return value such as 0 or {} (empty vector).

## User guide
When starting the program you will be asked to input the size of the room in which the vehicle will drive around in. The size will be given in x and y dimensions (ranging from 1-n) seperated by a space.

Example input: 1 1 (room size of 1 block)

After you've specified the room size you know need to enter the starting position and direction of the vehicle which will drive in the room. This is given by x and y index (ranging from 0-n) and N: north, S: south, W: west, or E: east all seperated by a space.

Example input: 0 0 N

At last if the input is correct you will be asked to enter a list of commands F: forward, L: left, R: right, B: back which will be executed in the order given.

Example input: FFLRLRB

Worth mentioning: when given the output which shows how the vehicle position changes after each command executed, the positions of the vehicle are given in x and y coordinates ranging from index 0-n. So if the vehicle is in a 2x2 size room vehicle position (2, 2) is out of bounds.



