#pragma once

//#ifndef HW4_PERSON_H
//#define HW4_PERSON_H

#include <string>
#include <vector>
#include <unordered_map>
#include "order.h"

class user {
public:
    int id = -1;
    std::string name;
    double rating;
    std::vector<order> orderHistory;
    std::string login;
    int password;

    user(std::string name = "NO_USER", std::string login = "NO_USER", std::string password = "");
};


//#endif //HW4_PERSON_H
