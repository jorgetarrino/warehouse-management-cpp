//
// Created by PC on 24/03/2026.
//

#include "UserList.h"

UserList::UserList() {

}

UserList::~UserList() {
    for (int i = 0; i < userList.size(); i++) {
        delete userList[i];
    }
}

void UserList::addUser(User *u) {
    userList.push_back(u);
}

void UserList::removeUser(int n) {
    vector<User*> aux;
    delete userList[n];
    for (int i = 0; i < n; i++) {
        aux.push_back(userList[i]);
    }

    for (int i = n + 1; i < userList.size(); i++) {
        aux.push_back(userList[i]);
    }
    userList = aux;
}

User * UserList::getUser(int n) const {
    return userList[n];
}

int UserList::getSize() const {
    return userList.size();
}