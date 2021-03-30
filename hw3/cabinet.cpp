#include "cabinet.h"

cabinet::cabinet(unsigned int rNumber, int floor) : room(rNumber, floor) {
    accessLevel = YELLOW;
}
