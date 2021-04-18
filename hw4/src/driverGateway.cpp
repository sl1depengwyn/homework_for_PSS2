#include "../headers/driverGateway.h"
#include "../headers/user.h"


driverGateway::driverGateway() = default;

using namespace sqlite_orm;

std::vector<car> driverGateway::getCars() {
    auto storage = initCarsStorage("../db/db.sqlite");
    return storage.get_all<car>(where(is_equal(&car::driverId, currentUser.id)));
}

bool driverGateway::chooseCar(int id) {
    auto storage = initCarsStorage("../db/db.sqlite");
    currentCar = storage.get<car>(id);
    return true;
}

void driverGateway::work() {
    isWorking = true;
}

void driverGateway::rest() {
    isWorking = false;
}

std::vector<order> driverGateway::getAvailableOrders() {
    auto storage = initOrdersStorage("../db/db.sqlite");
    auto orders = storage.get_all<order>(where(is_equal(&order::status, waitingForDriver)));
    auto i = orders.begin();
    while (i < orders.end()) {
        if (i->type > currentCar.type) {
            orders.erase(i);
        }
        i++;
    }
    return orders;
}

bool driverGateway::takeOrder(int id) {
    if (currentCar.id == -1) {
        std::cout << "You have no car" << std::endl;
        return false;
    }
    auto storage = initOrdersStorage("../db/db.sqlite");
    auto takenOrder = storage.get<order>(id);
    if (takenOrder.status != waitingForDriver) return false;
    takenOrder.status = inProcess;
    takenOrder.assignDriver(currentUser.id);
    currentOrder = takenOrder;
    currentOrder.car = currentCar.id;
    storage.update(currentOrder);
    work();
    return true;
}

bool driverGateway::finishOrder(int rating) {
    currentOrder.status = finished;
    currentOrder.paid = currentOrder.from.calculateDist(currentOrder.to);
    switch (currentOrder.type) {
        case economy:
            currentOrder.paid *= 0.9;
            break;
        case comfort:
            currentOrder.paid *= 1.3;
            break;
        case comfortPlus:
            currentOrder.paid *= 1.5;
            break;
        case business:
            currentOrder.paid *= 2;
            break;
    }
    auto storage = initOrdersStorage("../db/db.sqlite");
    storage.update(currentOrder);
    if (rating != -1) {
        auto userStorage = initUsersStorage("../db/db.sqlite");
        auto passenger = userStorage.get<user>(currentOrder.passenger);
        passenger.updateRating(rating);
        userStorage.update(passenger);
    }
    return true;
}

bool driverGateway::addCar(std::string model, std::string numberPlate, std::string color, carType type, int x, int y) {
    if (!isLoggedIn) {
        std::cout << "You need to login" << std::endl;
        return false;
    }
    auto storage = initCarsStorage("../db/db.sqlite");
    car newCar(currentUser.id, model, numberPlate, color, type, x, y);
    newCar.id = storage.insert(newCar);
    return true;
}



