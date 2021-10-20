//
// Created by Amalia on 15.10.2021.
//

#include "IdentityMatrix.h"

IdentityMatrix::IdentityMatrix() : Matrix() {}

IdentityMatrix::IdentityMatrix(int dim) : Matrix(dim) {
    for (int i = 0; i < dim; i++) matrix[i][i] = 1;
}

IdentityMatrix::IdentityMatrix(const IdentityMatrix &obj) : Matrix(obj) {}
