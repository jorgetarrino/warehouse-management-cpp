//
// Created by PC on 05/04/2026.
//

#ifndef PROYECTOANAYJORGE_COMPONENTSLIST_H
#define PROYECTOANAYJORGE_COMPONENTSLIST_H

#include "Components.h"
#include <vector>

class ComponentsList {
    vector<Components*> componentsList;
public:
    ComponentsList();
    ~ComponentsList();

    void addComponent(Components * c);
    void removeComponent(int n);
    Components * getComponent(int n) const;
    int getSize() const;
    void showCatalogue() const;

};


#endif //PROYECTOANAYJORGE_COMPONENTSLIST_H