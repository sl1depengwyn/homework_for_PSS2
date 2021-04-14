#include "../headers/address.h"

using namespace std;

int address::calculateDist(address otherAdr) {
    int dx = this->x - otherAdr.x;
    int dy = this->y - otherAdr.y;
    return int(sqrt(dx*dx + dy*dy));
}

address::address(std::string strRepresentation, int x, int y) {
    this->stringRepresentation = strRepresentation;
    this->x = x;
    this->y = y;
}
