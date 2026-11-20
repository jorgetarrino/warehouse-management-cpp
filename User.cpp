//
// Created by PC on 24/02/2026.
//

#include "User.h"

User::User() {
    _userName = "";
    _password = "";
}

User::User(string userName, string password) {
    _userName = userName;
    _password = password;
}

User::User(const User &user) {
    _userName = user._userName;
    _password = user._password;
}

User::~User() {

}

string User::getName() const{
    return _userName;
}

void User::setName(const string & userName) {
    _userName = userName;
}

string User::getPassword() const{
    return _password;

}

void User::setPassword(const string & password) {
    _password = password;
}

void User::showInfo() const {
    cout << "Generic User" << endl;
}