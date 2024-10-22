cmake_minimum_required(VERSION 3.22)
project(a2_3_ElizaLuchian)

set(CMAKE_CXX_STANDARD 14)

add_executable(a2_3_ElizaLuchian
        src/main.c
        src/domain/Material.c
        src/domain/Material.h
        src/repository/MaterialRepo.c
        src/repository/MaterialRepo.h
        src/domain/DynamicArray.c
        src/domain/DynamicArray.h
        src/ui/Ui.c
        src/ui/Ui.h
        src/domain/Date.c
        src/domain/Date.h
        src/controller/Controller.c
        src/controller/Controller.h
        src/tests/Tests.c
        src/tests/Tests.h
        src/domain/Operation.c
        src/domain/Operation.h
)
