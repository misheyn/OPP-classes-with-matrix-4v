//
// Created by Amalia on 09.09.2021.
//

#ifndef LAB1_3_MATRIX_H
#define LAB1_3_MATRIX_H

#include <iostream>
using namespace std;

class Matrix {

public:
    Matrix();

    Matrix(int order);

    Matrix(const Matrix &obj);

    ~Matrix();

    double GetMatrix(int i, int j) const;

    void SetMatrix(int i, int j, int value);

    char *toString();

    void TransposeMatrix();

    friend Matrix operator+(const Matrix &m_1, const Matrix &m_2);

    friend Matrix operator-(const Matrix &m_1, const Matrix &m_2);

    Matrix &operator=(const Matrix &matrix_2);

    double &operator()(int i, int j);

    double operator()();

    friend ostream& operator <<(ostream& os, const Matrix& m);

    friend istream& operator >>(istream& os, Matrix& m);

private:
    int order;
    double **matrix;

    static int strCat(char *buf, int len, char elem);

    static int digitCount(double **_matrix, int _order);
};

#endif //LAB1_3_MATRIX_H
