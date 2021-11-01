//
// Created by Amalia on 28.10.2021.
//

#ifndef LAB1_3_NODE_H
#define LAB1_3_NODE_H

#include "Matrix.h"

struct node {
    node *prev;
    node *next;
    Matrix &matrix;

    node(Matrix &obj) : prev(nullptr), next(nullptr), matrix(obj) {}
};

#endif //LAB1_3_NODE_H
