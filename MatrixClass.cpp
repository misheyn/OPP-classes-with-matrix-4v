//
// Created by Amalia on 09.09.2021.
//

#include "MatrixClass.h"
#include <iostream>

MatrixClass::MatrixClass() {
    order = 0;
    matrix = nullptr;
}

MatrixClass::MatrixClass(int order) {
    this->order = order;
    this->matrix = new int *[order];
    for (int i = 0; i < order; i++) {
        matrix[i] = new int[order];
    }
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            matrix[i][j] = 0;
}

MatrixClass::MatrixClass(const MatrixClass &matrix_2) {
    this->order = matrix_2.order;
    this->matrix = new int *[matrix_2.order];
    for (int i = 0; i < order; i++) {
        matrix[i] = new int[matrix_2.order];
    }
    for (int i = 0; i < matrix_2.order; i++)
        for (int j = 0; j < matrix_2.order; j++)
            matrix[i][j] = matrix_2.matrix[i][j];
}

MatrixClass::~MatrixClass() {
    for (int i = 0; i < order; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int MatrixClass::GetMatrix(int i, int j) const {
    return matrix[i][j];
}

void MatrixClass::SetMatrix(int i, int j, int value) {
    matrix[i][j] = value;
}

char *MatrixClass::toString() const {
    char *buf = new char[100];
    *buf = '\0';
    int len = 0;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%d", matrix[i][j]);
            if (j != order - 1) {
                len += strCat(buf, len, (' '));
            }
        }
        if (i != order - 1) {
            len += strCat(buf, len, ('\n'));

        } else {
            len += strCat(buf, len, ('\0'));
        }
    }
    return buf;
}

void MatrixClass::TransposeMatrix() {
    MatrixClass other(order);
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            other.matrix[i][j] = this->matrix[j][i];
        }
    }
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

MatrixClass MatrixClass::operator+(const MatrixClass &matrix_2) {
    MatrixClass temp(order);
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            temp.matrix[i][j] = this->matrix[i][j] + matrix_2.matrix[i][j];
        }
    }
    return temp;
}

int MatrixClass::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}

MatrixClass &MatrixClass::operator=(const MatrixClass &matrix_2) {
    this->order = matrix_2.order;
    if (this->matrix != nullptr) {
        for (int i = 0; i < order; i++) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }
    this->matrix = new int *[matrix_2.order];
    for (int i = 0; i < order; i++) {
        matrix[i] = new int[matrix_2.order];
    }
    for (int i = 0; i < matrix_2.order; i++) {
        for (int j = 0; j < matrix_2.order; j++) {
            matrix[i][j] = matrix_2.matrix[i][j];
        }
    }
    return *this;
}