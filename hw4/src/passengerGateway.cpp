#include <sqlite_orm/sqlite_orm.h>
#include "../headers/passengerGateway.h"
#include "../headers/order.h"
#include "../headers/user.h"

using namespace sqlite_orm;

passengerGateway::passengerGateway() {
    isLoggedIn = false;
}

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
                                           make_column("time_of_creating", &order::timeOfCreating),
                                           make_column("card_payed", &order::cardPayed),
                                           make_column("rating", &order::rating)));
    storage.sync_schema();
    return storage;
}

inline auto initCardStorage(const std::string &path) {
    auto storage = make_storage(path,
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

std::vector<order> passengerGateway::getOrderHistory() {
    auto storage = initOrderStorage("../db/db.sqlite");
    return storage.get_all<order>(where(is_equal(&order::passenger, currentUser->id)));
}

std::vector<creditCard> passengerGateway::getCards() {
    auto storage = initCardStorage("../db/db.sqlite");
    return storage.get_all<creditCard>(where(is_equal(&creditCard::userId, currentUser->id)));
}

std::vector<address> passengerGateway::getPinnedAddreses() {
    auto storage = initAddressStorage("../db/db.sqlite");
    return storage.get_all<address>(where(is_equal(&address::userId, currentUser->id)));
}


bool passengerGateway::addCard(std::string cardNumber, std::string cardHolder, std::string expirationDate, int cvv) {
    if (isLoggedIn) {
        creditCard newCard{0,
                           cardNumber,
                           cardHolder,
                           expirationDate,
                           cvv,
                           currentUser->id};
        auto storage = initCardStorage("../db/db.sqlite");
        newCard.id = storage.insert(newCard);
        return true;
    }
    return false;
}

bool passengerGateway::addAddress(address adr) {
    if (isLoggedIn) {
        auto storage = initAddressStorage("../db/db.sqlite");
        storage.insert(adr);
        return true;
    }
    return false;
}

int passengerGateway::calculatePriceForOrder(address from, address to, carType type) {
    if (isLoggedIn) {
        int dist = to.calculateDist(from);
        switch (type) {
            case economy:
                return dist * 0.9;
            case comfort:
                return dist * 1.3;
            case comfortPlus:
                return dist * 1.5;
            case business:
                return dist * 2;
        }
        order newOrder(from, to, type);
        currentOrder = &newOrder;
    }
    return 0;
}

bool passengerGateway::makeOrder(int cardId) {
    if (isLoggedIn) {
        if (cardId != -1) {
            auto cards = getCards();
            if (cards.size() > cardId) {
                currentOrder->cardPayed = getCards()[cardId].id;
            } else {
                return false;
            }
        }
        currentOrder->status = waitingForDriver;
        auto storage = initOrderStorage("../db/db.sqlite");
        storage.insert(*currentOrder);
        return true;
    }
    return false;
}

address passengerGateway::getCurrentCoordinates() {
    return address();
}

std::string passengerGateway::getBill() {
    std::string bill = "Today date\n";
    bill += currentOrder->paid;
    bill += '\n';
    bill += currentOrder->driver;
    return bill;
}
