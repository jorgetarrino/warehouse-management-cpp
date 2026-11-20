//
// Created by PC on 08/03/2026.
//

#include "Components.h"

#ifndef PROYECTOANAYJORGE_TRANSMISSIONTREE_H
#define PROYECTOANAYJORGE_TRANSMISSIONTREE_H


class TransmissionTree : public Components{
    int numberOfGears;
    char type;
    public:
    TransmissionTree();
    TransmissionTree(int numberOfGears, char type, const string & serialNumber, int fabricationTime, float price, int numberStock);
    void setNumberOfGears(int numberOfGears);
    void setType(char type);
    void showInfo() const override;
    int getNumberOfGears() const;
    char getType() const;
};


#endif //PROYECTOANAYJORGE_TRANSMISSIONTREE_H