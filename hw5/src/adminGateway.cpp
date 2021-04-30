#include "../headers/adminGateway.h"
#include <iostream>

adminGateway::adminGateway() {

}

std::vector<user> adminGateway::getAllUsers() {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return std::vector<user>();
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return std::vector<user>();
    }
    auto storage = initUsersStorage("../db/db.sqlite");
    return storage.get_all<user>();
}

std::vector<car> adminGateway::getAllCars() {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return std::vector<car>();
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return std::vector<car>();
    }
    auto storage = initCarsStorage("../db/db.sqlite");
    return storage.get_all<car>();
}

std::vector<order> adminGateway::getAllOrders() {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return std::vector<order>();
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return std::vector<order>();
    }
    auto storage = initOrdersStorage("../db/db.sqlite");
    return storage.get_all<order>();}

void adminGateway::validateCar(int id) {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return;
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return;
    }
    auto storage = initCarsStorage("../db/db.sqlite");
    auto carToValidate = storage.get<car>(id);
    carToValidate.isValidated = true;
    storage.update(carToValidate);
}

void adminGateway::blockPassenger(int id) {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return;
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return;
    }
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canMakeOrders = false;
    storage.update(userToBlock);
}

void adminGateway::blockDriver(int id) {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return;
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return;
    }
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canAcceptOrders = false;
    storage.update(userToBlock);
}

void adminGateway::unblockPassenger(int id) {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return;
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return;
    }
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canMakeOrders = true;
    storage.update(userToBlock);
}

void adminGateway::unblockDriver(int id) {
    if (!isLoggedIn) {
        std::cout << "You need to login!" << std::endl;
        return;
    }
    if (!currentUser.isAdmin) {
        std::cout << "You have no rights to do so!" << std::endl;
        return;
    }
    auto storage = initUsersStorage("../db/db.sqlite");
    auto userToBlock = storage.get<user>(id);
    userToBlock.canAcceptOrders = true;
    storage.update(userToBlock);
}
