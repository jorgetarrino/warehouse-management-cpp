//
// Created by PC on 08/03/2026.
//


#ifndef PROYECTOANAYJORGE_ADMIN_H
#define PROYECTOANAYJORGE_ADMIN_H

#include "User.h"
#include "UserList.h"
#include "ComponentsList.h"
#include "ManufacturingRequestList.h"
#include "Date.h"

class Admin : public User{
    UserList * userList;
    ComponentsList * componentsList;
    ManufacturingRequestList * manufacturingRequestList;
    Date currentDate;
    public:
    Admin(const string & name, const string & password, UserList * ul, ComponentsList * cList, ManufacturingRequestList * mList, const Date & currentDate);
    void registerUser();
    void modifyUser(int n);
    void deleteUser(int n);
    void showAllUsers() const;
    void showInfo() const override;
    void menu() override;
};



#endif //PROYECTOANAYJORGE_ADMIN_H