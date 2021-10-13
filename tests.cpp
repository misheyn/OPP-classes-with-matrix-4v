//
// Created by Amalia on 29.09.2021.
//
#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Matrix.h"

using namespace std;

TEST_CASE("MatrixClass tests", "[MATRIX]") {

    SECTION("Fundamental matrix work") {
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

    SECTION("Overloaded operators") {
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

    SECTION("Exceptions tests") {
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

    SECTION("I / O streams") {

        Matrix a(2);
        Matrix c(2);
        int arr_a[4] = {3, 59, 0, 11};
        int k = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++, k++)
                a.SetMatrix(i, j, arr_a[k]);

        fstream file;
        file.open("../text.txt", fstream::out);
        if (!file.is_open()) {
            std::cerr << "File open error" << "\n";
            exit(1);
        }
        file << a << endl;
        file.close();

        file.open("../text.txt", fstream::in);
        if (!file.is_open()) {
            std::cerr << "File open error" << "\n";
            exit(1);
        }
        file >> c;
        REQUIRE(strcmp(c.toString(), a.toString()) == 0);
        file.close();

        ofstream binFileIn;
        binFileIn.open("../binText.dat", ios::binary);
        if (!binFileIn.is_open()) {
            std::cerr << "File open error" << "\n";
            exit(1);
        }
        binFileIn << a << endl;
        binFileIn.close();

        ifstream binFileOut;
        binFileOut.open("../binText.dat", ios::binary);
        if (!binFileOut.is_open()) {
            std::cerr << "File open error" << "\n";
            exit(1);
        }
        binFileOut >> c;
        REQUIRE(strcmp(c.toString(), a.toString()) == 0);
        binFileOut.close();
    }
}

