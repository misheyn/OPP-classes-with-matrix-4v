//
// Created by Amalia on 15.10.2021.
//

#ifndef LAB1_3_IDENTITYMATRIX_H
#define LAB1_3_IDENTITYMATRIX_H

#include "Matrix.h"


class IdentityMatrix : public Matrix {
public:
    IdentityMatrix();

    IdentityMatrix(int order);

    IdentityMatrix(const IdentityMatrix &obj);

};


#endif //LAB1_3_IDENTITYMATRIX_H
