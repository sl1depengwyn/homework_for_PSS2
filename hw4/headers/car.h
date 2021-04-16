#pragma once

//#ifndef HW4_CAR_H
//#define HW4_CAR_H

#include <string>
#include "common.h"
#include "order.h"

class car {
public:
    int id;
    int driverId;
    std::string model;
    std::string numberPlate;
    std::string color;
    carType type;
    int currentAddress;
    int bottleCount;
    void parkRightInFrontOfTheEntrance(order currentOrder);
    car();
    car(int driverId, std::string model, std::string numberPlate, std::string color, carType type);
};


//#endif //HW4_CAR_H
