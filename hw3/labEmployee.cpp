#include "labEmployee.h"

using namespace std;

labEmployee::labEmployee(string name, string secondName, string email, string mPhone, int day, int month, int year)
        : person(move(name), move(secondName), move(email), move(mPhone), day, month, year) {
    accessLevel = YELLOW;
}
