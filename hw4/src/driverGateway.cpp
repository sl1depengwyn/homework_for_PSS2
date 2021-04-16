#include "../headers/driverGateway.h"


driverGateway::driverGateway() = default;

using namespace sqlite_orm;

inline auto initUsersStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("users",
                                           make_column("id", &user::id, autoincrement(), primary_key()),
                                           make_column("login", &user::login, unique()),
                                           make_column("password", &user::password),
                                           make_column("name", &user::name),
                                           make_column("rating", &user::rating)));
    storage.sync_schema();
    return storage;
}

inline auto initCarsStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("cars",
                                           make_column("id", &car::id, autoincrement(), primary_key()),
                                           make_column("model", &car::model),
                                           make_column("color", &car::color),
                                           make_column("type", &car::type),
                                           make_column("bottles", &car::bottleCount),
                                           make_column("x_coord", &car::x),
                                           make_column("y_coord", &car::y)));
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
                                           make_column("car", &order::car),
                                           make_column("payed", &order::paid),
                                           make_column("time_of_creating", &order::timeOfCreating),
                                           make_column("card_payed", &order::cardPayed)));
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
    if (currentCar.id == -1) {
        std::cout << "You have no car" << std::endl;
        return false;
    }
    auto storage = initOrderStorage("..db/db/sqlite");
    auto takenOrder = storage.get<order>(id);
    if (takenOrder.status != waitingForDriver) return false;
    takenOrder.status = inProcess;
    takenOrder.assignDriver(currentUser->id);
    currentOrder = &takenOrder;
    currentOrder->car = currentCar.id;
    storage.update(*currentOrder);
    work();
    return true;
}

bool driverGateway::finishOrder(int rating) {
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
    if (rating != -1) {
        auto userStorage = initUsersStorage("../db/db.sqlite");
        auto passenger = userStorage.get<user>(currentOrder->passenger);
        passenger.updateRating(rating);
        userStorage.update(passenger);
    }
    return true;
}

bool driverGateway::addCar(std::string model, std::string numberPlate, std::string color, carType type) {
    auto storage = initCarsStorage("../db/db.sqlite");
    car newCar(currentUser->id, model, numberPlate, color, type);
    newCar.id = storage.insert(newCar);
    return true;
}



