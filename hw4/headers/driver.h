#pragma once

//#ifndef HW4_DRIVER_H
//#define HW4_DRIVER_H

#include "user.h"

class driver  : public user {
public:
    driver(std::string name = "NO_USER", std::string login = "NO_USER", std::string password = "");
};


//#endif //HW4_DRIVER_H
