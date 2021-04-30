cmake_minimum_required(VERSION 3.17)
project(hw4)

find_package(SqliteOrm REQUIRED)

add_executable(hw4 src/main.cpp src/driverGateway.cpp headers/driverGateway.h src/passengerGateway.cpp headers/passengerGateway.h src/car.cpp headers/car.h src/user.cpp headers/user.h src/order.cpp headers/order.h headers/common.h src/common.cpp headers/address.h src/address.cpp headers/gateway.h src/gateway.cpp)

target_link_libraries(hw4 PUBLIC sqlite_orm::sqlite_orm)


