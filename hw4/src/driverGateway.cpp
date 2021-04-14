#include "../headers/driverGateway.h"


driverGateway::driverGateway() {

}

bool driverGateway::login(std::string login, std::string password) {
    using namespace sqlite_orm;

    std::hash<std::string> hasher;

    auto storage = make_storage("../db/db.sqlite",
                                make_table("drivers",
                                           make_column("id", &driver::id, autoincrement(), primary_key()),
                                           make_column("login", &driver::login, unique()),
                                           make_column("password", &driver::password),
                                           make_column("name", &driver::name),
                                           make_column("rating", &driver::rating)));

    storage.sync_schema();

    auto usr = storage.get_all<passenger>(where(c(&passenger::login) == login));

    if (usr.empty()) {
        std::cout << "Such login does not exist, wanna register?" << std::endl;
        return false;
    } else if (usr[0].password == hasher(password)) {
        currentUser = usr[0];
        return true;
    } else {
        return false;
    }
}


