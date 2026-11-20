//
// Created by PC on 24/03/2026.
//

#ifndef PROYECTOANAYJORGE_USERLIST_H
#define PROYECTOANAYJORGE_USERLIST_H

#include "User.h"
#include <vector>

class UserList {
    vector<User*> userList;
    public:
    UserList();
    ~UserList();

    void addUser(User * u);
    void removeUser(int n);
    User * getUser(int n) const;
    int getSize() const;
};


#endif //PROYECTOANAYJORGE_USERLIST_H