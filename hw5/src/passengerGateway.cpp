#include <sqlite_orm/sqlite_orm.h>
#include "../headers/passengerGateway.h"
#include <ctime>
using namespace sqlite_orm;

passengerGateway::passengerGateway() {
    isLoggedIn = false;
}

std::vector<order> passengerGateway::getOrderHistory() {
    if (isLoggedIn) {
        auto storage = initOrdersStorage("../db/db.sqlite");
        return storage.get_all<order>(where(is_equal(&order::passenger, currentUser.id)));
    }
    std::cout << "Need to login" << std::endl;
    return std::vector<order>();
}

std::vector<creditCard> passengerGateway::getCards() {
    if (isLoggedIn) {
        auto storage = initCardsStorage("../db/db.sqlite");
        return storage.get_all<creditCard>(where(is_equal(&creditCard::userId, currentUser.id)));
    }
    std::cout << "Need to login" << std::endl;
    return std::vector<creditCard>();
}

std::vector<address> passengerGateway::getPinnedAddreses() {
    if (isLoggedIn) {
        auto storage = initAddressesStorage("../db/db.sqlite");
        return storage.get_all<address>(where(is_equal(&address::userId, currentUser.id)));
    }
    std::cout << "Need to login" << std::endl;
    return std::vector<address>();
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
    std::cout << "Need to login" << std::endl;
    return false;
}

bool passengerGateway::addAddress(address adr) {
    if (isLoggedIn) {
        auto storage = initAddressesStorage("../db/db.sqlite");
        adr.userId = currentUser.id;
        storage.insert(adr);
        return true;
    }
    std::cout << "Need to login" << std::endl;
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
                currentOrder.paid = dist * 0.9;
                return currentOrder.paid;
            case comfort:
                currentOrder.paid = dist * 1.3;
                return currentOrder.paid;
            case comfortPlus:
                currentOrder.paid = dist * 1.5;
                return currentOrder.paid;
            case business:
                currentOrder.paid = dist * 2;
                return currentOrder.paid;
        }
    }
    std::cout << "Need to login" << std::endl;
    return 0;
}

bool passengerGateway::makeOrder(int cardId) {
    if (!currentUser.canMakeOrders) {
        std::cout << "You are not allowed to make orders!" << std::endl;
        return false;
    }
    if (isLoggedIn) {
        if (cardId != -1) {
            auto cards = getCards();
            if (cards.size() >= cardId) {
                currentOrder.cardPayed = cardId;
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
    std::cout << "Need to login" << std::endl;
    return false;
}

address passengerGateway::getCoordinatesOfCar() {
    if (isLoggedIn) {
        currentOrder = initOrdersStorage("../db/db.sqlite").get<order>(currentOrder.id);
        auto storage = initCarsStorage("../db/db.sqlite");
        auto travellingCar = storage.get<car>(currentOrder.car);
        return address("CAR_ADDRESS", travellingCar.x, travellingCar.y);
    }
    std::cout << "Need to login" << std::endl;
    return address();
}

std::string passengerGateway::getBill() {
    if (isLoggedIn) {
        currentOrder = initOrdersStorage("../db/db.sqlite").get<order>(currentOrder.id);
        std::time_t t(currentOrder.timeOfCreating);
        std::string bill = std::asctime(localtime(&t));
        bill += "\n paid: ";
        bill += std::to_string(currentOrder.paid);
        bill += "\n driver: ";
        bill += std::to_string(currentOrder.driver);
        bill += '\n';
        return bill;
    }
    std::cout << "Need to login" << std::endl;
    return "";
}

void passengerGateway::setRatingForLastRide(int r) {
    if (isLoggedIn) {
        if (currentOrder.id != -1) {
            currentOrder = initOrdersStorage("../db/db.sqlite").get<order>(currentOrder.id);
            auto userStorage = initUsersStorage("../db/db.sqlite");
            auto driver = userStorage.get<user>(currentOrder.driver);
            driver.updateRating(r);
            userStorage.update(driver);
        }
    }
    std::cout << "Need to login" << std::endl;
}

