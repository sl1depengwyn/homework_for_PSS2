#include <iostream>
#include "person.h"


using namespace std;

unsigned int person::idGen;

person::person(string name, string secondName, string email, string mPhone, int day, int month, int year) {
    id = ++idGen;
    this->email = email;
    mobilePhone = mPhone;
    this->name = name;
    this->secondName = secondName;
    birthday = {day, month, year};
}

bool person::getAccessToRoom(room& room) {
    return room.openDoor(*this);
}

int person::getId() {
    return id;
}

access person::getAccess() {
    return accessLevel;
}

void person::wishHappybirthday(date today) {
    if (today.day == birthday.day &&
        today.month == birthday.month) {
        cout << "Happy Birthday, " << name << "!" << endl;
        //mobilePhone.sengMessage(format"Happy Birthday, {}!", name);
    } else {
        cout << "Not today..." << endl;
    }
}

