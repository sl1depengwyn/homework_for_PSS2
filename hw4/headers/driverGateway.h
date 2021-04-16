#pragma once

//#ifndef HW4_DRIVERGATEWAY_H
//#define HW4_DRIVERGATEWAY_H

#include <sqlite_orm/sqlite_orm.h>
#include <iostream>
#include <vector>
#include "gateway.h"
#include "car.h"
#include "order.h"


class driverGateway : public gateway {
private:
    car currentCar;
public:
    bool isWorking;
    driverGateway();
    std::vector<car> getCars();
    bool chooseCar(int id);
    void work();
    void rest();
    std::vector<order> getAvailableOrders();
    bool takeOrder(int id);
    bool finishOrder(int rating = -1);
    bool addCar(std::string model, std::string numberPlate, std::string color, carType type);


};


//#endif //HW4_DRIVERGATEWAY_H
