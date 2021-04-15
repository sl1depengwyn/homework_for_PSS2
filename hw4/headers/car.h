#pragma once

//#ifndef HW4_CAR_H
//#define HW4_CAR_H

#include <string>
#include "common.h"
#include "address.h"

class car {
public:
    int id;
    std::string model;
    std::string numberPlate;
    std::string color;
    carType type;
    address currentAddress;
    int bottleCount;
    void parkRightInFrontOfTheEntrance(address client);
};


//#endif //HW4_CAR_H
