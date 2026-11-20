//
// Created by PC on 08/03/2026.
//



#ifndef PROYECTOANAYJORGE_MANAGER_H
#define PROYECTOANAYJORGE_MANAGER_H

#include "User.h"
#include "Components.h"
#include "ComponentsList.h"
#include "ManufacturingRequestList.h"
#include "UserList.h"
#include "Client.h"
#include "Date.h"

class Manager : public User{
    ComponentsList * componentsList;
    ManufacturingRequestList * manufacturingRequestList;
    UserList * userList;
    Date currentDate;
    public:
    Manager(const string & name, const string & password, ComponentsList * c, ManufacturingRequestList * m, UserList * u, const Date & currentDate);
    void seeActiveOrders();
    void addNewComponent();
    void modifyComponent(int n);
    void removeComponent(int n);
    void requestNewUnits();
    void showInfo() const override;
    void seeCatalogue() const;
    void searchComponent() const;
    void menu() override;

};


#endif //PROYECTOANAYJORGE_MANAGER_H