cmake_minimum_required(VERSION 3.25)
project(HiQ_code_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(HiQ_code_test
        main.cpp classes/Room.cpp classes/User.cpp classes/Vehicle.cpp)
