//
// Created by PC on 08/03/2026.
//

#include "Components.h"

#include <iostream>

Components::Components() {
    serialNumber = " ";
    fabricationTime = 0;
    price = 0;
    numberStock = 0;
}

Components::Components(const string &serialNumber, int fabricationTime, float price, int numberStock) {
    this->serialNumber = serialNumber;
    this->fabricationTime = fabricationTime;
    this->price = price;
    this->numberStock = numberStock;
}


void Components::setSerialNumber(const string &serialNumber) {
    this->serialNumber = serialNumber;
}

string Components::getSerialNumber() const {
    return this->serialNumber;
}

void Components::setFabricationTime(int n) {
    this->fabricationTime = n;
}

int Components::getFabricationTime() const {
    return this->fabricationTime;
}

void Components::setPrice(float price) {
    this->price = price;
}

float Components::getPrice() const {
    return this->price;
}


void Components::setNumberStock(int n) {
    this->numberStock = n;
}

int Components::getNumberStock() const {
    return this->numberStock;
}
