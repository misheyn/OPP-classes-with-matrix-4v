//
// Created by Amalia on 28.10.2021.
//

#include "Queue.h"

Queue::Queue() {
    first = nullptr;
}

void Queue::pushEnd(Matrix &obj) {
    node *tmp = new node(obj);
    if (first != nullptr) {
        if (first->prev != nullptr) {
            first->prev->next = tmp;
            tmp->prev = first->prev;
            tmp->next = first;
            first->prev = tmp;
        } else {
            first->next = tmp;
            first->prev = tmp;
            tmp->next = first;
            tmp->prev = first;
        }

    } else {
        first = tmp;
    }
}

void Queue::popBegin() {
    node *tmp = first;
    if (first != nullptr) {
        if (first->prev != nullptr) {
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
            delete tmp;
        } else {
            delete first;
            first = nullptr;
        }
    }
}

Matrix &Queue::operator[](int i) {
    node *tmp = first;
    if (first != nullptr) {
        for (int j = 0; j < i; j++) {
            tmp = tmp->next;
        }
    }
    return tmp->matrix;
}
