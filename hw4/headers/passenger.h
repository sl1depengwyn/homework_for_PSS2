#pragma once

//#ifndef HW4_PASSANGER_H
//#define HW4_PASSANGER_H

#include "user.h"
#include "common.h"
#include <vector>


class passenger : public user {
public:
    std::vector<paymentMethod> paymentMethods;
    passenger(std::string name = "NO_USER", std::string login = "NO_USER", std::string password = "");
};


//#endif //HW4_PASSANGER_H
