#pragma once

//#ifndef HW4_ADDRES_H
//#define HW4_ADDRES_H

#include <string>
#include <math.h>

class address {
public:
    int id;
    int userId;
    std::string stringRepresentation;
    int x;
    int y;

    int calculateDist(address otherAdr);

    address(std::string strRepresentation = "NO_ADDRESS", int x = 0, int y = 0);
};


//#endif //HW4_ADDRES_H
