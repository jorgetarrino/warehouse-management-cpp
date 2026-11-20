//
// Created by PC on 24/05/2026.
//

#include "ManufacturingRequestList.h"

ManufacturingRequestList::ManufacturingRequestList() {}

ManufacturingRequestList::~ManufacturingRequestList() {
    for (int i = 0; i < requests.size(); i++) {
        delete requests[i];
    }
}

void ManufacturingRequestList::addRequest(ManufacturingRequest* r) {
    requests.push_back(r);
}

void ManufacturingRequestList::removeRequest(int n) {
    delete requests[n];
    vector<ManufacturingRequest*> aux;
    for (int i = 0; i < n; i++) {
        aux.push_back(requests[i]);
    }
    for (int i = n + 1; i < requests.size(); i++) {
        aux.push_back(requests[i]);
    }
    requests = aux;
}

ManufacturingRequest* ManufacturingRequestList::getRequest(int n) const {
    return requests[n];
}

int ManufacturingRequestList::getSize() const {
    return requests.size();
}