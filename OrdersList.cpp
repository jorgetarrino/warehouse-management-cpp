//
// Created by PC on 14/04/2026.
//

#include "OrdersList.h"

OrdersList::OrdersList() {}

OrdersList::~OrdersList() {
    for (int i = 0; i < ordersList.size(); i++) {
        delete ordersList[i];
    }
}

void OrdersList::registerOrder(Order* o) {
    ordersList.push_back(o);
}

void OrdersList::removeOrder(int n) {
    delete ordersList[n];
    vector<Order*> aux;
    for (int i = 0; i < n; i++) {
        aux.push_back(ordersList[i]);
    }
    for (int i = n + 1; i < ordersList.size(); i++) {
        aux.push_back(ordersList[i]);
    }
    ordersList = aux;
}

Order* OrdersList::getOrder(int n) const {
    return ordersList[n];
}

int OrdersList::getSize() const {
    return ordersList.size();
}