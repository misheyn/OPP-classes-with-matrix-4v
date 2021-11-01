//
// Created by Amalia on 15.10.2021.
//

#ifndef LAB1_3_RECTANGULARMATRIX_H
#define LAB1_3_RECTANGULARMATRIX_H

#include "Matrix.h"


class RectangularMatrix : public Matrix {
public:
    RectangularMatrix();

    RectangularMatrix(int n, int m);

    RectangularMatrix(const RectangularMatrix &obj);

    double GetMatrix(int i, int j) const;

    void SetMatrix(int i, int j, double value);

    char *toString();

    void TransposeMatrix();

    friend RectangularMatrix operator+(const RectangularMatrix &m_1, const RectangularMatrix &m_2);

    friend RectangularMatrix operator-(const RectangularMatrix &m_1, const RectangularMatrix &m_2);

    RectangularMatrix &operator=(const RectangularMatrix &matrix_2);

    double &operator()(int i, int j);

private:
    int rows;
    int columns;

    static int digitCount(double **_matrix, int n, int m);
};


#endif //LAB1_3_RECTANGULARMATRIX_H
