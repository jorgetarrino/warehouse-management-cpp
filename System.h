//
// Created by PC on 24/05/2026.
//

#ifndef PROYECTOANAYJORGE_SYSTEM_H
#define PROYECTOANAYJORGE_SYSTEM_H



#include "UserList.h"
#include "ComponentsList.h"
#include "ManufacturingRequestList.h"
#include "Date.h"
#include "Client.h"
#include "Admin.h"
#include "Manager.h"
#include "Motor.h"
#include "TransmissionTree.h"

class System {
    UserList userList;
    ComponentsList componentsList;
    ManufacturingRequestList manufacturingRequestList;
    Date currentDate;

    void updateManufacturing();
    void updateActiveOrders();
    User* login();

public:
    System();
    void run();
    void saveFiles();
    void loadFiles();
};

#endif //PROYECTOANAYJORGE_SYSTEM_H