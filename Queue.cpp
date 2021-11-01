//
// Created by Amalia on 28.10.2021.
//
#include "Node.h"
#include "Queue.h"

template <typename T>
Queue<T>::Queue() : first(nullptr) {}

template <typename T>
void Queue<T>::pushEnd(T &obj) {
    node<T> *tmp = new node(obj);
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

template <typename T>
void Queue<T>::popBegin() {
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

template <typename T>
T &Queue<T>::operator[](int i) {
    node<T> *tmp = first;
    if (first != nullptr) {
        for (int j = 0; j < i; j++) {
            tmp = tmp->next;
        }
    }
    return tmp->matrix;
}
