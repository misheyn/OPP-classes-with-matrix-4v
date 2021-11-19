//
// Created by Amalia on 29.09.2021.
//
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Matrix.h"
#include "IdentityMatrix.h"
#include "RectangularMatrix.h"
#include "Queue.h"

using namespace std;

TEST_CASE("Fundamental square matrix work", "[Lab 1]") {

    Matrix t;
    REQUIRE(t.toString() == nullptr);

    Matrix q(2);
    int arr_q[4] = {9, 1, -6, 18};
    int k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            q.SetMatrix(i, j, arr_q[k]);
            k++;
        }
    }
    REQUIRE(strcmp(q.toString(), "9 1\n-6 18") == 0);

    Matrix A(q);
    REQUIRE(strcmp(A.toString(), q.toString()) == 0);

    REQUIRE(q.GetMatrix(0, 0) == 9);
    REQUIRE(q.GetMatrix(1, 1) == 18);

    q.TransposeMatrix();
    REQUIRE(strcmp(q.toString(), "9 -6\n1 18") == 0);
}

TEST_CASE("Overloaded operators", "[Lab 2]") {
    Matrix a(2);
    int arr_a[4] = {3, 7, 12, 9};
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++, k++)
            a.SetMatrix(i, j, arr_a[k]);

    Matrix b(2);
    int arr_b[4] = {1, 55, 2, 69};
    k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++, k++)
            b.SetMatrix(i, j, arr_b[k]);

    Matrix c;
    c = a + b;
    REQUIRE(strcmp(c.toString(), "4 62\n14 78") == 0);
    Matrix d;
    d = b - a;
    REQUIRE(strcmp(d.toString(), "-2 48\n-10 60") == 0);

    REQUIRE(c(1, 0) == 14.0);
    REQUIRE(d(0, 1) == 48.0);

    REQUIRE(c() == -556.0);
    REQUIRE(d() == 360.0);
}

TEST_CASE("Exceptions tests", "[Lab 6]") {
    Matrix test(2);
    try {
        test.SetMatrix(5, 9, 76);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Out of range matrix") == 0);
    }

    try {
        test.GetMatrix(2, 2);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Out of range matrix") == 0);
    }

    try {
        Matrix m(-3);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Invalid matrix order") == 0);
    }

    Matrix one(2);
    int arr_a[4] = {3, 7, 12, 9};

    for (int i = 0; i < 2; i++)
        for (int j = 0, k = 0; j < 2; j++, k++)
            one.SetMatrix(i, j, arr_a[k]);

    Matrix two(3);
    int arr_b[9] = {28, 1, 0, 55, 2, 21, 69, 5, 47};

    for (int i = 0; i < 3; i++)
        for (int j = 0, k = 0; j < 3; j++, k++)
            two.SetMatrix(i, j, arr_b[k]);
    try {
        Matrix three;
        three = one + two;
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Add/subtract matrices of different orders") == 0);
    }

    try {
        Matrix four;
        four = one - two;
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Add/subtract matrices of different orders") == 0);
    }
}

TEST_CASE("I / O streams", "[Lab 3]") {

    Matrix a(2);
    Matrix c;
    double arr_a[4] = {3, 59, 0, 11};
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++, k++)
            a.SetMatrix(i, j, arr_a[k]);

    ofstream fileIn;
    fileIn.open("../text.txt");
    if (!fileIn.is_open()) {
        std::cerr << "File open error" << "\n";
        exit(1);
    }
    fileIn << a << endl;
    fileIn.close();

    ifstream fileOut;
    fileOut.open("../text.txt");
    if (!fileOut.is_open()) {
        std::cerr << "File open error" << "\n";
        exit(1);
    }
    fileOut >> c;
    fileOut.close();
    REQUIRE(strcmp(c.toString(), a.toString()) == 0);

    ofstream binFileIn;
    binFileIn.open("../binText.dat", ios::binary);
    if (!binFileIn.is_open()) {
        std::cerr << "File open error" << "\n";
        exit(1);
    }
    BinaryIn(binFileIn, a);
    binFileIn.close();

    ifstream binFileOut;
    binFileOut.open("../binText.dat", ios::binary);
    if (!binFileOut.is_open()) {
        std::cerr << "File open error" << "\n";
        exit(1);
    }
    BinaryOut(binFileOut, c);
    binFileOut.close();
    REQUIRE(strcmp(c.toString(), a.toString()) == 0);
}

