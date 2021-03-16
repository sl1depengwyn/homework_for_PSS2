
#pragma once

//#ifndef HW2STRINGS_ADMIN_H
//#define HW2STRINGS_ADMIN_H

#include "person.h"

class admin : public person::person {
public:

    admin(std::string name = "unknown", std::string secondName = "unknown", std::string email = "unknown",
          std::string mPhone = "unknown", int day = 0, int month = 0,
          int year = 1970);

    void setAccess(person& smone, room& smroom);

    void cancelAccess(person& smone, room& smroom);

    void ban(person& smoneBad, room& smroom);

    void unban(person& smoneNotBadAnymore, room& smroom);
};


//#endif //HW2STRINGS_ADMIN_H
