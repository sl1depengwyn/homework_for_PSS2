#include "common.h"
#include "room.h"
#include "directorCabinet.h"

directorCabinet::directorCabinet(unsigned int rNumber, int floor) : room(rNumber, floor) {
    accessLevel = RED;
}
