#ifndef LAB1_3_NODE_H
#define LAB1_3_NODE_H

#include "Matrix.h"
template <typename T>


struct node {
    node *prev;
    node *next;
    T &obj;

    explicit node(T &elem) : prev(nullptr), next(nullptr), obj(elem) {}

};

#endif //LAB1_3_NODE_H
