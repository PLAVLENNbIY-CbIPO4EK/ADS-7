// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car* car = new Car;

    car->light = light;
    car->n = nullptr;
    car->p = nullptr;

    if (first == nullptr) {
        first = car;

        first->n = first;
        first->p = first;
    } else {
        Car* tail = first->p;

        tail->n = car;

        car->p = tail;
        car->n = first;

        first->p = car;
    }
}

int Train::getLength() {
    countOp = 0;

    if (first == nullptr) {
        return 0;
    }

    int len = 1;

    bool allOn = first->light;

    const Car* cur = first->n;

    while (cur != first) {
        len++;

        if (!cur->light) {
            allOn = false;
        }

        cur = cur->next;
    }

    if (allOn) {
        countOp = len * (len + 1);
    } else {
        countOp = len * 2;
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}