TEST_CASE("Identity matrix", "[Lab 4]") {
    IdentityMatrix t;
    REQUIRE(t.toString() == nullptr);

    IdentityMatrix q(3);
    REQUIRE(strcmp(q.toString(), "1 0 0\n0 1 0\n0 0 1") == 0);

    IdentityMatrix A(q);
    REQUIRE(strcmp(A.toString(), q.toString()) == 0);


    IdentityMatrix a(2);
    IdentityMatrix b(2);
    REQUIRE(strcmp(a.toString(), "1 0\n0 1") == 0);

    Matrix c;
    c = a + b;
    REQUIRE(strcmp(c.toString(), "2 0\n0 2") == 0);
    Matrix d;
    d = b - a;
    REQUIRE(strcmp(d.toString(), "0 0\n0 0") == 0);
}

TEST_CASE("Rectangular matrix: Fundamental work", "[Lab 4]") {
    RectangularMatrix t;
    REQUIRE(t.toString() == nullptr);

    RectangularMatrix q(2, 3);
    int arr_q[6] = {9, 1, -6, 18, 3, -1};
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++, k++)
            q.SetMatrix(i, j, arr_q[k]);

    REQUIRE(strcmp(q.toString(), "9 1 -6\n18 3 -1") == 0);

    RectangularMatrix A(q);
    REQUIRE(strcmp(A.toString(), q.toString()) == 0);

    REQUIRE(q.GetMatrix(0, 0) == 9);
    REQUIRE(q.GetMatrix(1, 2) == -1);

    q.TransposeMatrix();
    REQUIRE(strcmp(q.toString(), "9 18\n1 3\n-6 -1") == 0);
}

TEST_CASE("Rectangular matrix: Overloaded operators", "[Lab 4]") {
    RectangularMatrix a(3, 2);
    int arr_a[6] = {3, 7, 12, 9, -5, 7};
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++, k++)
            a.SetMatrix(i, j, arr_a[k]);

    RectangularMatrix b(3, 2);
    int arr_b[6] = {1, 55, 2, 69, 2, -39};
    k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++, k++)
            b.SetMatrix(i, j, arr_b[k]);

    RectangularMatrix c;
    c = a + b;
    REQUIRE(strcmp(c.toString(), "4 62\n14 78\n-3 -32") == 0);
    RectangularMatrix d;
    d = b - a;
    REQUIRE(strcmp(d.toString(), "-2 48\n-10 60\n7 -46") == 0);

    REQUIRE(c(2, 1) == -32);
    REQUIRE(d(2, 0) == 7);
}

TEST_CASE("Rectangular matrix: Exceptions", "[Lab 4]") {

    RectangularMatrix test(2, 3);
    try {
        test.SetMatrix(5, 9, 76);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Out of range matrix") == 0);
    }

    try {
        test.GetMatrix(2, 4);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Out of range matrix") == 0);
    }

    try {
        RectangularMatrix m(-3, 0);
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Invalid matrix order") == 0);
    }

    RectangularMatrix one(2, 2);
    int arr_one[4] = {3, 7, 12, 9};

    for (int i = 0; i < 2; i++)
        for (int j = 0, p = 0; j < 2; j++, p++)
            one.SetMatrix(i, j, arr_one[p]);

    RectangularMatrix two(3, 3);
    int arr_two[9] = {28, 1, 0, 55, 2, 21, 69, 5, 47};

    for (int i = 0; i < 3; i++)
        for (int j = 0, p = 0; j < 3; j++, p++)
            two.SetMatrix(i, j, arr_two[p]);

    try {
        RectangularMatrix three;
        three = one + two;
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Add/subtract matrices of different orders") == 0);
    }

    try {
        RectangularMatrix four;
        four = one - two;
    } catch (exception &ex) {
        REQUIRE(strcmp(ex.what(), "Add/subtract matrices of different orders") == 0);
    }
}

