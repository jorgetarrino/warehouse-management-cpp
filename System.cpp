//
// Created by PC on 24/05/2026.
//

#include "System.h"
#include <iostream>
#include <fstream>

using namespace std;

System::System() {
    int d, m, y;
    cout << "Enter current date (dd mm yyyy): ";
    cin >> d >> m >> y;
    currentDate = Date(d, m, y);
}

void System::updateManufacturing() {
    float daysRemaining = 0;
    for (int i = 0; i < manufacturingRequestList.getSize(); i++) {
        ManufacturingRequest* req = manufacturingRequestList.getRequest(i);
        if (req->isCompleted()) continue;

        float totalDays = currentDate.daysDiff(req->getDateRequested()) + daysRemaining;
        daysRemaining = 0;

        float unitsPerDay = req->getComponent()->getFabricationTime();
        float unitsMade = totalDays * unitsPerDay;

        if (unitsMade >= req->getUnitsToManufacture()) {
            float daysUsed = (float)req->getUnitsToManufacture() / unitsPerDay;
            daysRemaining = totalDays - daysUsed;

            int newUnits = req->getUnitsToManufacture() - req->getUnitsManufactured();
            req->setUnitsManufactured(req->getUnitsToManufacture());
            int current = req->getComponent()->getNumberStock();
            req->getComponent()->setNumberStock(current + newUnits);
        } else {
            int newUnits = (int)unitsMade - req->getUnitsManufactured();
            if (newUnits > 0) {
                req->setUnitsManufactured((int)unitsMade);
                int current = req->getComponent()->getNumberStock();
                req->getComponent()->setNumberStock(current + newUnits);
            }
        }
    }
}

void System::updateActiveOrders() {
    for (int i = 0; i < userList.getSize(); i++) {
        Client* client = dynamic_cast<Client*>(userList.getUser(i));
        if (client == nullptr) continue;
        client->checkActiveOrders();
    }
}

User* System::login() {
    string userName, password;
    cout << "Username: "; cin >> userName;
    cout << "Password: "; cin >> password;

    for (int i = 0; i < userList.getSize(); i++) {
        if (userList.getUser(i)->getName() == userName &&
            userList.getUser(i)->getPassword() == password) {
            return userList.getUser(i);
        }
    }
    return nullptr;
}

void System::saveFiles() {
    ofstream fUsers("usuarios.txt");
    for (int i = 0; i < userList.getSize(); i++) {
        User* u = userList.getUser(i);
        Admin* a = dynamic_cast<Admin*>(u);
        Manager* m = dynamic_cast<Manager*>(u);
        Client* c = dynamic_cast<Client*>(u);
        if (a != nullptr) {
            fUsers << "a\n" << u->getName() << "\n" << u->getPassword() << "\n";
        } else if (m != nullptr) {
            fUsers << "m\n" << u->getName() << "\n" << u->getPassword() << "\n";
        } else if (c != nullptr) {
            fUsers << "c\n" << u->getName() << "\n" << u->getPassword() << "\n"
                   << c->getVAT() << "\n" << c->getWallet() << "\n";
        }
    }
    fUsers.close();

    ofstream fComp("componentes.txt");
    for (int i = 0; i < componentsList.getSize(); i++) {
        Components* comp = componentsList.getComponent(i);
        Motor* mo = dynamic_cast<Motor*>(comp);
        TransmissionTree* tt = dynamic_cast<TransmissionTree*>(comp);
        if (mo != nullptr) {
            fComp << "m\n" << comp->getSerialNumber() << "\n" << comp->getFabricationTime()
                  << "\n" << comp->getPrice() << "\n" << comp->getNumberStock()
                  << "\n" << mo->getHorsePower() << "\n" << mo->getEfficiency() << "\n";
        } else if (tt != nullptr) {
            fComp << "t\n" << comp->getSerialNumber() << "\n" << comp->getFabricationTime()
                  << "\n" << comp->getPrice() << "\n" << comp->getNumberStock()
                  << "\n" << tt->getNumberOfGears() << "\n" << tt->getType() << "\n";
        }
    }
    fComp.close();

    ofstream fReq("solicitudes.txt");
    for (int i = 0; i < manufacturingRequestList.getSize(); i++) {
        ManufacturingRequest* req = manufacturingRequestList.getRequest(i);
        fReq << req->getComponent()->getSerialNumber() << "\n"
             << req->getUnitsToManufacture() << "\n"
             << req->getUnitsManufactured() << "\n"
             << req->getDateRequested().getDay() << "\n"
             << req->getDateRequested().getMonth() << "\n"
             << req->getDateRequested().getYear() << "\n";
    }
    fReq.close();

    ofstream fOrders("pedidos.txt");
    for (int i = 0; i < userList.getSize(); i++) {
        Client* c = dynamic_cast<Client*>(userList.getUser(i));
        if (c == nullptr) continue;
        c->saveOrders(fOrders);
    }
    fOrders.close();

    cout << "Data saved successfully." << endl;
}

