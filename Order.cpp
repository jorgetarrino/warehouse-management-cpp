//
// Created by PC on 08/03/2026.
//

#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() : orderStatus(' '), price(0.0) {}

Order::Order(char status, float price) : orderStatus(status), price(price) {}

void Order::addComponents(Components *components, int units) {
    OrderUnits order;
    order.components = components;
    order.units = units;
    componentsOrders.push_back(order);
    price += components->getPrice() * units;
}

float Order::getPrice() const{
    return price;
}

char Order::getStatus() const {
    return orderStatus;
}

vector<OrderUnits> Order::getComponentsOrders() const {
    return componentsOrders;
}

void Order::setStatus(char s) {
    orderStatus = s;
}

void Order::showOrder() const {
    cout << "Order status: ";
    if (orderStatus == 'a') {
        cout << "Active" << endl;
    } else {
        cout << "Completed" << endl;
    }
    for (int i = 0; i < componentsOrders.size(); i++) {
        cout << i + 1 << ".- Units ordered: " << componentsOrders[i].units << endl;
        componentsOrders[i].components->showInfo();
    }
}
