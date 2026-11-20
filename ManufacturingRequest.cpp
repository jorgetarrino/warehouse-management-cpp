//
// Created by PC on 08/03/2026.
//
#include "ManufacturingRequest.h"
#include <iostream>
using namespace std;

ManufacturingRequest::ManufacturingRequest(const Date& date, Components* component, int units) {
    dateRequested = date;
    this->component = component;
    unitsToManufacture = units;
    unitsManufactured = 0;
}

Date ManufacturingRequest::getDateRequested() const {
    return dateRequested;
}

Components* ManufacturingRequest::getComponent() const {
    return component;
}

int ManufacturingRequest::getUnitsToManufacture() const {
    return unitsToManufacture;
}

int ManufacturingRequest::getUnitsManufactured() const {
    return unitsManufactured;
}

void ManufacturingRequest::setUnitsManufactured(int n) {
    unitsManufactured = n;
}

bool ManufacturingRequest::isCompleted() const {
    return unitsManufactured >= unitsToManufacture;
}

void ManufacturingRequest::showInfo() const {
    cout << "Date requested: ";
    dateRequested.showDate();
    cout << "Component: ";
    component->showInfo();
    cout << "Units to manufacture: " << unitsToManufacture << endl;
    cout << "Units manufactured: " << unitsManufactured << endl;
}