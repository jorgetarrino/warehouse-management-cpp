//
// Created by PC on 08/03/2026.
//

#ifndef PROYECTOANAYJORGE_CLIENT_H
#define PROYECTOANAYJORGE_CLIENT_H

#include "User.h"
#include "OrdersList.h"
#include "ComponentsList.h"
#include <fstream>

class Client : public User{
    string VAT;
    float wallet;
    OrdersList ordersList;
    ComponentsList* catalogue;
public:
    Client(const string & name, const string & password, const string & vat, float wallet, ComponentsList* catalogue);
    bool seeActiveOrders();
    void makeNewOrder();
    void modifyOrder(int n);
    void cancelOrder(int n);
    void addFunds(float f);
    void seeComponentsCatalogue();
    void seeOrdersHistory();
    void checkActiveOrders();
    string getVAT() const;
    float getWallet() const;
    void showInfo() const override;
    void menu() override;
    void saveOrders(ofstream& f);
    void loadOrder(Order* o);
};


#endif //PROYECTOANAYJORGE_CLIENT_H