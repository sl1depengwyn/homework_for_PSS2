#include <sqlite_orm/sqlite_orm.h>
#include "../headers/passengerGateway.h"
#include "../headers/order.h"
#include "../headers/user.h"
#include "../headers/car.h"

using namespace sqlite_orm;

passengerGateway::passengerGateway() {
    isLoggedIn = false;
}

std::vector<order> passengerGateway::getOrderHistory() {
    auto storage = initOrdersStorage("../db/db.sqlite");
    return storage.get_all<order>(where(is_equal(&order::passenger, currentUser.id)));
}

std::vector<creditCard> passengerGateway::getCards() {
    auto storage = initCardsStorage("../db/db.sqlite");
    return storage.get_all<creditCard>(where(is_equal(&creditCard::userId, currentUser.id)));
}

std::vector<address> passengerGateway::getPinnedAddreses() {
    auto storage = initAddressesStorage("../db/db.sqlite");
    return storage.get_all<address>(where(is_equal(&address::userId, currentUser.id)));
}


bool passengerGateway::addCard(std::string cardNumber, std::string cardHolder, std::string expirationDate, int cvv) {
    if (isLoggedIn) {
        creditCard newCard{0,
                           cardNumber,
                           cardHolder,
                           expirationDate,
                           cvv,
                           currentUser.id};
        auto storage = initCardsStorage("../db/db.sqlite");
        newCard.id = storage.insert(newCard);
        return true;
    }
    return false;
}

bool passengerGateway::addAddress(address adr) {
    if (isLoggedIn) {
        auto storage = initAddressesStorage("../db/db.sqlite");
        storage.insert(adr);
        return true;
    }
    return false;
}

int passengerGateway::calculatePriceForOrder(address from, address to, carType type) {
    if (isLoggedIn) {
        int dist = to.calculateDist(from);
        order newOrder(from, to, type);
        newOrder.passenger = currentUser.id;
        currentOrder = newOrder;
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
    }
    return 0;
}

bool passengerGateway::makeOrder(int cardId) {
    if (isLoggedIn) {
        if (cardId != -1) {
            auto cards = getCards();
            if (cards.size() > cardId) {
                currentOrder.cardPayed = getCards()[cardId].id;
            } else {
                return false;
            }
        }
        currentOrder.status = waitingForDriver;
        currentOrder.cardPayed = cardId;
        auto storage = initOrdersStorage("../db/db.sqlite");
        currentOrder.id = storage.insert(currentOrder);
        return true;
    }
    std::cout << "need to login" << std::endl;
    return false;
}

address passengerGateway::getCoordinatesOfCar() {
    auto storage = initCarsStorage("..db/db.sqlite");
    auto travellingCar = storage.get<car>(currentOrder.car);
    return address("CAR_ADDRESS", travellingCar.x, travellingCar.y);
}

std::string passengerGateway::getBill() {
    std::string bill = "Today date\n";
    bill += currentOrder.paid;
    bill += '\n';
    bill += currentOrder.driver;
    return bill;
}

void passengerGateway::setRatingForLastRide(int r) {
    if (currentOrder.id != -1) {
        auto completeOrder = initOrdersStorage("../db/db.sqlite").get<order>(currentOrder.id);
        auto userStorage = initUsersStorage("../db/db.sqlite");
        auto driver = userStorage.get<user>(completeOrder.driver);
        driver.updateRating(r);
        userStorage.update(driver);
    }
}