TEST_CASE("Circular queue", "[Lab 5]") {
    Matrix a(2);
    int arr_a[4] = {3, 7, 12, 9};
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++, k++)
            a.SetMatrix(i, j, arr_a[k]);

    Matrix b(2);
    int arr_b[4] = {1, 55, 2, 69};
    k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++, k++)
            b.SetMatrix(i, j, arr_b[k]);
    IdentityMatrix c(2);
    IdentityMatrix d(3);
    RectangularMatrix e(2, 3);
    int arr_e[6] = {9, 1, -6, 18, 3, -1};
    k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++, k++) {
            e.SetMatrix(i, j, arr_e[k]);
        }
    }
    RectangularMatrix f(3, 2);
    int arr_f[6] = {1, 55, 2, 69, 2, -39};
    k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++, k++) {
            f.SetMatrix(i, j, arr_f[k]);
        }
    }

    Queue <Matrix>queue;
    queue.pushEnd(a);
    queue.pushEnd(b);
    queue.pushEnd(c);
    queue.pushEnd(d);
    queue.pushEnd(e);
    queue.pushEnd(f);

    REQUIRE(strcmp(queue[0].toString(), "3 7\n12 9") == 0);
    REQUIRE(strcmp(queue[1].toString(), "1 55\n2 69") == 0);
    REQUIRE(strcmp(queue[2].toString(), "1 0\n0 1") == 0);
    REQUIRE(strcmp(queue[3].toString(), "1 0 0\n0 1 0\n0 0 1") == 0);
    REQUIRE(strcmp(queue[4].toString(), "9 1 -6\n18 3 -1") == 0);
    REQUIRE(strcmp(queue[5].toString(), "1 55\n2 69\n2 -39") == 0);


    REQUIRE(strcmp(queue.popBegin().toString(), "3 7\n12 9") == 0);
    REQUIRE(strcmp(queue[0].toString(), "1 55\n2 69") == 0);

    queue.popBegin();
    queue.popBegin();
    REQUIRE(strcmp(queue.popBegin().toString(), "1 0 0\n0 1 0\n0 0 1") == 0);
    REQUIRE(strcmp(queue[0].toString(), "9 1 -6\n18 3 -1") == 0);
}

TEST_CASE("Templates <int>", "[Lab 7]") {
    Queue<int> q1;
    int n1 = 5, n2 = 1, n3 = 9;

    q1.pushEnd(n1);
    q1.pushEnd(n2);
    q1.pushEnd(n3);

    REQUIRE(q1[0] == 5);
    REQUIRE(q1[1] == 1);
    REQUIRE(q1[2] == 9);

    REQUIRE(q1.sumInt(q1[0], q1[1]) == 6);

    q1.popBegin();
    REQUIRE(q1[0] == 1);
}

TEST_CASE("Templates <float>", "[Lab 7]") {
    Queue<float> q2;
    float n1 = 2.8, n2 = 8.4, n3 = 6.6;

    q2.pushEnd(n1);
    q2.pushEnd(n2);
    q2.pushEnd(n3);

    REQUIRE(q2[0] == 2.8f);
    REQUIRE(q2[1] == 8.4f);
    REQUIRE(q2[2] == 6.6f);

    REQUIRE(q2.roundFloat(q2[0]) == 3.0);

    q2.popBegin();
    REQUIRE(q2[0] == 8.4f);
}

/*TEST_CASE("Templates <char>", "[Lab 7]") {
    Queue<char> q3;
    char n1 = 'c', n2 = 'a', n3 = 't';

    q3.pushEnd(n1);
    q3.pushEnd(n2);
    q3.pushEnd(n3);

    REQUIRE(q3[0] == 'c');
    REQUIRE(q3[1] == 'a');
    REQUIRE(q3[2] == 't');

    q3.popBegin();
    REQUIRE(q3[0] == 'a');
}*/
