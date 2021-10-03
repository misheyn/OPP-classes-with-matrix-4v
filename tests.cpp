//
// Created by Amalia on 29.09.2021.
//
#include "catch.hpp"
#include <iostream>
#include <cstring>
#include "Matrix.h"

using namespace std;

TEST_CASE("MatrixClass tests", "[MATRIX]") {
//
//    SECTION("Fundamental matrix work") {
//        Matrix t;
//        REQUIRE(t.toString() == nullptr);
//
//        Matrix q(2);
//        int arr_q[4] = {9, 1, -6, 18};
//        int k = 0;
//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 2; j++) {
//                q.SetMatrix(i, j, arr_q[k]);
//                k++;
//            }
//        }
//        REQUIRE(strcmp(q.toString(), "9 1\n-6 18") == 0);
//
//        Matrix A(q);
//        REQUIRE(strcmp(A.toString(), q.toString()) == 0);
//
//        REQUIRE(q.GetMatrix(0, 0) == 9);
//        REQUIRE(q.GetMatrix(1, 1) == 18);
//
//        q.TransposeMatrix();
//        REQUIRE(strcmp(q.toString(), "9 -6\n1 18") == 0);
//    }
//
//
//    SECTION("Overloaded operators") {
//        Matrix a(2);
//        int arr_a[4] = {3, 7, 12, 9};
//        int k = 0;
//        for (int i = 0; i < 2; i++)
//            for (int j = 0; j < 2; j++, k++)
//                a.SetMatrix(i, j, arr_a[k]);
//
//        int arr_b[4] = {1, 55, 2, 69};
//
//        Matrix b(2);
//        k = 0;
//        for (int i = 0; i < 2; i++) {
//            for (int j = 0; j < 2; j++, k++) {
//                b.SetMatrix(i, j, arr_b[k]);
//            }
//        }
//
//        Matrix c;
//        c = a + b;
//        REQUIRE(strcmp(c.toString(), "4 62\n14 78") == 0);
//        Matrix d;
//        d = b - a;
//        REQUIRE(strcmp(d.toString(), "-2 48\n-10 60") == 0);
//
//        REQUIRE(c(1, 0) == 14.0);
//        REQUIRE(d(0, 1) == 48.0);
//
//        REQUIRE(c() == -556.0);
//        REQUIRE(d() == 360.0);
//    }
//
//    SECTION("Exceptions tests") {
//        try {
//            Matrix k(-3);
//        } catch (exception &ex) {
//            cout << ex.what() << endl;
//        }
//        try {
//            Matrix k(0);
//        } catch (exception &ex) {
//            cout << ex.what() << endl;
//        }
//        try {
//            Matrix k('t');
//        } catch (exception &ex) {
//            cout << ex.what() << endl;
//        }
//    }

    SECTION("I / O streams") {
        Matrix v;
        cin >> v;
        cout << v;
    }
}

