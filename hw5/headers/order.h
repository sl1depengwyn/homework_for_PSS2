#pragma once

//#ifndef HW4_ORDER_H
//#define HW4_ORDER_H


#include "common.h"
#include "address.h"
#include <ctime>


class order {
public:
    int id;
    address from;
    address to;
    carType type;
    orderStatus status;
    long long timeOfCreating;
    int cardPayed;
    double paid;
    int driver;
    int car;
    int passenger;

    order(address from = address(), address to = address(), carType type = economy);

    void assignDriver(int drvr);
};


//#endif //HW4_ORDER_H
