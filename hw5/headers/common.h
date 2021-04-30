#pragma once

//#ifndef HW4_COMMON_H
//#define HW4_COMMON_H

#include <string>
#include <iostream>
#include <memory>
#include <sqlite_orm/sqlite_orm.h>
#include <cassert>

struct creditCard {
    int id;
    std::string cardNumber;
    std::string cardHolder;
    std::string expirationDate;
    int cvv;
    int userId;
};

enum carType {
    economy,
    comfort,
    comfortPlus,
    business,
};


enum orderStatus {
    justCreated,
    cancelled,
    waitingForDriver,
    inProcess,
    finished,
};

std::string carTypeToString(carType type);

std::unique_ptr<carType> carTypeFromString(std::string type);

std::string orderStatusToString(orderStatus status);

std::unique_ptr<orderStatus> orderStatusFromString(std::string type);

namespace sqlite_orm {

    template<>
    struct type_printer<carType> : public text_printer {
    };

    template<>
    struct type_printer<orderStatus> : public text_printer {
    };

    template<>
    struct statement_binder<carType> {
        int bind(sqlite3_stmt *stmt, int index, const carType &value);
    };

    template<>
    struct statement_binder<orderStatus> {
        int bind(sqlite3_stmt *stmt, int index, const orderStatus &value);
    };

    template<>
    struct field_printer<carType> {
        std::string operator()(const carType &t) const;
    };

    template<>
    struct field_printer<orderStatus> {
        std::string operator()(const orderStatus &t) const;
    };

    template<>
    struct row_extractor<carType> {
        carType extract(const char *row_value);

        carType extract(sqlite3_stmt *stmt, int columnIndex);
    };

    template<>
    struct row_extractor<orderStatus> {
        orderStatus extract(const char *row_value);

        orderStatus extract(sqlite3_stmt *stmt, int columnIndex);
    };
}

//#endif //HW4_COMMON_H
