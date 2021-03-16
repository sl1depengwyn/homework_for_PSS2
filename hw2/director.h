
#pragma once

//#ifndef HW2STRINGS_DIRECTOR_H
//#define HW2STRINGS_DIRECTOR_H

#include "person.h"

class director : public person {
public:
    director(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
             std::string mPhone = "unknown", int day = 0, int month = 0,
             int year = 1970);

    void signPapers();

    void decreaseScholarship();
};


//#endif //HW2STRINGS_DIRECTOR_H
