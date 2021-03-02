#include "conferenceRoom.h"

conferenceRoom::conferenceRoom() : room() {
    accessLevel = YELLOW;
}

conferenceRoom::conferenceRoom(int rNumber) : room(rNumber) {
    accessLevel = YELLOW;
}
