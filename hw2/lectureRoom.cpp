#include "lectureRoom.h"

lectureRoom::lectureRoom() : room() {
    accessLevel = YELLOW;
}

lectureRoom::lectureRoom(int rNumber) : room(rNumber) {
    accessLevel = YELLOW;
}
