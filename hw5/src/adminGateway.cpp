#include "../headers/adminGateway.h"

adminGateway::adminGateway() {

}

void adminGateway::validateCar(int id) {
    auto storage = initCarsStorage("../db/db.sqlite");
    auto carToValidate = storage.get<car>(id);
    carToValidate.isValidated = true;
    storage.update(carToValidate);
}

void adminGateway::blockPassenger(int id) {
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canMakeOrders = false;
    storage.update(userToBlock);
}

void adminGateway::blockDriver(int id) {
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canAcceptOrders = false;
    storage.update(userToBlock);
}

void adminGateway::unblockPassenger(int id) {
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canMakeOrders = true;
    storage.update(userToBlock);
}

void adminGateway::unblockDriver(int id) {
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canAcceptOrders = true;
    storage.update(userToBlock);
}
