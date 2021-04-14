#include "../headers/common.h"

using namespace std;

string carTypeToString(carType type) {
    switch (type) {
        case carType::economy:
            return "economy";
        case carType::comfort:
            return "comfort";
        case carType::comfortPlus:
            return "comfortPlus";
        case carType::business:
            return "business";
    }
    throw domain_error("Invalid carType enum");
}

unique_ptr<carType> carTypeFromString(string type) {
    if (type == "economy") {
        return make_unique<carType>(carType::economy);
    } else if (type == "comfort") {
        return make_unique<carType>(carType::comfort);
    } else if (type == "comfortPlus") {
        return make_unique<carType>(carType::comfortPlus);
    } else if (type == "business") {
        return make_unique<carType>(carType::business);
    }
    return nullptr;
}

string paymentMethodToString(paymentMethod method) {
    switch (method) {
        case paymentMethod::cash:
            return "cash";
        case paymentMethod::card:
            return "card";
        case paymentMethod::googlePay:
            return "googlePay";
        case paymentMethod::applePay:
            return "applePay";
    }
    throw domain_error("Invalid paymentMethod enum");

}

std::unique_ptr<paymentMethod> paymentMethodFromString(string method) {
    if (method == "cash") {
        return make_unique<paymentMethod>(paymentMethod::cash);
    } else if (method == "card") {
        return make_unique<paymentMethod>(paymentMethod::card);
    } else if (method == "googlePay") {
        return make_unique<paymentMethod>(paymentMethod::googlePay);
    } else if (method == "applePay") {
        return make_unique<paymentMethod>(paymentMethod::applePay);
    }
    return nullptr;
}

namespace sqlite_orm {

    template<>
    struct type_printer<carType> : public text_printer {
    };

    template<>
    struct type_printer<paymentMethod> : public text_printer {
    };

    template<>
    struct statement_binder<carType> {
        int bind(sqlite3_stmt *stmt, int index, const carType &value) {
            return statement_binder<std::string>().bind(stmt, index, carTypeToString(value));
        }
    };

    template<>
    struct statement_binder<paymentMethod> {
        int bind(sqlite3_stmt *stmt, int index, const paymentMethod &value) {
            return statement_binder<std::string>().bind(stmt, index, paymentMethodToString(value));
        }
    };

    template<>
    struct field_printer<carType> {
        std::string operator()(const carType &t) const {
            return carTypeToString(t);
        }
    };

    template<>
    struct field_printer<paymentMethod> {
        std::string operator()(const paymentMethod &t) const {
            return paymentMethodToString(t);
        }
    };

    template<>
    struct row_extractor<carType> {
        carType extract(const char *row_value) {
            if (auto type = carTypeFromString(row_value)) {
                return *type;
            } else {
                throw std::runtime_error("incorrect gender string (" + std::string(row_value) + ")");
            }
        }

        carType extract(sqlite3_stmt *stmt, int columnIndex) {
            auto str = sqlite3_column_text(stmt, columnIndex);
            return this->extract((const char *) str);
        }
    };

    template<>
    struct row_extractor<paymentMethod> {
        paymentMethod extract(const char *row_value) {
            if (auto method = paymentMethodFromString(row_value)) {
                return *method;
            } else {
                throw std::runtime_error("incorrect gender string (" + std::string(row_value) + ")");
            }
        }

        paymentMethod extract(sqlite3_stmt *stmt, int columnIndex) {
            auto str = sqlite3_column_text(stmt, columnIndex);
            return this->extract((const char *) str);
        }
    };
}