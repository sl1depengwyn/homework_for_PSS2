#include "../headers/car.h"
#include <iostream>

using namespace std;

void car::parkRightInFrontOfTheEntrance(order currentOrder) {
    cout << "parked right in front of the entrance" << endl;
}

car::car(int DriverId, std::string model, std::string numberPlate, std::string color, carType type, int x, int y) {
    id = -1;
    this->driverId = DriverId;
    this->model = model;
    this->numberPlate = numberPlate;
    this->color = color;
    this->type = type;
    this->x = x;
    this->y = y;
    bottleCount = 0;
}

car::car() = default;
