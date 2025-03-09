cmake_minimum_required(VERSION 3.14)
project(bank_management_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(bank_management_system ./main.cpp)

target_link_libraries(bank_management_system PRIVATE nlohmann_json::nlohmann_json)
