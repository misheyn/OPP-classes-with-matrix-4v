//
// Created by Amalia on 09.09.2021.
//

#ifndef LAB1_3_MATRIXCLASS_H
#define LAB1_3_MATRIXCLASS_H


class MatrixClass {
public:
    MatrixClass();

    MatrixClass(int order);

    MatrixClass(const MatrixClass &matrix_2);

    ~MatrixClass();

    int GetMatrix(int i, int j) const;

    void SetMatrix(int i, int j, int value);

    char *toString() const;

    void TransposeMatrix();

    MatrixClass operator+(const MatrixClass &matrix_2);

    MatrixClass &operator=(const MatrixClass &matrix_2);

private:
    int order;
    int **matrix;

    static int strCat(char *buf, int len, char elem);
};

#endif //LAB1_3_MATRIXCLASS_H
