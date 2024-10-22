cmake_minimum_required(VERSION 3.22)
project(t1_ElizaLuchian_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(t1_ElizaLuchian_1
        main.cpp
        Repository/Repo.h
        Repository/Repo.cpp
        Controller/Controller.h
        Controller/Controller.cpp
        Ui/Ui.h
        Ui/Ui.cpp
        Tests/Test.h
        Tests/Test.cpp
        Domain/Task.h
        Domain/Task.cpp
        Domain/Struct.h)
