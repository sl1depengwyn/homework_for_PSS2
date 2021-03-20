#include "guest.h"

using namespace std;

guest::guest(string name, string secondName, string email, string mPhone, int day, int month, int year)
        : person(move(name), move(secondName), move(email), move(mPhone), day, month, year) {
    accessLevel = BLUE;
}