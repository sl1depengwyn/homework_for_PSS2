#include "../headers/gateway.h"
#include <iostream>

using namespace sqlite_orm;

gateway::gateway() = default;

userStorage gateway::initUsersStorage(const std::string &path) {
    userStorage storage = make_storage(path,
                                       make_table("users",
                                                  make_column("id", &user::id, autoincrement(), primary_key()),
                                                  make_column("login", &user::login, unique()),
                                                  make_column("password", &user::password),
                                                  make_column("name", &user::name),
                                                  make_column("is_allowed_to_make_order", &user::canMakeOrders),
                                                  make_column("is_allowed_to_accept_order", &user::canAcceptOrders),
                                                  make_column("rating", &user::rating)));
    storage.sync_schema();
    return storage;
}

orderStorage gateway::initOrdersStorage(const std::string &path) {
    orderStorage storage = make_storage(path,
                                        make_table("orders",
                                                   make_column("id", &order::id, autoincrement(), primary_key()),
                                                   make_column("car_type", &order::type),
                                                   make_column("status", &order::status),
                                                   make_column("driver", &order::driver),
                                                   make_column("passenger", &order::passenger),
                                                   make_column("car", &order::car),
                                                   make_column("payed", &order::paid),
                                                   make_column("time_of_creating", &order::timeOfCreating),
                                                   make_column("card_payed", &order::cardPayed)));
    storage.sync_schema();
    return storage;
}

cardsStorage gateway::initCardsStorage(const std::string &path) {
    cardsStorage storage = make_storage(path,
                                        make_table("cards",
                                                   make_column("id", &creditCard::id, autoincrement(), primary_key()),
                                                   make_column("card_number", &creditCard::cardNumber),
                                                   make_column("card_holder", &creditCard::cardHolder),
                                                   make_column("expiration_date", &creditCard::expirationDate),
                                                   make_column("cvv", &creditCard::cvv),
                                                   make_column("owner", &creditCard::userId)));
    storage.sync_schema();
    return storage;
}

addressesStorage gateway::initAddressesStorage(const std::string &path) {
    addressesStorage storage = make_storage(path,
                                            make_table("addresses",
                                                      make_column("id", &address::id, autoincrement(), primary_key()),
                                                      make_column("string_representation",
                                                                  &address::stringRepresentation),
                                                      make_column("x", &address::x),
                                                      make_column("y", &address::y),
                                                      make_column("owner_id", &address::userId)));
    storage.sync_schema();
    return storage;
}

carsStorage gateway::initCarsStorage(const std::string &path) {
    carsStorage storage = make_storage(path,
                                       make_table("cars",
                                                  make_column("id", &car::id, autoincrement(), primary_key()),
                                                  make_column("model", &car::model),
                                                  make_column("color", &car::color),
                                                  make_column("type", &car::type),
                                                  make_column("bottles", &car::bottleCount),
                                                  make_column("driver", &car::driverId),
                                                  make_column("is_validated", &car::isValidated),
                                                  make_column("x_coord", &car::x),
                                                  make_column("y_coord", &car::y)));
    storage.sync_schema();
    return storage;
}

void gateway::updateUser() {
    auto storage = initUsersStorage("../db/db.sqlite");
    storage.update(currentUser);
}

bool gateway::login(std::string login, std::string password) {

    std::hash<std::string> hasher;

    auto storage = initUsersStorage("../db/db.sqlite");

    auto usr = storage.get_all<user>(where(is_equal(&user::login, login)));

    if (usr.empty()) {
        std::cout << "Such login does not exist, wanna register?" << std::endl;
        return false;
    } else if (usr[0].password == hasher(password)) {
        currentUser = usr[0];
        isLoggedIn = true;
        return isLoggedIn;
    } else {
        return false;
    }
}

bool gateway::registerUser(std::string name, std::string login, std::string password) {

    auto storage = initUsersStorage("../db/db.sqlite");

    storage.sync_schema();

    auto usr = storage.get_all<user>(where(c(&user::login) == login));

    if (!usr.empty()) {
        std::cout << "User with this login already exists, wanna login?" << std::endl;
        return false;
    } else {
        user newUser(name, login, password);
        currentUser = newUser;
        currentUser.id = storage.insert(newUser);
        isLoggedIn = true;
        return isLoggedIn;
    }
}

void gateway::quit() {
    user defaultUser;
    currentUser = defaultUser;
    isLoggedIn = false;
}

void gateway::finishCurrentOrder() {
    auto storage = initOrdersStorage("../db/db.sqlite");
    storage.insert(currentOrder);
}



