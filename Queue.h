//
// Created by Amalia on 28.10.2021.
//

#ifndef LAB1_3_QUEUE_H
#define LAB1_3_QUEUE_H

#include "Node.h"

class Queue {
public:
    Queue();

    void pushEnd(Matrix &ob);

    void popBegin();

    Matrix &operator[](int i);

private:
    node *first;
};


#endif //LAB1_3_QUEUE_H
