//
// Created by PC on 08/03/2026.
//
#ifndef PROYECTOANAYJORGE_MANUFACTURINGREQUEST_H
#define PROYECTOANAYJORGE_MANUFACTURINGREQUEST_H

#include "Components.h"
#include "Date.h"

class ManufacturingRequest {
    Date dateRequested;
    Components* component;
    int unitsToManufacture;
    int unitsManufactured;
public:
    ManufacturingRequest(const Date& date, Components* component, int units);
    Date getDateRequested() const;
    Components* getComponent() const;
    int getUnitsToManufacture() const;
    int getUnitsManufactured() const;
    void setUnitsManufactured(int n);
    bool isCompleted() const;
    void showInfo() const;
};

#endif //PROYECTOANAYJORGE_MANUFACTURINGREQUEST_H