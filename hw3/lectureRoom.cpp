#include "lectureRoom.h"

lectureRoom::lectureRoom(unsigned int rNumber, int floor) : room(rNumber, floor) {
    if (floor == 1) {
        accessLevel = BLUE;
    } else {
        accessLevel = YELLOW;
    }
}
