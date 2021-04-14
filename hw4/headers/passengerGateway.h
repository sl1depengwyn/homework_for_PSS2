#pragma once

//#ifndef HW4_PASSENGERGATEWAY_H
//#define HW4_PASSENGERGATEWAY_H

#include "passenger.h"
#include <sqlite_orm/sqlite_orm.h>
#include <iostream>

class passengerGateway {
private:
    passenger currentUser;
public:
    passengerGateway();
    bool login(std::string login, std::string password);
};


//#endif //HW4_PASSENGERGATEWAY_H
