//
// Created by Amalia on 28.10.2021.
//

#ifndef LAB1_3_QUEUE_H
#define LAB1_3_QUEUE_H

#include "Node.h"
template <typename T>

class Queue {
public:

    Queue();

    void pushEnd(T &ob);

    void popBegin();

    T &operator[](int i);

private:
    node<T> *first;
};


#endif //LAB1_3_QUEUE_H
