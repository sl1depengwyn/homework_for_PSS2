#include "../headers/order.h"

order::order(address from, address to, carType type) {
    this->id = -1;
    this->from = from;
    this->to = to;
    this->type = type;
    this->status = justCreated;
    this->timeOfCreating = time(nullptr);
    cardPayed = -1;
    paid = -1;
    driver = -1;
    car = -1;
    passenger = -1;
}

void order::assignDriver(int drvr) {
    driver = drvr;
}
