//
// Created by PC on 05/04/2026.
//

#include "ComponentsList.h"
#include <iostream>
using namespace std;

ComponentsList::ComponentsList() {

}

ComponentsList::~ComponentsList() {
    for (int i = 0; i < componentsList.size(); i++) {
        delete componentsList[i];
    }
}

void ComponentsList::addComponent(Components * c) {
    componentsList.push_back(c);
}

void ComponentsList::removeComponent(int n) {
    vector<Components*> aux;
    delete componentsList[n];
    for (int i = 0; i < n; i++) {
        aux.push_back(componentsList[i]);
    }

    for (int i = n + 1; i < componentsList.size(); i++) {
        aux.push_back(componentsList[i]);
    }
    componentsList = aux;
}

Components * ComponentsList::getComponent(int n) const {
    return componentsList[n];
}

int ComponentsList::getSize() const {
    return componentsList.size();
}

void ComponentsList::showCatalogue() const {
    for (int i = 0; i < componentsList.size(); i++) {
        cout << i + 1 << ". ";
        componentsList[i]->showInfo();
    }
}
