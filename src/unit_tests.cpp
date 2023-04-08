#include <gtest/gtest.h>
#include "s21_matrix_oop.h"

TEST(EqMatrixTest, default_test) {
    S21Matrix a(5, 6);
    S21Matrix b(5, 6);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            double num = rand() % 100;
            a(i, j) = num;
            b(i, j) = num;
        }
    }

    ASSERT_TRUE(a == b);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
