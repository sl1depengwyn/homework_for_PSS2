#include "../headers/passengerGateway.h"
#include "../headers/driverGateway.h"
#include "../headers/adminGateway.h"

using namespace std;

int main() {
    passengerGateway passengerApp;
    driverGateway driverApp;
    adminGateway adminApp;

    // let us have default user admin
    adminApp.login("admin", "admin"); // ha-ha classic
    passengerApp.registerUser("Mike", "l1va", "qwerty"); // weak password, Mike
    driverApp.registerUser("Ivan", "vanya", "asd123");

    passengerApp.addAddress(address("IU", 0, 0));
    auto addresses = passengerApp.getPinnedAddreses();

    cout << passengerApp.calculatePriceForOrder(addresses[0],
                                                address("SportComplex", 200, 300),
                                                economy) << endl;

    passengerApp.addCard("000000000000", "Mike Ivanov", "10/23", 228);
    auto cards = passengerApp.getCards();
    passengerApp.makeOrder(cards[0].id);

    driverApp.addCar("lada2114", "O000OO16", "black", economy);
    auto cars = driverApp.getCars();
    adminApp.validateCar(cars[0].id);
    driverApp.chooseCar(cars[0].id);
    auto orders = driverApp.getAvailableOrders();
    driverApp.takeOrder(orders[0].id);
    driverApp.finishOrder(5);
    cout << passengerApp.getBill();
    passengerApp.setRatingForLastRide(5);
    passengerApp.quit();
    driverApp.quit();

    auto users = adminApp.getAllUsers();
    adminApp.blockPassenger(users[1].id);

    passengerApp.login("l1va", "qwerty");
    cout << passengerApp.calculatePriceForOrder(address("SportComplex", 200, 300), addresses[0], economy) << endl;
    passengerApp.makeOrder();
    passengerApp.quit(); // :(
    adminApp.unblockPassenger(users[1].id); // :)
    adminApp.blockDriver(users[2].id);

    passengerApp.login("l1va", "qwerty");
    cout << passengerApp.calculatePriceForOrder(address("SportComplex", 200, 300), addresses[0], economy) << endl;
    passengerApp.makeOrder();
    driverApp.login("vanya", "asd123");
    orders = driverApp.getAvailableOrders();
    driverApp.takeOrder(orders[0].id); // :(
    driverApp.quit();

    adminApp.unblockDriver(users[2].id); // :)
    driverApp.login("vanya", "asd123");
    orders = driverApp.getAvailableOrders();
    driverApp.takeOrder(orders[0].id);
    auto currentLocation = passengerApp.getCoordinatesOfCar();
    std::cout << currentLocation.stringRepresentation << " " << currentLocation.x << " " << currentLocation.y << std::endl;
    driverApp.finishOrder();

    return 0;
}