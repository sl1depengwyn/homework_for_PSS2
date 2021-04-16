#include "../headers/driverGateway.h"


driverGateway::driverGateway() {
    carId = -1;
}

using namespace sqlite_orm;

inline auto initCarsStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("cars",
                                           make_column("id", &car::id, autoincrement(), primary_key()),
                                           make_column("model", &car::model),
                                           make_column("color", &car::color),
                                           make_column("type", &car::type),
                                           make_column("bottles", &car::bottleCount),
                                           make_column("address", &car::currentAddress)));
    storage.sync_schema();
    return storage;
}

inline auto initAddressStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("addresses",
                                           make_column("id", &address::id, autoincrement(), primary_key()),
                                           make_column("string_representation", &address::stringRepresentation),
                                           make_column("x", &address::x),
                                           make_column("y", &address::y),
                                           make_column("owner_id", &address::userId)));
    storage.sync_schema();
    return storage;
}

inline auto initOrderStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("orders",
                                           make_column("id", &order::id, autoincrement(), primary_key()),
                                           make_column("car_type", &order::type),
                                           make_column("status", &order::status),
                                           make_column("driver", &order::driver),
                                           make_column("payed", &order::paid),
                                           make_column("time_of_creating", &order::timeOfCreating),
                                           make_column("card_payed", &order::cardPayed),
                                           make_column("rating", &order::rating)));
    storage.sync_schema();
    return storage;
}

std::vector<car> driverGateway::getCars() {
    auto storage = initCarsStorage("../db/db.sqlite");
    return storage.get_all<car>(where(is_equal(&car::driverId, currentUser->id)));
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
    auto storage = initOrderStorage("../db/db.sqlite");
    auto orders = storage.get_all<order>(where(is_equal(&order::status, waitingForDriver)));
    auto i = orders.begin();
    while (i < orders.end()) {
        if (i->type > currentCar.type) {
            orders.erase(i);
        }
    }
    return orders;
}

bool driverGateway::takeOrder(int id) {
    auto storage = initOrderStorage("..db/db/sqlite");
    auto takenOrder = storage.get<order>(id);
    if (takenOrder.status != waitingForDriver) return false;
    takenOrder.status = inProcess;
    takenOrder.assignDriver(currentUser->id);
    currentOrder = &takenOrder;
    storage.update(*currentOrder);
    work();
    return true;
}

bool driverGateway::finishOrder() {
    currentOrder->status = finished;
    currentOrder->paid = currentOrder->from.calculateDist(currentOrder->to);
    switch (currentOrder->type) {
        case economy:
            currentOrder->paid *= 0.9;
            break;
        case comfort:
            currentOrder->paid *= 1.3;
            break;
        case comfortPlus:
            currentOrder->paid *= 1.5;
            break;
        case business:
            currentOrder->paid *= 2;
            break;
    }
    auto storage = initOrderStorage("../db/db.sqlite");
    storage.update(*currentOrder);
    return true;
}

bool driverGateway::addCar(std::string model, std::string numberPlate, std::string color, carType type) {
    auto storage = initCarsStorage("../db/db.sqlite");
    car newCar(currentUser->id, model, numberPlate, color, type);
    storage.insert(newCar);
    return true;
}



