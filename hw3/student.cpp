#include "student.h"

using namespace std;

student::student(string name, string secondName, string email, string mPhone, int day, int month, int year)
        : person(move(name), move(secondName), move(email), move(mPhone), day, month, year) {
    accessLevel = GREEN;
}

void student::nyit() {
    // chat zoo(tglink);
    // zoo.send("xnik xnik(((")
}

void student::shushukatsa() {
    // chat zoo(tglink);
    // zoo.send("lets spam the form about scholarship");
}


