#include "cabinet.h"

cabinet::cabinet() : room() {
    accessLevel = YELLOW;
}

cabinet::cabinet(int rNumber) : room(rNumber) {
    accessLevel = YELLOW;
}
