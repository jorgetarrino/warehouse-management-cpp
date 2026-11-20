//
// Created by PC on 08/03/2026.
//

#include "Motor.h"
#include <iostream>

Motor::Motor() : horsePower(0), efficiency(0), Components() {}

Motor::Motor(float horsePower, float efficiency, const string & serialNumber, const int fabricationTime, float price, int numberStock) : horsePower(horsePower), efficiency(efficiency), Components(serialNumber, fabricationTime, price, numberStock) {}

void Motor::setHorsePower(float horsePower) {
    this->horsePower = horsePower;
}

void Motor::setEfficiency(float efficiency) {
    this->efficiency = efficiency;
}

void Motor::showInfo() const {
    cout << "Motor Info:" << endl;
    cout << "Horsepower: " << horsePower << endl;
    cout << "Efficiency: " << efficiency << endl;
    cout << "Serial Number: " << getSerialNumber() << endl;
    cout << "Fabrication Time: " << getFabricationTime() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Number in Stock: " << getNumberStock() << endl;
    cout << endl;
}

float Motor::getHorsePower() const {
    return horsePower;
}

float Motor::getEfficiency() const {
    return efficiency;
}