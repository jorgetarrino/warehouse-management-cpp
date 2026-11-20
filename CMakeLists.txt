cmake_minimum_required(VERSION 4.1)
project(proyectoAnayJorge)

set(CMAKE_CXX_STANDARD 11)

add_executable(proyectoAnayJorge main.cpp
        User.cpp
        User.h
        Admin.cpp
        Admin.h
        Client.cpp
        Client.h
        Manager.cpp
        Manager.h
        Components.cpp
        Components.h
        Motor.cpp
        Motor.h
        TransmissionTree.cpp
        TransmissionTree.h
        Date.cpp
        Date.h
        Order.cpp
        Order.h
        ManufacturingRequest.cpp
        ManufacturingRequest.h
        UserList.cpp
        UserList.h
        ComponentsList.cpp
        ComponentsList.h
        OrdersList.cpp
        OrdersList.h
        ManufacturingRequestList.cpp
        ManufacturingRequestList.h
        System.cpp
        System.h)
