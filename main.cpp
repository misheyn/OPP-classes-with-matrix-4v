#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "Matrix.h"
#include <cstring>
#include "catch.hpp"

using namespace std;

int main() {
    Catch::Session().run();
    return 0;
}

TEST_CASE("MatrixClass tests", "[Square]") {
    Matrix t;
    REQUIRE(t.toString() == nullptr);
    Matrix a(2);
    int arr_a[4] = {3, 7, 12, 9};
    int arr_b[4] = {1, 55, 2, 69};
    int k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a.SetMatrix(i, j, arr_a[k]);
            k++;
        }
    }
    REQUIRE(strcmp("3 7\n12 9", a.toString()) == 0);
    Matrix A(a);
    REQUIRE(strcmp(A.toString(), a.toString()) == 0);
    REQUIRE(a.GetMatrix(0, 0) == 3);
    a.TransposeMatrix();
    REQUIRE(strcmp("3 12\n7 9", a.toString()) == 0);
    Matrix b(2);
    k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            b.SetMatrix(i, j, arr_b[k]);
            k++;
        }
    }
    Matrix c;
    c = a + b;
    REQUIRE(strcmp(c.toString(), "4 67\n9 78") == 0);
}