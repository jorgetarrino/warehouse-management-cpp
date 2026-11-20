//
// Created by PC on 08/03/2026.
//

#include "Admin.h"

#include "Client.h"
#include "Manager.h"
#include "UserList.h"

Admin::Admin(const string & name, const string & password, UserList * ul, ComponentsList * cList, ManufacturingRequestList * mList, const Date & currentDate) {
    userList = ul;
    componentsList = cList;
    manufacturingRequestList = mList;
    this->currentDate = currentDate;
    setName(name);
    setPassword(password);
}

void Admin::registerUser() {
    char type = 'n';
    while (type != 'a' and type != 'm' and type != 'c') {
        cout << "Enter user type: " << endl;
        cout << " a - Admin" << endl;
        cout << " m - Manager" << endl;
        cout << " c - Client" << endl;
        cin >> type;
        if (type != 'a' and type != 'm' and type != 'c') {
            cout << "Error: Incorrect type entered. Try again." << endl;
        }
    }
    string userName, userPassword;
    bool nameAvailable;
    do {
        nameAvailable = true;
        cout << "Enter user name: ";
        cin >> userName;
        for (int i = 0; i < userList->getSize(); i++) {
            if (userList->getUser(i)->getName() == userName) {
                cout << "Error: Username already exists. Try again." << endl;
                nameAvailable = false;
                break;
            }
        }
    } while (!nameAvailable);

    cout << "Enter password: ";
    cin >> userPassword;

    User * u = nullptr;
    if (type == 'a') {
        u = new Admin(userName, userPassword, userList, componentsList, manufacturingRequestList, currentDate);
    } else if (type == 'm') {
        u = new Manager(userName, userPassword, componentsList, manufacturingRequestList, userList, currentDate);
    } else {
        string vat;
        float wallet;
        cout << "Enter VAT: ";
        cin >> vat;
        cout << "Enter funds: ";
        cin >> wallet;
        u = new Client(userName, userPassword, vat, wallet, componentsList);
    }
    userList->addUser(u);
    cout << "User registered successfully." << endl;
}

void Admin::modifyUser(int n) {
    User * u = userList->getUser(n);
    string userName, userPassword;
    bool nameAvailable;
    do {
        nameAvailable = true;
        cout << "Enter user name: ";
        cin >> userName;
        for (int i = 0; i < userList->getSize(); i++) {
            if (userList->getUser(i)->getName() == userName) {
                cout << "Error: Username already exists. Try again." << endl;
                nameAvailable = false;
                break;
            }
        }
    } while (!nameAvailable);

    cout << "Enter new password: ";
    cin >> userPassword;
    u->setName(userName);
    u->setPassword(userPassword);
    cout << "User modified successfully." << endl;
}

void Admin::deleteUser(int n) {
    userList->removeUser(n);
    cout << "User deleted successfully." << endl;
}

void Admin::showAllUsers() const {
    for (int i = 0; i < userList->getSize(); i++) {
        cout << i + 1 << ". ";
        userList->getUser(i)->showInfo();
        cout << endl;
    }
}

void Admin::showInfo() const {
    cout << "Admin" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Password: " << getPassword() << endl;
}


void Admin::menu() {
    bool isOn = true;
    while (isOn) {
        int index = 0;
        while (index < 1 or index > 5) {
            cout << "1.- Register User" << endl;
            cout << "2.- Modify User" << endl;
            cout << "3.- Delete User" << endl;
            cout << "4.- See users list" << endl;
            cout << "5.- Exit" << endl;
            cout << "Enter your choice: ";
            cin >> index;
            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
            if (index < 1 or index > 5) {
                cout << "Invalid choice. Try again." << endl;
            }
        }

        int num = 0;
        switch (index) {
            case 1:
                registerUser();
                break;
            case 2:
                do {
                    cout << "Enter number of the user to be modified: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > userList->getSize()) {
                        cout << "Invalid number. Try again." << endl;
                    }
                } while (num < 1 or num > userList->getSize());
                modifyUser(num - 1);
                break;
            case 3:
                do {
                    cout << "Enter user number to be deleted: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > userList->getSize()) {
                        cout << "Invalid number. Try again." << endl;
                    }
                } while (num < 1 or num > userList->getSize());
                deleteUser(num - 1);
                break;
            case 4:
                showAllUsers();
                break;
            case 5:
                isOn = false;
                break;
        }
    }
}
