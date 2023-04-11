#include "unit_tests.h"

S21Matrix random_matrix(int rows, int cols) {
  S21Matrix res(rows, cols);
  for (int i = 0; i < res.getRows(); ++i) {
    for (int j = 0; j < res.getCols(); ++j) {
      res(i, j) = rand() % 100;
    }
  }
  return res;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
