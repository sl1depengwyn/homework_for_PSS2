#pragma once

//#ifndef HW4_PASSENGERGATEWAY_H
//#define HW4_PASSENGERGATEWAY_H

#include <iostream>
#include "common.h"
#include "address.h"
#include "gateway.h"

class order;
class passenger;

class passengerGateway : public gateway {
public:
    passengerGateway();
    std::vector<order> getOrderHistory();
    std::vector<creditCard> getCards();
    std::vector<address> getPinnedAddreses();
    bool addCard(std::string cardNumber, std::string cardHolder, std::string expirationDate, int cvv);
    bool addAddress(address adr);
    int calculatePriceForOrder(address from, address to, carType type);
    bool makeOrder(int cardId = -1);
    address getCurrentCoordinates();
    std::string getBill();


};


//#endif //HW4_PASSENGERGATEWAY_H
