#pragma once

//#ifndef HW4_DRIVERGATEWAY_H
//#define HW4_DRIVERGATEWAY_H

#include <sqlite_orm/sqlite_orm.h>
#include <iostream>
#include "car.h"

class driver;

class driverGateway {
private:
    driver* currentUser{};
public:
    driverGateway();
    bool login(std::string login, std::string password);

};


//#endif //HW4_DRIVERGATEWAY_H
