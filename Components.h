//
// Created by PC on 08/03/2026.
//


#ifndef PROYECTOANAYJORGE_COMPONENTS_H
#define PROYECTOANAYJORGE_COMPONENTS_H

#include <string>

using namespace std;

class Components {
    string serialNumber;
    int fabricationTime;
    float price;
    int numberStock;
    public:
    Components();
    Components(const string & serialNumber, int fabricationTime, float price, int numberStock);
    void setSerialNumber(const string & serialNumber);
    void setFabricationTime(int n);
    void setPrice(float price);
    void setNumberStock(int n);
    string getSerialNumber() const;
    int getFabricationTime() const;
    float getPrice() const;
    int getNumberStock() const;

    virtual void showInfo() const = 0;
};


#endif //PROYECTOANAYJORGE_COMPONENTS_H