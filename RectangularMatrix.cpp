//
// Created by Amalia on 15.10.2021.
//
#include "RectangularMatrix.h"

RectangularMatrix::RectangularMatrix() {
    rows = 0;
    columns = 0;
    matrix = nullptr;
}

RectangularMatrix::RectangularMatrix(int n, int m) {
    if (n < 1 || isalpha((char) n) || m < 1 || isalpha((char) m))
        throw invalid_argument("Invalid matrix order");
    rows = n;
    columns = m;
    order = -1;
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = 0;
}

RectangularMatrix::RectangularMatrix(const RectangularMatrix &obj) {
    rows = obj.rows;
    columns = obj.columns;
    matrix = new double *[obj.rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[obj.columns];
    }
    for (int i = 0; i < obj.rows; i++)
        for (int j = 0; j < obj.columns; j++)
            matrix[i][j] = obj.matrix[i][j];
}

RectangularMatrix::~RectangularMatrix() {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double RectangularMatrix::GetMatrix(int i, int j) const {
    if (i >= rows || j >= columns || i < 0 || j < 0)
        throw out_of_range("Out of range matrix");
    return matrix[i][j];
}

void RectangularMatrix::SetMatrix(int i, int j, int value) {
    if (i >= rows || j >= columns || i < 0 || j < 0)
        throw out_of_range("Out of range matrix");
    matrix[i][j] = value;
}

char *RectangularMatrix::toString() {
    int l, len;
    if (matrix == nullptr) return nullptr;
    l = digitCount(matrix, rows, columns);
    char *buf = new char[l + rows * columns];
    len = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%g", matrix[i][j]);
            if (j != columns - 1) {
                len += strCat(buf, len, (' '));
            }
        }
        if (i != rows - 1) {
            len += strCat(buf, len, ('\n'));

        } else {
            len += strCat(buf, len, ('\0'));
        }
    }
    return buf;
}

void RectangularMatrix::TransposeMatrix() {
    RectangularMatrix other(columns, rows);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            other.matrix[i][j] = matrix[j][i];
        }
    }
    swap(rows, columns);
    matrix = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i]  = new double [columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

int RectangularMatrix::digitCount(double **_matrix, int n, int m) {
    RectangularMatrix other(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            other.matrix[i][j] = _matrix[i][j];
        }
    }
    int len;
    len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while (other.matrix[i][j] > 0) {
                len++;
                other.matrix[i][j] = other.matrix[i][j] / 10;
            }
        }
    }
    return len;
}

RectangularMatrix operator+(const RectangularMatrix &m_1, const RectangularMatrix &m_2) {
    if (m_2.rows != m_1.rows || m_2.columns != m_1.columns)
        throw logic_error("Add/subtract matrices of different orders");
    RectangularMatrix temp(m_1.rows, m_1.columns);
    for (int i = 0; i < m_1.rows; i++) {
        for (int j = 0; j < m_1.columns; j++) {
            temp.matrix[i][j] = m_1.matrix[i][j] + m_2.matrix[i][j];
        }
    }
    return temp;
}

RectangularMatrix operator-(const RectangularMatrix &m_1, const RectangularMatrix &m_2) {
    if (m_2.rows != m_1.rows || m_2.columns != m_1.columns)
        throw logic_error("Add/subtract matrices of different orders");
    RectangularMatrix temp(m_1.rows, m_1.columns);
    for (int i = 0; i < m_1.rows; i++) {
        for (int j = 0; j < m_1.columns; j++) {
            temp.matrix[i][j] = m_1.matrix[i][j] - m_2.matrix[i][j];
        }
    }
    return temp;
}

RectangularMatrix &RectangularMatrix::operator=(const RectangularMatrix &new_m) {
    if (this != &new_m) {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        rows = new_m.rows;
        columns = new_m.columns;
        matrix = new double *[new_m.rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[new_m.columns];
        }
        for (int i = 0; i < new_m.rows; i++) {
            for (int j = 0; j < new_m.columns; j++) {
                matrix[i][j] = new_m.matrix[i][j];
            }
        }
    }
    return *this;
}

double &RectangularMatrix::operator()(int i, int j) {
    if (i > rows || j > columns || i < 0 || j < 0)
        throw out_of_range("Out of range matrix");
    return matrix[i][j];
}


