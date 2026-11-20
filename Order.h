//
// Created by PC on 08/03/2026.
//

//#include "Date.h"

#ifndef PROYECTOANAYJORGE_ORDER_H
#define PROYECTOANAYJORGE_ORDER_H
#include <vector>

#include "Components.h"

struct OrderUnits {
    Components * components;
    int units;
};

class Order {
    vector<OrderUnits> componentsOrders;
    char orderStatus;
    float price;

public:
    Order();
    Order(char status, float price);
    void addComponents(Components * components, int units);
    float getPrice() const;
    char getStatus() const;
    void setStatus(char s);
    vector<OrderUnits> getComponentsOrders() const;
    void showOrder() const;
};


#endif //PROYECTOANAYJORGE_ORDER_H