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
    int ratingSum;
    int numberOfRides;
    std::string login;
    int password;

    void updateRating(int r);
    user(std::string name = "NO_USER", std::string login = "NO_USER", std::string password = "");
};


//#endif //HW4_PERSON_H
