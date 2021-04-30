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

string orderStatusToString(orderStatus status) {
    switch (status) {
        case orderStatus::justCreated:
            return "justCreated";
        case orderStatus::cancelled:
            return "cancelled";
        case orderStatus::waitingForDriver:
            return "waitingForDriver";
        case orderStatus::inProcess:
            return "inProcess";
        case orderStatus::finished:
            return "finished";
    }
    throw domain_error("Invalid carType enum");
}

unique_ptr<orderStatus> orderStatusFromString(string status) {
    if (status == "justCreated") {
        return make_unique<orderStatus>(orderStatus::justCreated);
    } else if (status == "cancelled") {
        return make_unique<orderStatus>(orderStatus::cancelled);
    } else if (status == "waitingForDriver") {
        return make_unique<orderStatus>(orderStatus::waitingForDriver);
    } else if (status == "inProcess") {
        return make_unique<orderStatus>(orderStatus::inProcess);
    } else if (status == "finished") {
        return make_unique<orderStatus>(orderStatus::finished);
    }
    return nullptr;
}

namespace sqlite_orm {

    int statement_binder<carType>::bind(sqlite3_stmt *stmt, int index, const carType &value) {
        return statement_binder<std::string>().bind(stmt, index, carTypeToString(value));
    }

    int statement_binder<orderStatus>::bind(sqlite3_stmt *stmt, int index, const orderStatus &value) {
        return statement_binder<std::string>().bind(stmt, index, orderStatusToString(value));
    }

    std::string field_printer<carType>::operator()(const carType &t) const {
        return carTypeToString(t);
    }


    std::string field_printer<orderStatus>::operator()(const orderStatus &t) const {
        return orderStatusToString(t);
    }


    carType row_extractor<carType>::extract(const char *row_value) {
        if (auto type = carTypeFromString(row_value)) {
            return *type;
        } else {
            throw std::runtime_error("incorrect carType string (" + std::string(row_value) + ")");
        }
    }

    carType row_extractor<carType>::extract(sqlite3_stmt *stmt, int columnIndex) {
        auto str = sqlite3_column_text(stmt, columnIndex);
        return this->extract((const char *) str);
    }

    orderStatus row_extractor<orderStatus>::extract(const char *row_value) {
        if (auto type = orderStatusFromString(row_value)) {
            return *type;
        } else {
            throw std::runtime_error("incorrect orderStatus string (" + std::string(row_value) + ")");
        }
    }

    orderStatus row_extractor<orderStatus>::extract(sqlite3_stmt *stmt, int columnIndex) {
        auto str = sqlite3_column_text(stmt, columnIndex);
        return this->extract((const char *) str);
    }
}
