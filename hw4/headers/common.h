#pragma once

//#ifndef HW4_COMMON_H
//#define HW4_COMMON_H

#include <string>
#include <iostream>
#include <memory>
#include <sqlite_orm/sqlite_orm.h>
#include <cassert>


enum carType {
    economy,
    comfort,
    comfortPlus,
    business,
};

enum paymentMethod {
    cash,
    card,
    googlePay,
    applePay,
};

std::string carTypeToString(carType type);

std::unique_ptr<carType> carTypeFromString(std::string type);

std::string paymentMethodToString(paymentMethod method);

std::unique_ptr<paymentMethod> paymentMethodFromString(std::string method);

//namespace sqlite_orm {
//
//    /**
//     *  First of all is a type_printer template class.
//     *  It is responsible for sqlite type string representation.
//     *  We want Gender to be `TEXT` so let's just derive from
//     *  text_printer. Also there are other printers: real_printer and
//     *  integer_printer. We must use them if we want to map our type to `REAL` (double/float)
//     *  or `INTEGER` (int/long/short etc) respectively.
//     */
//    template<>
//    struct type_printer<carType>;
//
//    /**
//     *  This is a binder class. It is used to bind c++ values to sqlite queries.
//     *  Here we have to create gender string representation and bind it as string.
//     *  Any statement_binder specialization must have `int bind(sqlite3_stmt*, int, const T&)` function
//     *  which returns bind result. Also you can call any of `sqlite3_bind_*` functions directly.
//     *  More here https://www.sqlite.org/c3ref/bind_blob.html
//     */
//    template<>
//    struct statement_binder<carType> {
//        int bind(sqlite3_stmt *stmt, int index, const carType &value);
//    };
//
//    /**
//     *  field_printer is used in `dump` and `where` functions. Here we have to create
//     *  a string from mapped object.
//     */
//    template<>
//    struct field_printer<carType> {
//        std::string operator()(const carType &t) const;
//    };
//
//    /**
//     *  This is a reverse operation: here we have to specify a way to transform string received from
//     *  database to our Gender object. Here we call `GenderFromString` and throw `std::runtime_error` if it returns
//     *  nullptr. Every `row_extractor` specialization must have `extract(const char*)` and `extract(sqlite3_stmt *stmt,
//     * int columnIndex)` functions which return a mapped type value.
//     */
//    template<>
//    struct row_extractor<carType> {
//        carType extract(const char *row_value);
//
//        carType extract(sqlite3_stmt *stmt, int columnIndex);
//    };
//}

//#endif //HW4_COMMON_H
