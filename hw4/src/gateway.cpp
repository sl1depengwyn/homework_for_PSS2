
#include "../headers/gateway.h"
#include <sqlite_orm/sqlite_orm.h>
#include "../headers/user.h"
#include "../headers/order.h"
#include <iostream>

using namespace sqlite_orm;

gateway::gateway() = default;

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

inline auto initOrderStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("orders",
                                           make_column("id", &order::id, autoincrement(), primary_key()),
                                           make_column("car_type", &order::type),
                                           make_column("status", &order::status),
                                           make_column("driver", &order::driver),
                                           make_column("payed", &order::paid),
                                           make_column("card_payed", &order::cardPayed),
                                           make_column("rating", &order::rating)));
    storage.sync_schema();
    return storage;
}

void gateway::updateUser() {
    auto storage = initUsersStorage("../db/db.sqlite");
    storage.update(*currentUser);
}

bool gateway::login(std::string login, std::string password) {

    std::hash<std::string> hasher;

    auto storage = initUsersStorage("../db/db.sqlite");

    auto usr = storage.get_all<user>(where(is_equal(&user::login, login)));

    if (usr.empty()) {
        std::cout << "Such login does not exist, wanna register?" << std::endl;
        return false;
    } else if (usr[0].password == hasher(password)) {
        currentUser = &usr[0];
        isLoggedIn = true;
        return isLoggedIn;
    } else {
        return false;
    }
}

bool gateway::registerUser(std::string name, std::string login, std::string password) {

    std::hash<std::string> hasher;

    auto storage = initUsersStorage("../db/db.sqlite");

    storage.sync_schema();

    auto usr = storage.get_all<user>(where(c(&user::login) == login));

    if (!usr.empty()) {
        std::cout << "User with this login already exists, wanna login?" << std::endl;
        return false;
    } else {
        user newUser(name, login, password);
        newUser.id = storage.insert(newUser);
        currentUser = &newUser;
        isLoggedIn = true;
        return isLoggedIn;
    }
}

void gateway::quit() {
    user defaultUser;
    currentUser = &defaultUser;
    isLoggedIn = false;
}

void gateway::finishCurrentOrder() {
    auto storage = initOrderStorage("../db/db.sqlite");
    storage.insert(*currentOrder);
}