void System::loadFiles() {
    ifstream fUsers("usuarios.txt");
    if (fUsers.is_open()) {
        string type;
        while (getline(fUsers, type)) {
            string name, password;
            getline(fUsers, name);
            getline(fUsers, password);
            if (type == "a") {
                userList.addUser(new Admin(name, password, &userList, &componentsList, &manufacturingRequestList, currentDate));
            } else if (type == "m") {
                userList.addUser(new Manager(name, password, &componentsList, &manufacturingRequestList, &userList, currentDate));
            } else if (type == "c") {
                string vat, walletStr;
                getline(fUsers, vat);
                getline(fUsers, walletStr);
                userList.addUser(new Client(name, password, vat, stof(walletStr), &componentsList));
            }
        }
        fUsers.close();
    } else {
        userList.addUser(new Admin("admin", "1234", &userList, &componentsList, &manufacturingRequestList, currentDate));
    }

    ifstream fComp("componentes.txt");
    if (fComp.is_open()) {
        string type;
        while (getline(fComp, type)) {
            string serial, fabStr, priceStr, stockStr;
            getline(fComp, serial);
            getline(fComp, fabStr);
            getline(fComp, priceStr);
            getline(fComp, stockStr);
            int fab = stoi(fabStr);
            float price = stof(priceStr);
            int stock = stoi(stockStr);
            if (type == "m") {
                string hpStr, effStr;
                getline(fComp, hpStr);
                getline(fComp, effStr);
                componentsList.addComponent(new Motor(stof(hpStr), stof(effStr), serial, fab, price, stock));
            } else if (type == "t") {
                string gearsStr, transType;
                getline(fComp, gearsStr);
                getline(fComp, transType);
                componentsList.addComponent(new TransmissionTree(stoi(gearsStr), transType[0], serial, fab, price, stock));
            }
        }
        fComp.close();
    }

    ifstream fReq("solicitudes.txt");
    if (fReq.is_open()) {
        string serial;
        while (getline(fReq, serial)) {
            string unitsStr, madeStr, dStr, mStr, yStr;
            getline(fReq, unitsStr);
            getline(fReq, madeStr);
            getline(fReq, dStr);
            getline(fReq, mStr);
            getline(fReq, yStr);

            Components* comp = nullptr;
            for (int i = 0; i < componentsList.getSize(); i++) {
                if (componentsList.getComponent(i)->getSerialNumber() == serial) {
                    comp = componentsList.getComponent(i);
                    break;
                }
            }
            if (comp == nullptr) continue;

            Date date(stoi(dStr), stoi(mStr), stoi(yStr));
            ManufacturingRequest* req = new ManufacturingRequest(date, comp, stoi(unitsStr));
            req->setUnitsManufactured(stoi(madeStr));
            manufacturingRequestList.addRequest(req);
        }
        fReq.close();
    }
    ifstream fOrders("pedidos.txt");
    if (fOrders.is_open()) {
        string line;
        while (getline(fOrders, line)) {
            if (line.empty()) continue;
            string clientName = line;

            string statusStr, priceStr;
            getline(fOrders, statusStr);
            getline(fOrders, priceStr);

            Client* client = nullptr;
            for (int i = 0; i < userList.getSize(); i++) {
                Client* c = dynamic_cast<Client*>(userList.getUser(i));
                if (c != nullptr && c->getName() == clientName) {
                    client = c;
                    break;
                }
            }
            if (client == nullptr) continue;

            Order* order = new Order();
            order->setStatus(statusStr[0]);

            string numLinesStr;
            getline(fOrders, numLinesStr);
            int numLines = stoi(numLinesStr);

            for (int i = 0; i < numLines; i++) {
                string serial, unitsStr;
                getline(fOrders, serial);
                getline(fOrders, unitsStr);

                Components* comp = nullptr;
                for (int j = 0; j < componentsList.getSize(); j++) {
                    if (componentsList.getComponent(j)->getSerialNumber() == serial) {
                        comp = componentsList.getComponent(j);
                        break;
                    }
                }
                if (comp != nullptr) {
                    order->addComponents(comp, stoi(unitsStr));
                }
            }
            client->loadOrder(order);
        }
        fOrders.close();
    }
}

void System::run() {
    loadFiles();
    updateManufacturing();
    updateActiveOrders();

    bool running = true;
    while (running) {
        User* loggedUser = login();
        if (loggedUser == nullptr) {
            cout << "Invalid credentials." << endl;
        } else {
            cout << "Welcome, " << loggedUser->getName() << "!" << endl;
            loggedUser->menu();
        }

        char again;
        do {
            cout << "Login again? (y/n): ";
            cin >> again;
        } while (again != 'y' and again != 'n');
        if (again == 'n') running = false;
    }

    saveFiles();
}