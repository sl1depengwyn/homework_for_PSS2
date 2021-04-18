#pragma once

//#ifndef HW4_GATEWAY_H
//#define HW4_GATEWAY_H

#include <string>
#include <vector>
#include "user.h"
#include "order.h"
#include "car.h"

//class order;

typedef sqlite_orm::internal::storage_t<sqlite_orm::internal::table_t<user, sqlite_orm::internal::column_t<user, int, const int &(user::*)() const, void (user::*)(int), sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<user, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(user::*)() const, void (user::*)(std::__cxx11::basic_string<char>), sqlite_orm::constraints::unique_t<>>, sqlite_orm::internal::column_t<user, int, const int &(user::*)() const, void (user::*)(int)>, sqlite_orm::internal::column_t<user, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(user::*)() const, void (user::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<user, double, const double &(user::*)() const, void (user::*)(double)>>> userStorage;
typedef sqlite_orm::internal::storage_t<sqlite_orm::internal::table_t<order, sqlite_orm::internal::column_t<order, int, const int &(order::*)() const, void (order::*)(int), sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<order, carType, const carType &(order::*)() const, void (order::*)(carType)>, sqlite_orm::internal::column_t<order, orderStatus, const orderStatus &(order::*)() const, void (order::*)(orderStatus)>, sqlite_orm::internal::column_t<order, int, const int &(order::*)() const, void (order::*)(int)>, sqlite_orm::internal::column_t<order, int, const int &(order::*)() const, void (order::*)(int)>, sqlite_orm::internal::column_t<order, int, const int &(order::*)() const, void (order::*)(int)>, sqlite_orm::internal::column_t<order, double, const double &(order::*)() const, void (order::*)(double)>, sqlite_orm::internal::column_t<order, long long, const long long &(order::*)() const, void (order::*)(long long)>, sqlite_orm::internal::column_t<order, int, const int &(order::*)() const, void (order::*)(int)>>> orderStorage;
typedef sqlite_orm::internal::storage_t<sqlite_orm::internal::table_t<creditCard, sqlite_orm::internal::column_t<creditCard, int, const int &(creditCard::*)() const, void (creditCard::*)(int), sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<creditCard, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(creditCard::*)() const, void (creditCard::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<creditCard, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(creditCard::*)() const, void (creditCard::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<creditCard, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(creditCard::*)() const, void (creditCard::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<creditCard, int, const int &(creditCard::*)() const, void (creditCard::*)(int)>, sqlite_orm::internal::column_t<creditCard, int, const int &(creditCard::*)() const, void (creditCard::*)(int)>>> cardsStorage;
typedef sqlite_orm::internal::storage_t<sqlite_orm::internal::table_t<address, sqlite_orm::internal::column_t<address, int, const int &(address::*)() const, void (address::*)(int), sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<address, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(address::*)() const, void (address::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<address, int, const int &(address::*)() const, void (address::*)(int)>, sqlite_orm::internal::column_t<address, int, const int &(address::*)() const, void (address::*)(int)>, sqlite_orm::internal::column_t<address, int, const int &(address::*)() const, void (address::*)(int)>>> adressesStorage;
typedef sqlite_orm::internal::storage_t<sqlite_orm::internal::table_t<car, sqlite_orm::internal::column_t<car, int, const int &(car::*)() const, void (car::*)(int), sqlite_orm::constraints::autoincrement_t, sqlite_orm::constraints::primary_key_t<>>, sqlite_orm::internal::column_t<car, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(car::*)() const, void (car::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<car, std::__cxx11::basic_string<char>, const std::__cxx11::basic_string<char> &(car::*)() const, void (car::*)(std::__cxx11::basic_string<char>)>, sqlite_orm::internal::column_t<car, carType, const carType &(car::*)() const, void (car::*)(carType)>, sqlite_orm::internal::column_t<car, int, const int &(car::*)() const, void (car::*)(int)>, sqlite_orm::internal::column_t<car, int, const int &(car::*)() const, void (car::*)(int)>, sqlite_orm::internal::column_t<car, int, const int &(car::*)() const, void (car::*)(int)>, sqlite_orm::internal::column_t<car, int, const int &(car::*)() const, void (car::*)(int)>>> carsStorage;

class gateway {
protected:
    user currentUser;
    order currentOrder;
    bool isLoggedIn = false;

    void updateUser();

public:

    gateway();

    bool login(std::string login, std::string password);

    bool registerUser(std::string name, std::string login, std::string password);

    void quit();

    void finishCurrentOrder();

    static userStorage initUsersStorage(const std::string &path);

    static orderStorage initOrdersStorage(const std::string &path);

    static cardsStorage initCardsStorage(const std::string  &path);

    static  adressesStorage initAddressesStorage(const std::string  &path);

    static carsStorage initCarsStorage(const std::string &path);
};

//#endif //HW4_GATEWAY_H
