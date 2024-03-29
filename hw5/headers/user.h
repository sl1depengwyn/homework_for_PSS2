#pragma once

//#ifndef HW4_PERSON_H
//#define HW4_PERSON_H

#include <string>
#include <vector>
#include <unordered_map>

class order;

class user {
public:
    int id = -1;
    std::string name;
    double rating;
    double ratingSum;
    double numberOfRides;
    std::string login;
    unsigned long long int password;
    bool isAdmin;
    bool canMakeOrders;
    bool canAcceptOrders;

    void updateRating(int r);

    user(std::string name = "NO_USER", std::string login = "NO_USER", std::string password = "");
};


//#endif //HW4_PERSON_H
