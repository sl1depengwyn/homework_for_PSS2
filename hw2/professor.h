
#pragma once

//#ifndef HW2STRINGS_PROFESSOR_H
//#define HW2STRINGS_PROFESSOR_H

#include "person.h"

class professor : public person {
protected:
    std::string favJoke;
public:
    professor(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
              std::string mPhone = "unknown", int day = 0, int month = 0,
              int year = 1970);

    void setFavJoke(std::string joke);

    void provideFavJoke();
};


//#endif //HW2STRINGS_PROFESSOR_H
