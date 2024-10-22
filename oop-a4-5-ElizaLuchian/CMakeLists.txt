cmake_minimum_required(VERSION 3.22)
project(oop_a4_5_ElizaLuchian)

set(CMAKE_CXX_STANDARD 14)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")


include_directories(.)
include_directories(Domain)
include_directories(Repo)

add_executable(oop_a4_5_ElizaLuchian
        Domain/DateTime.cpp
        Domain/DateTime.h
        Domain/DynamicArray.h
        Domain/Event.cpp
        Domain/Event.h
        Repo/AdminRepo.cpp
        Repo/AdminRepo.h
        main.cpp
        Controller/Controller.h
        Controller/Controller.cpp
        Ui/ui.h
        Ui/ui.cpp
        Tests.h
        Tests.cpp
        Repo/UserRepo.h
        Repo/UserRepo.cpp)

