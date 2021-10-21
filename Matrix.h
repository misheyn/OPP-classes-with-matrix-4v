//
// Created by Amalia on 09.09.2021.
//

#ifndef LAB1_3_MATRIX_H
#define LAB1_3_MATRIX_H


class Matrix {

public:
    // конструктор по умолчанию
    Matrix();
    // конструктор с параметрами
    Matrix(int dim);
    // конструктор копирования
    Matrix(const Matrix &matrix_2);
    // деструктор
    ~Matrix();
    // метод получения значения матрицы
    int GetMatrix(int i, int j) const;
    // метод устанавливающий значения матрицы
    void SetMatrix(int i, int j, int value);
    // метод получения матрицы в строковом представлении
    char *toString() const;
    // метод транспонирования матрицы
    void TransposeMatrix();
    // перегруженный оператор сложения
    Matrix operator+(const Matrix &matrix_2);
    // перегруженный оператор присваивания
    Matrix &operator=(const Matrix &matrix_2);

private:
    int order; // поле порядка матрицы
    int **matrix; // поле набора элементов матрицы
    // статичный метод сохранения символов в массив символов
    static int strCat(char *buf, int len, char elem);
    // статичный метод подсчета количества цифр в числе
    static int digitCount(int **_matrix, int _order);
};

#endif //LAB1_3_MATRIX_H
