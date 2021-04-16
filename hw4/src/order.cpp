#include "../headers/order.h"
#include "../headers/address.h"


order::order(address from, address to, carType type) {
    this->from = from;
    this->to = to;
    this->type = type;
    this->status = justCreated;
    this->timeOfCreating = time(nullptr);
}

void order::assignDriver(int drvr) {
    driver = drvr;
}
