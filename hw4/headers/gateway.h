#pragma once

//#ifndef HW4_GATEWAY_H
//#define HW4_GATEWAY_H

#include <string>
#include <vector>
#include "user.h"

class order;

class gateway {
protected:
    user* currentUser;
    order* currentOrder;
    bool isLoggedIn;
    void updateUser();
public:
    gateway();
    bool login(std::string login, std::string password);
    bool registerUser(std::string name, std::string login, std::string password);
    void quit();
    void finishCurrentOrder();
};

//#endif //HW4_GATEWAY_H
