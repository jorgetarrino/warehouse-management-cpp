//
// Created by PC on 08/03/2026.
//

#include "Client.h"
#include "Order.h"
#include <iostream>
using namespace std;

Client::Client(const string & name, const string & password, const string & vat, float wallet, ComponentsList* catalogue) {
    setName(name);
    setPassword(password);
    VAT = vat;
    this->wallet = wallet;
    this->catalogue = catalogue;
}

bool Client::seeActiveOrders() {
    bool found = false;
    for (int i = 0; i < ordersList.getSize(); i++) {
        if (ordersList.getOrder(i)->getStatus() == 'a') {
            cout << "Order " << i + 1 << ":" << endl;
            ordersList.getOrder(i)->showOrder();
            found = true;
        }
    }
    return found;
}

void Client::makeNewOrder() {
    if (catalogue->getSize() == 0) {
        cout << "No components available." << endl;
        return;
    }
    Order* order = new Order();
    bool ordering = true;
    while (ordering) {
        int index;
        int units;
        char orderChar;
        do {
            cout << "Enter component number: ";
            cin >> index;
            if (index < 1 or index > catalogue->getSize()) {
                cout << "Invalid component number. Try again." << endl;
            }
        } while (index < 1 or index > catalogue->getSize());

        do {
            cout << "Enter units: ";
            cin >> units;
            if (units <= 0) {
                cout << "Invalid units. Try again." << endl;
            }
        } while (units <= 0);

        order->addComponents(catalogue->getComponent(index-1), units);

        do {
            cout << "Anything else? (y/n): ";
            cin >> orderChar;
            if (orderChar != 'y' && orderChar != 'n') {
                cout << "Invalid component answer. Try again." << endl;
            }
        } while (orderChar != 'y' && orderChar != 'n');
        if (orderChar == 'n') {
            ordering = false;
        }
    }
    cout << "Total price: " << order->getPrice() << endl;
    cout << "Wallet: " << wallet << endl;
    if (wallet < order->getPrice()) {
        cout << "Insufficient funds, cancelling order" << endl;
        delete order;
        return;
    }

    bool stock = true;
    vector<OrderUnits> lines = order->getComponentsOrders();
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i].components->getNumberStock() < lines[i].units) {
            stock = false;
            break;
        }
    }

    if (stock) {
        for (int i = 0; i < lines.size(); i++) {
            int current = lines[i].components->getNumberStock();
            lines[i].components->setNumberStock(current - lines[i].units);
        }
        order->setStatus('c');
        cout << "Order completed immediately." << endl;
    } else {
        order->setStatus('a');
        cout << "Not enough stock. Order set to active." << endl;
    }

    wallet -= order->getPrice();
    ordersList.registerOrder(order);

}

void Client::modifyOrder(int n) {
    Order* order = ordersList.getOrder(n);
    if (order->getStatus() != 'a') {
        cout << "Order is not active, cannot be modified." << endl;
        return;
    }

    wallet += order->getPrice();

    ordersList.removeOrder(n);
    cout << "Current order cancelled. Make your new order:" << endl;
    makeNewOrder();
}

void Client::cancelOrder(int n) {
    Order* order = ordersList.getOrder(n);
    if (order->getStatus() != 'a') {
        cout << "Order is not active, cannot be cancelled." << endl;
        return;
    }
    float refund = order->getPrice();
    wallet += refund;
    ordersList.removeOrder(n);
    cout << "Order cancelled. " << refund << " refunded to wallet." << endl;
}

void Client::addFunds(float f) {
    wallet += f;
}

void Client::seeComponentsCatalogue() {
    catalogue->showCatalogue();
}

void Client::seeOrdersHistory() {
    if (ordersList.getSize() == 0) {
        cout << "No orders." << endl;
        return;
    }
    for (int i = 0; i < ordersList.getSize(); i++) {
        cout << "Order " << i + 1 << ":" << endl;
        ordersList.getOrder(i)->showOrder();
    }

}

