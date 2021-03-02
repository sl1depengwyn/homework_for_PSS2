#include "admin.h"

using namespace std;


admin::admin(string name, string secondName, string email, std::string mPhone, int day, int month, int year)
        : person::person(move(name), move(secondName), move(email), move(mPhone), day, month,
                         year) {
    accessLevel = RED;
}

void admin::setAccess(person& smone, room& smroom) {
    smroom.setAccess(smone);
}

void admin::cancelAccess(person& smone, room& smroom) {
    smroom.rejectAccess(smone);
}

void admin::ban(person& smoneBad, room& smroom) {
    smroom.ban(smoneBad);
}

void admin::unban(person& smoneNotBadAnymore, room& smroom) {
    smroom.unban(smoneNotBadAnymore);
}
