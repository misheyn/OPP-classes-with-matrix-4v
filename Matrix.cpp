//
// Created by Amalia on 09.09.2021.
//

#include "Matrix.h"
#include <cmath>
#include <stdexcept>
using namespace std;

Matrix::Matrix() {
    this->order = 0;
    this->matrix = nullptr;
}

Matrix::Matrix(int order) {
    if (order < 1) throw invalid_argument("Incorrect matrix order");
    this->order = order;
    this->matrix = new double *[order];
    if (this->matrix == nullptr) throw "Memory denied";
    for (int i = 0; i < order; i++) {
        this->matrix[i] = new double[order];
        if (this->matrix[i] == nullptr) throw "Memory denied";
    }
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            this->matrix[i][j] = 0;
}

Matrix::Matrix(const Matrix &matrix_2) {
    this->order = matrix_2.order;
    this->matrix = new double *[matrix_2.order];
    for (int i = 0; i < order; i++) {
        this->matrix[i] = new double[matrix_2.order];
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

double Matrix::GetMatrix(int i, int j) const {
    return this->matrix[i][j];
}

void Matrix::SetMatrix(int i, int j, int value) {
    matrix[i][j] = value;
}

char *Matrix::toString() {
    int l, len;
    if (this->matrix == nullptr) return nullptr;
    l = digitCount(this->matrix, this->order);
    char *buf = new char[l + order * order];
    len = 0;
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%g", matrix[i][j]);
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

Matrix operator+(const Matrix &m_1, const Matrix &m_2) {
    Matrix temp(m_1.order);
    for (int i = 0; i < m_1.order; i++) {
        for (int j = 0; j < m_1.order; j++) {
            temp.matrix[i][j] = m_1.matrix[i][j] + m_2.matrix[i][j];
        }
    }
    return temp;
}

Matrix operator-(const Matrix &m_1, const Matrix &m_2) {
    Matrix temp(m_1.order);
    for (int i = 0; i < m_1.order; i++) {
        for (int j = 0; j < m_1.order; j++) {
            temp.matrix[i][j] = m_1.matrix[i][j] - m_2.matrix[i][j];
        }
    }
    return temp;
}

int Matrix::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}

Matrix &Matrix::operator=(const Matrix &new_m) {
    if (this != &new_m) {
        for (int i = 0; i < order; i++) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        this->order = new_m.order;
        this->matrix = new double *[new_m.order];
        for (int i = 0; i < order; i++) {
            this->matrix[i] = new double[new_m.order];
        }
        for (int i = 0; i < new_m.order; i++) {
            for (int j = 0; j < new_m.order; j++) {
                this->matrix[i][j] = new_m.matrix[i][j];
            }
        }
    }
    return *this;
}

int Matrix::digitCount(double **_matrix, int _order) {
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

double &Matrix::operator()(int i, int j) {
    return this->matrix[i][j];
}

double Matrix::operator()() {
    int scale = order;
    double **_matrix;
    double first, mult;
    double det = 1;
    _matrix = new double *[order];
    for (int i = 0; i < order; i++) {
        _matrix[i] = new double[order];
    }

    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            _matrix[i][j] = this->matrix[i][j];

    while (scale > 1) {
        if (_matrix[order - scale][order - scale] == 0) return 0;
        first = _matrix[order - scale][order - scale];
        for (int i = order - scale + 1; i < order; ++i) {
            mult = _matrix[i][order - scale] / first;
            for (int j = order - scale; j < order; ++j) {
                _matrix[i][j] -= _matrix[order - scale][j] * mult;
            }
        }
        scale--;
    }
    for (int i = 0; i < order; ++i) det *= _matrix[i][i];
    for (int i = 0; i < order; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;

    return det;
}