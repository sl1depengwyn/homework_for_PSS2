#include <iostream>
#include "professor.h"

using namespace std;

professor::professor(string name, string secondName, string email, string mPhone, int day, int month, int year)
        : person(move(name), move(secondName), move(email), move(mPhone), day, month, year) {
    accessLevel = YELLOW;
}

void professor::setFavJoke(std::string joke) {
    favJoke = move(joke);
}

void professor::provideFavJoke() {
    cout << favJoke << endl;
}
