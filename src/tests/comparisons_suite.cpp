#include "unit_tests.h"

TEST(S21Matrix, equal) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b(a);

  bool res = true;
  res &= a.getRows() == b.getRows() && a.getCols() == b.getCols();
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      res &= std::abs(a(i, j) - b(i, j)) < DELTA;
    }
  }

  ASSERT_EQ(res, a == b);
}

TEST(S21Matrix, equal_empty) {
  S21Matrix a;
  S21Matrix b;

  bool res = true;
  res &= a.getRows() == b.getRows() && a.getCols() == b.getCols();

  ASSERT_EQ(res, a == b);
}

TEST(S21Matrix, unequal_size) {
  S21Matrix a = random_matrix(4, 4);
  S21Matrix b = random_matrix(5, 5);

  bool res = true;
  res &= a.getRows() == b.getRows() && a.getCols() == b.getCols();

  ASSERT_EQ(res, a == b);
}

TEST(S21Matrix, unequal_element) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b(a);
  b(4, 4) += 1;

  bool res = true;
  res &= a.getRows() == b.getRows() && a.getCols() == b.getCols();
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      res &= std::abs(a(i, j) - b(i, j)) < DELTA;
    }
  }

  ASSERT_EQ(res, a == b);
}
