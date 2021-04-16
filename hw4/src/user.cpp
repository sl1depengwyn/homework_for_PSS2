#include "../headers/user.h"
#include "../headers/order.h"

using namespace std;

user::user(string name, string login, string password) {

    hash<string> hasher;

    this->name = name;
    this->login = login;
    this->password = hasher(password);
    this->rating = 0;
}

void user::updateRating(int r) {
    ratingSum += r;
    numberOfRides ++;
    rating = ratingSum / numberOfRides;
}
