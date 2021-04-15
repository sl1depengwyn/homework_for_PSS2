#include "../headers/driverGateway.h"


driverGateway::driverGateway() = default;

using namespace sqlite_orm;

inline auto initUsersStorage(const std::string &path) {
    auto storage = make_storage(path,
                                make_table("cars",
                                           make_column("id", &car::id, autoincrement(), primary_key()),
                                           make_column("model", &car::model,
                                           make_column("password", &user::password),
                                           make_column("name", &user::name),
                                           make_column("rating", &user::rating)));
    storage.sync_schema();
    return storage;
}



