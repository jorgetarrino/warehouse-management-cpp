//
// Created by PC on 14/04/2026.
//

#ifndef PROYECTOANAYJORGE_ORDERSLIST_H
#define PROYECTOANAYJORGE_ORDERSLIST_H

#include "Order.h"
#include <vector>

class OrdersList {
    vector<Order *> ordersList;
    public:
    OrdersList();
    ~OrdersList();

    void registerOrder(Order * o);
    void removeOrder(int n);
    Order* getOrder(int n) const;
    int getSize() const;
};


#endif //PROYECTOANAYJORGE_ORDERSLIST_H