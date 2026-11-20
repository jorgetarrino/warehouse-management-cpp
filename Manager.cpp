//
// Created by PC on 08/03/2026.
//

#include "Manager.h"
#include "ComponentsList.h"
#include "Motor.h"
#include "TransmissionTree.h"

Manager::Manager(const string & name, const string & password, ComponentsList * c, ManufacturingRequestList * m, UserList * u, const Date & currentDate) {
    setName(name);
    setPassword(password);
    componentsList = c;
    manufacturingRequestList = m;
    userList = u;
    this->currentDate = currentDate;
}

void Manager::seeActiveOrders() {
    bool found = false;
    for (int i = 0; i < userList->getSize(); i++) {
        Client* client = dynamic_cast<Client*>(userList->getUser(i));
        if (client == nullptr) continue;
        if (client->seeActiveOrders()) found = true;
    }
    if (!found) cout << "No active orders." << endl;
}

void Manager::addNewComponent() {
    string serialNumber;
    int fabricationTime;
    float price;
    int numberStock;

    char type = 'n';
    while (type != 'm' and type != 't') {
        cout << "Enter component type: " << endl;
        cout << " m - Motor" << endl;
        cout << " t - Transmission Tree" << endl;
        cin >> type;
        if (type != 'm' and type != 't') {
            cout << "Error: Incorrect type entered. Try again." << endl;
        }
    }

    cout << "Enter serial number: ";
    cin >> serialNumber;
    cout << "Enter fabrication time: ";
    cin >> fabricationTime;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter number of stock: ";
    cin >> numberStock;

    Components* comp = nullptr;
    if (type == 'm') {
        float horsePower, efficiency;
        cout << "Enter horsepower: ";
        cin >> horsePower;
        cout << "Enter efficiency: ";
        cin >> efficiency;
        comp = new Motor(horsePower, efficiency, serialNumber, fabricationTime, price, numberStock);
    } else {
        int gears;
        char transType = 'n';
        while (transType != 'm' and transType != 'a') {
            cout << "Enter transmission type (m - Manual, a - Automatic): ";
            cin >> transType;
            if (transType != 'm' and transType != 'a') {
                cout << "Error: Incorrect type entered. Try again." << endl;
            }
        }
        cout << "Enter number of gears: ";
        cin >> gears;
        comp = new TransmissionTree(gears, transType, serialNumber, fabricationTime, price, numberStock);
    }
    componentsList->addComponent(comp);
    cout << "Component added successfully." << endl;
}

void Manager::modifyComponent(int n) {
    Components* comp = componentsList->getComponent(n);
    string serialNumber;
    int fabricationTime;
    float price;
    int numberStock;

    cout << "Enter serial number: ";
    cin >> serialNumber;
    cout << "Enter fabrication time: ";
    cin >> fabricationTime;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter number of stock: ";
    cin >> numberStock;
    comp->setSerialNumber(serialNumber);
    comp->setFabricationTime(fabricationTime);
    comp->setPrice(price);
    comp->setNumberStock(numberStock);

    Motor* m = dynamic_cast<Motor*>(comp);
    if (m != nullptr) {
        float horsePower, efficiency;
        cout << "Enter new horsepower: ";
        cin >> horsePower;
        cout << "Enter new efficiency: ";
        cin >> efficiency;
        m->setHorsePower(horsePower);
        m->setEfficiency(efficiency);
    }

    TransmissionTree* t = dynamic_cast<TransmissionTree*>(comp);
    if (t != nullptr) {
        int gears;
        char transType = 'n';
        while (transType != 'm' and transType != 'a') {
            cout << "Enter new transmission type (m - Manual, a - Automatic): ";
            cin >> transType;
        }
        cout << "Enter new number of gears: ";
        cin >> gears;
        t->setNumberOfGears(gears);
        t->setType(transType);
    }

}

void Manager::removeComponent(int n) {
    componentsList->removeComponent(n);

}

void Manager::requestNewUnits() {
    int index;
    do {
        cout << "Enter component number: ";
        cin >> index;
        if (index < 1 or index > componentsList->getSize()){
            cout << "Invalid number. Try again." << endl;
        }
    } while (index < 1 or index > componentsList->getSize());

    int units;
    do {
        cout << "Enter units to manufacture: ";
        cin >> units;
        if (units <= 0) {
            cout << "Invalid units. Try again." << endl;
        }
    } while (units <= 0);


    ManufacturingRequest* req = new ManufacturingRequest(currentDate, componentsList->getComponent(index - 1), units);
    manufacturingRequestList->addRequest(req);
    cout << "Manufacturing request added successfully." << endl;
}

void Manager::showInfo() const{
    cout << "Manager" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Password: " << getPassword() << endl;
}

void Manager::seeCatalogue() const {
    for (int i = 0; i < componentsList->getSize(); i++) {
        cout << i + 1 << ". ";
        componentsList->getComponent(i)->showInfo();
        cout << endl;
    }
}

void Manager::searchComponent() const {
    if (componentsList->getSize() == 0) {
        cout << "No components available." << endl;
        return;
    }
    char type = 'n';
    while (type != 'm' and type != 't') {
        cout << "Search by type: " << endl;
        cout << " m - Motor" << endl;
        cout << " t - Transmission Tree" << endl;
        cin >> type;
        if (type != 'm' and type != 't') {
            cout << "Invalid type. Try again." << endl;
        }
    }
    bool found = false;
    for (int i = 0; i < componentsList->getSize(); i++) {
        Components* comp = componentsList->getComponent(i);
        Motor* m = dynamic_cast<Motor*>(comp);
        TransmissionTree* t = dynamic_cast<TransmissionTree*>(comp);
        if (type == 'm' and m != nullptr) {
            cout << i + 1 << ". "; m->showInfo(); found = true;
        } else if (type == 't' and t != nullptr) {
            cout << i + 1 << ". "; t->showInfo(); found = true;
        }
    }
    if (!found) cout << "No components found." << endl;
}

void Manager::menu() {
    bool isOn = true;
    while (isOn) {
        int index = 0;
        while (index < 1 or index > 8) {
            cout << "1.- See active orders" << endl;
            cout << "2.- Add component" << endl;
            cout << "3.- Modify component" << endl;
            cout << "4.- Delete component" << endl;
            cout << "5.- Request manufacturing of units" << endl;
            cout << "6.- See catalogue of components" << endl;
            cout << "7.- Search components by type" << endl;
            cout << "8.- Exit" << endl;
            cout << "Enter your choice: ";
            cin >> index;
            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
            if (index < 1 or index > 8) {
                cout << "Invalid choice. Try again." << endl;
            }
        }

        int num = 0;
        switch (index) {
            case 1:
                seeActiveOrders();
                break;
            case 2:
                addNewComponent();
                break;
            case 3:
                do {
                    cout << "Enter component to be modified: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > componentsList->getSize()) {
                        cout << "Invalid number. Try again." << endl;
                    }
                } while (num < 1 or num > componentsList->getSize());
                modifyComponent(num - 1);
                break;
            case 4:
                do {
                    cout << "Enter component to be deleted: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > componentsList->getSize()) {
                        cout << "Invalid number. Try again." << endl;
                    }
                } while (num < 1 or num > componentsList->getSize());
                removeComponent(num - 1);
                break;
            case 5:
                requestNewUnits();
                break;
            case 6:
                seeCatalogue();
                break;
            case 7:
                searchComponent();
                break;
            case 8:
                isOn = false;
                break;
        }
    }
}
