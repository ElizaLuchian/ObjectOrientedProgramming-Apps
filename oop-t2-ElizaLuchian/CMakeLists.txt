cmake_minimum_required(VERSION 3.27)
project(oop_t2_ElizaLuchian)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_t2_ElizaLuchian
        main.cpp
        Ui.cpp
        Ui.h
        HospitalDepartment.cpp
        HospitalDepartment.h
        NeonatalUnit.cpp
        NeonatalUnit.h
        Surgery.cpp
        Surgery.h
        Controller.cpp
        Controller.h
        Exceptions/AlreadyExistsException.cpp
        Exceptions/AlreadyExistsException.h)
