//
// Created by Amalia on 09.09.2021.
//

#ifndef LAB1_3_MATRIX_H
#define LAB1_3_MATRIX_H

class Matrix {
public:
    Matrix();

    Matrix(int order);

    Matrix(const Matrix &matrix_2);

    ~Matrix();

    int GetMatrix(int i, int j) const;

    void SetMatrix(int i, int j, int value);

    char *toString() const;

    void TransposeMatrix();

    Matrix operator+(const Matrix &matrix_2);

    Matrix &operator=(const Matrix &matrix_2);

    int &operator()(int i, int j);

private:
    int order;
    int **matrix;

    static int strCat(char *buf, int len, char elem);
    static int digitCount(int** _matrix, int _order);
};

#endif //LAB1_3_MATRIX_H
