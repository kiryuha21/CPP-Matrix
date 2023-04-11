#include "unit_tests.h"

TEST(S21Matrix, empty_arithmetics) {
  S21Matrix a;
  S21Matrix b;
  ASSERT_THROW(a += b, std::length_error);
  ASSERT_THROW(a -= b, std::length_error);
  ASSERT_THROW(a *= b, std::length_error);
  ASSERT_THROW(a *= 5, std::length_error);
}

TEST(S21Matrix, correct_plus) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b = random_matrix(4, 5);
  S21Matrix c;
  c = a + b;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(c(i, j), a(i, j) + b(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, correct_func_plus) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b = random_matrix(4, 5);
  S21Matrix c(b);
  c.SumMatrix(a);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(c(i, j), a(i, j) + b(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, plus_with_wrong_size) {
  S21Matrix a(4, 4);
  S21Matrix b(5, 5);
  ASSERT_THROW(S21Matrix c = a + b, std::length_error);
}

TEST(S21Matrix, correct_minus) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b = random_matrix(4, 5);
  S21Matrix c;
  c = a - b;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(c(i, j), a(i, j) - b(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, correct_func_minus) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b = random_matrix(4, 5);
  S21Matrix c(b);
  c.SubMatrix(a);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(c(i, j), b(i, j) - a(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, minus_with_wrong_size) {
  S21Matrix a(4, 4);
  S21Matrix b(5, 5);
  ASSERT_THROW(S21Matrix c = a - b, std::length_error);
}

TEST(S21Matrix, correct_mul_num) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b = a * 5;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(b(i, j), a(i, j) * 5, DELTA);
    }
  }
}

TEST(S21Matrix, correct_mul_num_func) {
  S21Matrix a = random_matrix(4, 5);
  S21Matrix b(a);
  b.MulNumber(5);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 5; ++j) {
      ASSERT_NEAR(b(i, j), a(i, j) * 5, DELTA);
    }
  }
}

TEST(S21Matrix, correct_mul_matrix) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b = random_matrix(6, 5);
  S21Matrix c = a * b;

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      double res = 0;
      for (int k = 0; k < 6; ++k) {
        res += a(i, k) * b(k, j);
      }
      ASSERT_NEAR(res, c(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, correct_mul_matrix_func) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b = random_matrix(6, 5);
  S21Matrix c(a);
  c.MulMatrix(b);

  ASSERT_EQ(a.getRows(), c.getRows());
  ASSERT_EQ(b.getCols(), c.getCols());

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      double res = 0;
      for (int k = 0; k < 6; ++k) {
        res += a(i, k) * b(k, j);
      }
      ASSERT_NEAR(res, c(i, j), DELTA);
    }
  }
}

TEST(S21Matrix, mul_matrix_with_wrong_size) {
  S21Matrix a = random_matrix(7, 8);
  S21Matrix b = random_matrix(7, 8);
  ASSERT_THROW(S21Matrix c = a * b, std::length_error);
}
