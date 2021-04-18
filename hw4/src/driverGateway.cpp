#include "../headers/driverGateway.h"

driverGateway::driverGateway() = default;

using namespace sqlite_orm;

std::vector<car> driverGateway::getCars() {
    if (isLoggedIn) {
        auto storage = initCarsStorage("../db/db.sqlite");
        return storage.get_all<car>(where(is_equal(&car::driverId, currentUser.id)));
    }
    std::cout << "Need to login" << std::endl;
    return std::vector<car>();
}

bool driverGateway::chooseCar(int id) {
    if (isLoggedIn) {
        auto storage = initCarsStorage("../db/db.sqlite");
        currentCar = storage.get<car>(id);
        return true;
    }
    std::cout << "Need to login" << std::endl;
    return false;
}

void driverGateway::work() {
    if (isLoggedIn) {
        isWorking = true;
    }
    std::cout << "Need to login" << std::endl;
}

void driverGateway::rest() {
    if (isLoggedIn) {
        isWorking = false;
    }
    std::cout << "Need to login" << std::endl;
}

std::vector<order> driverGateway::getAvailableOrders() {
    if (isLoggedIn) {
        auto storage = initOrdersStorage("../db/db.sqlite");
        auto orders = storage.get_all<order>(where(is_equal(&order::status, waitingForDriver)
                                                   and lesser_or_equal(&order::type, currentCar.type)));
        return orders;
    }
    std::cout << "Need to login" << std::endl;
    return std::vector<order>();
}

bool driverGateway::takeOrder(int id) {
    if (isLoggedIn) {
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
    std::cout << "Need to login" << std::endl;
    return false;
}

bool driverGateway::finishOrder(int rating) {
    if (isLoggedIn) {
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
    std::cout << "Need to login" << std::endl;
    return false;
}

bool driverGateway::addCar(std::string model, std::string numberPlate, std::string color, carType type, int x, int y) {
    if (isLoggedIn) {
        auto storage = initCarsStorage("../db/db.sqlite");
        car newCar(currentUser.id, model, numberPlate, color, type, x, y);
        newCar.id = storage.insert(newCar);
        return true;
    }
    std::cout << "Need to login" << std::endl;
    return false;
}



