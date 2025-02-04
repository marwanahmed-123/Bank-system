cmake_minimum_required(VERSION 3.28)
project(ProjectV2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ProjectV2
        main.cpp
        Admin.h
        Employee.h
        Client.h
        Person.h
        ClientValidation.h
        Validate.h
        EmployeeValidation.h
        BalanceServices.h
        EmployeeServices.h
        AdminServices.h
        FileManager.h
        FilesHelper.h
        Parser.h
        ClientManager.h
        EmployeeManager.h
        AdminManager.h
        EmployeeFunctionalitiesForScreen.h
        Screens.h
        Admin.cpp
        AdminManager.cpp
        AdminServices.cpp
        Employee.cpp
        FileManager.cpp
        FilesHelper.cpp
        Parser.cpp
        BalanceServices.cpp
        Client.cpp
        ClientManager.cpp
        ClientValidation.cpp
        EmployeeFunctionalitiesForScreen.cpp
        EmployeeManager.cpp
        EmployeeServices.cpp
        EmployeeValidation.cpp
        Person.cpp
        Screens.cpp
        Validate.cpp
        vectors.h
)
