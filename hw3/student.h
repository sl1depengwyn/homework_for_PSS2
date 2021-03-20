
#pragma once

//#ifndef HW2STRINGS_STUDENT_H
//#define HW2STRINGS_STUDENT_H

#include "person.h"

class student : public person {
public:
    student(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
            std::string mPhone = "unknown", int day = 0, int month = 0,
            int year = 1970);

    void nyit();

    void shushukatsa();
};


//#endif //HW2STRINGS_STUDENT_H
