#include "conferenceRoom.h"


conferenceRoom::conferenceRoom(unsigned int rNumber, int floor) : room(rNumber, floor) {
    if (floor == 1) {
        accessLevel = BLUE;
    } else {
        accessLevel = YELLOW;
    }
}

