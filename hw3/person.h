
#pragma once

//#ifndef ASSIGNMENTS_PERSON_H
//#define ASSIGNMENTS_PERSON_H

#include <string>
#include "common.h"
#include "room.h"

class person {
protected:
    unsigned int id;
    static unsigned int idGen;
    std::string name;
    std::string secondName;
    date birthday;
    std::string email;
    access accessLevel;
    std::string mobilePhone;
public:

    person(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
           std::string mPhone = "unknown", int day = 0, int month = 0,
           int year = 1970);

    bool getAccessToRoom(room& room);

    int getId();

    access getAccess();

    void wishHappybirthday(date today);
};


//#endif //ASSIGNMENTS_PERSON_H
