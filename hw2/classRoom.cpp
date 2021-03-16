#include "classRoom.h"

classRoom::classRoom() : room() {
    accessLevel = GREEN;
}

classRoom::classRoom(int rNumber) : room(rNumber) {
    accessLevel = GREEN;
}
