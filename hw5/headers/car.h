#pragma once

//#ifndef HW4_CAR_H
//#define HW4_CAR_H

#include <string>
#include "common.h"
#include "order.h"

class car {
public:
    int id = -1;
    int driverId;
    std::string model;
    std::string numberPlate;
    std::string color;
    carType type;
    int x;
    int y;
    int bottleCount;
    bool isValidated;
    void parkRightInFrontOfTheEntrance(order currentOrder);

    car();

    car(int driverId, std::string model, std::string numberPlate, std::string color, carType type, int x, int y);
};


//#endif //HW4_CAR_H
