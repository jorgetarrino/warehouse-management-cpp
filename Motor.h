//
// Created by PC on 08/03/2026.
//

#include "Components.h"

#ifndef PROYECTOANAYJORGE_MOTOR_H
#define PROYECTOANAYJORGE_MOTOR_H


class Motor : public Components{
    float horsePower;
    float efficiency;
public:
    Motor();
    Motor(float horsePower, float efficiency, const string & serialNumber, int fabricationTime, float price, int numberStock);
    void setHorsePower(float horsePower);
    void setEfficiency(float efficiency);
    void showInfo() const override;
    float getHorsePower() const;
    float getEfficiency() const;
};


#endif //PROYECTOANAYJORGE_MOTOR_H