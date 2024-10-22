cmake_minimum_required(VERSION 3.27)
project(untitled7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled7 main.cpp
        Domain/Courier.cpp
        Domain/Courier.h
        Domain/Package.cpp
        Domain/Package.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        GUI/CourierGUI.cpp
        GUI/CourierGUI.h
        GUI/CourierGUI.ui
        Service/Observer.cpp
        Service/Observer.h
        GUI/CompanyGUI.cpp
        GUI/CompanyGUI.h
        GUI/CompanyGUI.ui)
target_link_libraries(untitled7
        Qt::Core
        Qt::Gui
        Qt::Widgets
)