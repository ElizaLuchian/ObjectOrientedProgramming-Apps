cmake_minimum_required(VERSION 3.27)
project(oop_a6_7_ElizaLuchian)

set(CMAKE_CXX_STANDARD 23)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

include_directories(.)
qt_add_executable(oop_a6_7_ElizaLuchian
        main.cpp
        main.h
        Controller/Controller.cpp
        Domain/Event.cpp
        Domain/DateTime.cpp
        Repo/FileUserRepo.cpp
        Repo/FileAdminRepo.cpp
        Tests.cpp
        Ui/ui.cpp
        Domain/Helpers.h
        Domain/Helpers.cpp
        InputValidator.cpp
        InputValidator.h
        ValidatorExceptions.h
        ValidatorExceptions.h
        RepositoryExceptions.h
        FileExceptions.h
        FileExceptions.cpp
        RepositoryExceptions.cpp
        Repo/CsvUserFile.cpp
        Repo/CsvUserFile.h
        Repo/CsvAdminFile.cpp
        Repo/CsvAdminFile.h
        Repo/HtmlUserFile.cpp
        Repo/HtmlUserFile.h
        Repo/HtmlAdminFile.cpp
        Repo/HtmlAdminFile.h
        Gui/GUI.cpp
        Gui/GUI.h
        Gui/GUI.h
        Gui/AdminWidget.cpp
        Gui/AdminWidget.h
        Gui/UserWidget.cpp
        Gui/UserWidget.h
        Action.cpp
        Action.h
        EventTableModel.cpp
        EventTableModel.h


)

target_link_libraries(oop_a6_7_ElizaLuchian PRIVATE Qt6::Widgets)

set_target_properties(oop_a6_7_ElizaLuchian PROPERTIES
        WIN32_EXECUTABLE ON
        MACOSX_BUNDLE ON
)
