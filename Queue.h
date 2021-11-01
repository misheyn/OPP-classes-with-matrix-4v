//
// Created by Amalia on 28.10.2021.
//

#ifndef LAB1_3_QUEUE_H
#define LAB1_3_QUEUE_H

#include "Node.h"
#include "Matrix.h"

template<typename T>

class Queue {
public:

    Queue() : first(nullptr) {}

    void pushEnd(T &elem) {
        auto *tmp = new node(elem);
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

    void popBegin() {
        node<T> *tmp = first;
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

    T &operator[](int i) {
        node<T> *tmp = first;
        if (first != nullptr) {
            for (int j = 0; j < i; j++) {
                tmp = tmp->next;
            }
        }
        return tmp->obj;
    }

private:
    node<T> *first;
};


#endif //LAB1_3_QUEUE_H