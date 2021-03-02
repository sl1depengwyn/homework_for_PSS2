
#pragma once

//#ifndef HW2STRINGS_LABEMPLOYEE_H
//#define HW2STRINGS_LABEMPLOYEE_H

#include "person.h"

class labEmployee : public person {
public:
    labEmployee(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
                std::string mPhone = "unknown", int day = 0, int month = 0,
                int year = 1970);
};


//#endif //HW2STRINGS_LABEMPLOYEE_H
