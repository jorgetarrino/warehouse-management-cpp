//
// Created by PC on 24/05/2026.
//

#ifndef PROYECTOANAYJORGE_MANUFACTURINGREQUESTLIST_H
#define PROYECTOANAYJORGE_MANUFACTURINGREQUESTLIST_H

#include "ManufacturingRequest.h"
#include <vector>

class ManufacturingRequestList {
    vector<ManufacturingRequest*> requests;
public:
    ManufacturingRequestList();
    ~ManufacturingRequestList();

    void addRequest(ManufacturingRequest* r);
    void removeRequest(int n);
    ManufacturingRequest* getRequest(int n) const;
    int getSize() const;
};

#endif //PROYECTOANAYJORGE_MANUFACTURINGREQUESTLIST_H