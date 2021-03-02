#include "person.h"
#include "director.h"

using namespace std;

director::director(string name, string secondName, string email, string mPhone, int day, int month, int year) : person(
        move(name), move(secondName), move(email), move(mPhone), day, month, year) {
    accessLevel = RED;
}

void director::signPapers() {

}

void director::decreaseScholarship() {

}

