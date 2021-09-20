//
// Created by Amalia on 09.09.2021.
//

#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {
    this->order = 0;
    this->matrix = nullptr;
}

Matrix::Matrix(int order) {
    this->order = order;
    this->matrix = new int *[order];
    for (int i = 0; i < order; i++) {
        this->matrix[i] = new int[order];
    }
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            this->matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix &matrix_2) {
    this->order = matrix_2.order;
    this->matrix = new int *[matrix_2.order];
    for (int i = 0; i < order; i++) {
        this->matrix[i] = new int[matrix_2.order];
    }
    for (int i = 0; i < matrix_2.order; i++)
        for (int j = 0; j < matrix_2.order; j++)
            this->matrix[i][j] = matrix_2.matrix[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < order; i++) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}

int Matrix::GetMatrix(int i, int j) const {
    return this->matrix[i][j];
}

void Matrix::SetMatrix(int i, int j, int value) {
    matrix[i][j] = value;
}

char *Matrix::toString() const {
    int l, len;
    if (this->matrix == nullptr) return nullptr;
    l = digitCount(this->matrix, this->order);
    char *buf = new char[l + order * order];
    len = 0;
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

void Matrix::TransposeMatrix() {
    Matrix other(this->order);
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

Matrix Matrix::operator+(const Matrix &matrix_2) {
    Matrix temp(order);
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            temp.matrix[i][j] = this->matrix[i][j] + matrix_2.matrix[i][j];
        }
    }
    return temp;
}

int Matrix::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}

Matrix &Matrix::operator=(const Matrix &matrix_2) {
    if (this != &matrix_2) {
        for (int i = 0; i < order; i++) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        this->order = matrix_2.order;
        this->matrix = new int *[matrix_2.order];
        for (int i = 0; i < order; i++) {
            this->matrix[i] = new int[matrix_2.order];
        }
        for (int i = 0; i < matrix_2.order; i++) {
            for (int j = 0; j < matrix_2.order; j++) {
                this->matrix[i][j] = matrix_2.matrix[i][j];
            }
        }
    }
    return *this;
}

int Matrix::digitCount(int **_matrix, int _order) {
    Matrix other(_order);
    for (int i = 0; i < _order; i++) {
        for (int j = 0; j < _order; j++) {
            other.matrix[i][j] = _matrix[j][i];
        }
    }
    int len;
    len = 0;
    for (int i = 0; i < _order; i++) {
        for (int j = 0; j < _order; j++) {
            while (other.matrix[i][j] > 0) {
                len++;
                other.matrix[i][j] = other.matrix[i][j] / 10;
            }
        }
    }
    return len;
}