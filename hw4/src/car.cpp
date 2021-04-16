#include "../headers/car.h"
#include <iostream>
using namespace std;

void car::parkRightInFrontOfTheEntrance(order currentOrder) {
    cout << "parked right in front of the entrance" << endl;
}

car::car(int intDriver, std::string model, std::string numberPlate, std::string color, carType type) {
    id = -1;
    this->driverId = driverId;
    this->model = model;
    this->numberPlate = numberPlate;
    this->color = color;
    this->type = type;
    bottleCount = 0;
}

car::car() = default;
