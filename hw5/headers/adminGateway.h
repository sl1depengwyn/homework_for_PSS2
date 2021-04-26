#pragma once

//#ifndef HW4_ADMINGATEWAY_H
//#define HW4_ADMINGATEWAY_H

#include "gateway.h"

class adminGateway : public gateway {
public:
    adminGateway();
    void validateCar(int id);
    void blockPassenger(int id);
    void blockDriver(int id);
    void unblockPassenger(int id);
    void unblockDriver(int id);
};

//#endif //HW4_ADMINGATEWAY_H
