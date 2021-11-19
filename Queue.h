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

    ~Queue() {
        delete[] first;
    }

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

    T popBegin() {
        node<T> *tmp = first;
        node<T> *tmp2 = tmp;
        if (first != nullptr) {
            if (first->prev != nullptr) {
                first->prev->next = first->next;
                first->next->prev = first->prev;
                first = first->next;
                delete tmp;
                return tmp2->obj;

            } else {
                delete first;
                first = nullptr;
                return tmp2->obj;
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

template<>
class Queue<int> {
public:
    static int sumInt(int n1, int n2) {
        return n1 + n2;
    }

    Queue() : first(nullptr) {}

    ~Queue() {
        delete[] first;
    }

    void pushEnd(int &elem) {
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

    int popBegin() {
        node<int> *tmp = first;
        node<int> *tmp2 = tmp;
        if (first != nullptr) {
            if (first->prev != nullptr) {
                first->prev->next = first->next;
                first->next->prev = first->prev;
                first = first->next;
                delete tmp;
                return tmp2->obj;

            } else {
                delete first;
                first = nullptr;
                return tmp2->obj;

            }
        }
    }

    int &operator[](int i) {
        node<int> *tmp = first;
        if (first != nullptr) {
            for (int j = 0; j < i; j++) {
                tmp = tmp->next;
            }
        }
        return tmp->obj;
    }

private:
    node<int> *first;
};

template<>
class Queue<float> {
public:
    static float roundFloat(float n1) {
        return roundf(n1);
    }

    Queue() : first(nullptr) {}

    ~Queue() {
        delete[] first;
    }

    void pushEnd(float &elem) {
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

    float popBegin() {
        node<float> *tmp = first;
        node<float> *tmp2 = tmp;
        if (first != nullptr) {
            if (first->prev != nullptr) {
                first->prev->next = first->next;
                first->next->prev = first->prev;
                first = first->next;
                delete tmp;
                return tmp2->obj;

            } else {
                delete first;
                first = nullptr;
                return tmp2->obj;

            }
        }
    }

    float &operator[](int i) {
        node<float> *tmp = first;
        if (first != nullptr) {
            for (int j = 0; j < i; j++) {
                tmp = tmp->next;
            }
        }
        return tmp->obj;
    }

private:
    node<float> *first;
};

#endif //LAB1_3_QUEUE_H
