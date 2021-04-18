#include "../headers/passengerGateway.h"
#include "../headers/driverGateway.h"
#include "../headers/common.h"

using namespace std;

int main() {
    passengerGateway passengerApp;
    driverGateway driverApp;


    passengerApp.makeOrder();

    passengerApp.registerUser("Mike", "l1va", "qwerty"); // weak password, Mike
    cout << passengerApp.calculatePriceForOrder(address("IU", 0, 0),
                                                address("SportComplex", 200, 300),
                                                economy) << endl;
    passengerApp.addCard("000000000000", "Mike Ivanov", "10/23", 228);
    auto cards = passengerApp.getCards();
    passengerApp.makeOrder();

    driverApp.registerUser("Ivan", "vanya", "asd123");
    auto orders = driverApp.getAvailableOrders();
    driverApp.takeOrder(orders[0].id);
    driverApp.addCar("lada2114", "O000OO16", "black", economy);
    auto cars = driverApp.getCars();
    driverApp.chooseCar(cars[0].id);
    driverApp.takeOrder(orders[0].id);
    driverApp.finishOrder(5);
    passengerApp.setRatingForLastRide(5);
    passengerApp.quit();
    passengerApp.login("liva", "qwerty");

    return 0;
}