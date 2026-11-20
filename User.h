//
// Created by PC on 24/02/2026.
//

#ifndef PROYECTOANAYJORGE_USER_H
#define PROYECTOANAYJORGE_USER_H

#include <iostream>
#include <string>

using namespace std;


class User {
    string _userName;
    string _password;
public:
    User();
    User(string userName, string password);
    User(const User &user);
    virtual ~User();

    string getName() const;
    void setName(const string & name);
    string getPassword() const;
    void setPassword(const string & password);

    virtual void showInfo() const;
    virtual void menu() = 0;
};


#endif //PROYECTOANAYJORGE_USER_H