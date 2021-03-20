
#pragma once

//#ifndef HW2_GUEST_H
//#define HW2_GUEST_H

#include "person.h"

class guest : public person {
public:
    guest(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
          std::string mPhone = "unknown", int day = 0, int month = 0,
          int year = 1970);
};


//#endif //HW2_GUEST_H
