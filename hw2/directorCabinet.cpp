#include "common.h"
#include "room.h"
#include "directorCabinet.h"

directorCabinet::directorCabinet() : room() {
    accessLevel = RED;
}

directorCabinet::directorCabinet(int rNumber) : room(rNumber) {
    accessLevel = RED;
}
