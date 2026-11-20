//
// Created by PC on 08/03/2026.
//

#include "TransmissionTree.h"

#include <iostream>


TransmissionTree::TransmissionTree() : numberOfGears(0), type(0), Components() {}

TransmissionTree::TransmissionTree(int numberOfGears, char type, const string &serialNumber, int fabricationTime, float price, int numberStock) : numberOfGears(numberOfGears), type(type), Components(serialNumber, fabricationTime, price, numberStock) {}

void TransmissionTree::setNumberOfGears(int numberOfGears) {
    this->numberOfGears = numberOfGears;
}

void TransmissionTree::setType(char type) {
    this->type = type;
}

void TransmissionTree::showInfo() const {
    cout << "Transmission Tree Info: " << endl;
    cout << "Number of Gears: " << numberOfGears << endl;
    cout << "Type: " << type << endl;
    cout << "Serial Number: " << getSerialNumber() << endl;
    cout << "Fabrication Time: " << getFabricationTime() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Number in Stock: " << getNumberStock() << endl;
    cout << endl;
}

int TransmissionTree::getNumberOfGears() const {
    return numberOfGears;
}

char TransmissionTree::getType() const {
    return type;
}