void Client::checkActiveOrders() {
    for (int i = 0; i < ordersList.getSize(); i++) {
        Order* order = ordersList.getOrder(i);
        if (order->getStatus() != 'a') {
            continue;
        }

        bool stock = true;
        vector<OrderUnits> lines = order->getComponentsOrders();
        for (int j = 0; j < lines.size(); j++) {
            if (lines[j].components->getNumberStock() < lines[j].units) {
                stock = false;
                break;
            }
        }
        if (!stock) break;

        for (int j = 0; j < lines.size(); j++) {
            int current = lines[j].components->getNumberStock();
            lines[j].components->setNumberStock(current - lines[j].units);
        }
        order->setStatus('c');
        cout << "Order " << i + 1 << " completed." << endl;
    }
}

string Client::getVAT() const {
    return VAT;
}

float Client::getWallet() const {
    return wallet;
}

void Client::showInfo() const{
    cout << "Client" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Password: " << getPassword() << endl;
    cout << "VAT: " << getVAT() << endl;
    cout << "Wallet: " << getWallet() << endl;
}

void Client::menu() {
    bool isOn = true;
    while (isOn) {
        int index = 0;
        while (index < 1 or index > 8) {
            cout << "1.- See active orders" << endl;
            cout << "2.- Make new order" << endl;
            cout << "3.- Modify active order" << endl;
            cout << "4.- Cancel active order" << endl;
            cout << "5.- Add funds to the wallet" << endl;
            cout << "6.- See components catalogue" << endl;
            cout << "7.- See orders history" << endl;
            cout << "8.- Exit" << endl;
            cout << "Enter your choice: ";
            cin >> index;
            if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
            if (index < 1 or index > 8) {
                cout << "Invalid choice. Try again." << endl;
            }
        }

        int num = 0;
        float funds = 0;
        switch (index) {
            case 1:
                seeActiveOrders();
                break;
            case 2:
                makeNewOrder();
                break;
            case 3:
                do {
                    cout << "Enter order to be modified: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > ordersList.getSize())
                        cout << "Invalid number. Try again." << endl;
                } while (num < 1 or num > ordersList.getSize());
                modifyOrder(num - 1);
                break;
            case 4:
                do {
                    cout << "Enter order to be canceled: ";
                    cin >> num;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (num < 1 or num > ordersList.getSize())
                        cout << "Invalid number. Try again." << endl;
                } while (num < 1 or num > ordersList.getSize());
                cancelOrder(num - 1);
                break;
            case 5:
                cout << "Wallet: " << wallet << endl;
                do {
                    cout << "Enter funds to put into the wallet: ";
                    cin >> funds;
                    if (cin.fail()) { cin.clear(); cin.ignore(1000, '\n'); }
                    if (funds < 1) {
                        cout << "Invalid funds. Try again." << endl;
                    }
                } while (funds < 1);

                addFunds(funds);
                cout << "Funds added." << endl;
                cout << "Wallet: " << wallet << endl;
                break;
            case 6:
                seeComponentsCatalogue();
                break;
            case 7:
                seeOrdersHistory();
                break;
            case 8:
                isOn = false;
                break;
        }
    }
}


void Client::saveOrders(ofstream& f) {
    for (int i = 0; i < ordersList.getSize(); i++) {
        Order* order = ordersList.getOrder(i);
        vector<OrderUnits> lines = order->getComponentsOrders();
        f << getName() << "\n";
        f << order->getStatus() << "\n";
        f << order->getPrice() << "\n";
        f << lines.size() << "\n";
        for (int j = 0; j < lines.size(); j++) {
            f << lines[j].components->getSerialNumber() << "\n";
            f << lines[j].units << "\n";
        }
    }
}

void Client::loadOrder(Order* o) {
    ordersList.registerOrder(o);
}