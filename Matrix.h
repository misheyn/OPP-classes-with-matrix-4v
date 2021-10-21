//
// Created by Amalia on 09.09.2021.
//

#ifndef LAB1_3_MATRIX_H
#define LAB1_3_MATRIX_H

class Matrix {

public:
    Matrix();

    Matrix(int dim);

    Matrix(const Matrix &matrix_2);

    ~Matrix();

    double GetMatrix(int i, int j) const;

    void SetMatrix(int i, int j, double value);

    char *toString();

    void TransposeMatrix();

    friend Matrix operator+(const Matrix &m_1, const Matrix &m_2);

    friend Matrix operator-(const Matrix &m_1, const Matrix &m_2);

    Matrix &operator=(const Matrix &matrix_2);

    double &operator()(int i, int j);

    double operator()();

private:
    int order;
    double **matrix;

    static int strCat(char *buf, int len, char elem);

    static int digitCount(double **_matrix, int _order);
};

#endif //LAB1_3_MATRIX_H
