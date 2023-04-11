#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(S21Matrix, 1_init) {
  S21Matrix a;
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getCols(), 0);
}

TEST(S21Matrix, 1_init_with_wrong_size) {
  try {
    S21Matrix a(-1, -1);
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 2_equal) {
  S21Matrix a(2, 2);
  a(1, 1) = 5;
  ASSERT_EQ(a(1, 1), 5);
  S21Matrix b(a);
  ASSERT_EQ(a(1, 1), b(1, 1));
}

TEST(S21Matrix, 3_plus) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  S21Matrix b(a);
  S21Matrix c;
  c = a + b;
  ASSERT_EQ(c(0, 0), 10);
}

TEST(S21Matrix, 3_plus_wrong_size) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  S21Matrix b(5, 5);
  S21Matrix c;
  try {
    c = a + b;
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 4_minus) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  S21Matrix b(a);
  S21Matrix c(4, 4);
  c = a - b;
  ASSERT_EQ(c(0, 0), 0);
}

TEST(S21Matrix, 4_minus_wrong_size) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  S21Matrix b(5, 5);
  S21Matrix c;
  try {
    c = a - b;
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 5_equal) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);

  a(0, 0) = 5;
  bool first = (a == b);
  ASSERT_EQ(first, false);
  b(0, 0) = 5;
  bool second = (a == b);
  ASSERT_EQ(second, true);
}

TEST(S21Matrix, 5_equal_with_wrong_size) {
  S21Matrix a(4, 4);
  S21Matrix b(5, 5);

  bool result = (a == b);
  ASSERT_EQ(result, false);
}

TEST(S21Matrix, 5_not_equal) {
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);

  a(0, 0) = 5;
  bool first = (a != b);
  ASSERT_EQ(first, true);
  b(0, 0) = 5;
  bool second = (a != b);
  ASSERT_EQ(second, false);
}

TEST(S21Matrix, 6_mul_num) {
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 5;
  S21Matrix b = a * 2;

  S21Matrix test(2, 2);
  test(0, 0) = 4;
  test(0, 1) = 0;
  test(1, 0) = 0;
  test(1, 1) = 10;

  bool res = b == test;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 7_mul_matrix) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 4;
  b(0, 1) = 3;
  b(1, 0) = 2;
  b(1, 1) = 1;

  c(0, 0) = 8.0;
  c(0, 1) = 5.0;
  c(1, 0) = 20.0;
  c(1, 1) = 13.0;

  S21Matrix d = a * b;

  bool res = d == c;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 7_mul_matrix_wrong_size) {
  S21Matrix a(2, 2);
  S21Matrix b(10, 10);
  S21Matrix c(10, 10);
  try {
    c = a * b;
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 8_mul_matrix) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 4;
  b(0, 1) = 3;
  b(1, 0) = 2;
  b(1, 1) = 1;

  c(0, 0) = 8.0;
  c(0, 1) = 5.0;
  c(1, 0) = 20.0;
  c(1, 1) = 13.0;

  a *= b;

  bool res = a == c;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 9_mul_num) {
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 5;
  a *= 2;

  S21Matrix test(2, 2);
  test(0, 0) = 4;
  test(0, 1) = 0;
  test(1, 0) = 0;
  test(1, 1) = 10;

  bool res = a == test;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 10_transpose) {
  S21Matrix test_matrix_1(3, 2);
  S21Matrix test_matrix_2(2, 3);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = 4.0;
  test_matrix_1(1, 0) = 2.0;
  test_matrix_1(1, 1) = 5.0;
  test_matrix_1(2, 0) = 3.0;
  test_matrix_1(2, 1) = 6.0;

  test_matrix_2(0, 0) = 1.0;
  test_matrix_2(0, 1) = 2.0;
  test_matrix_2(0, 2) = 3.0;
  test_matrix_2(1, 0) = 4.0;
  test_matrix_2(1, 1) = 5.0;
  test_matrix_2(1, 2) = 6.0;

  S21Matrix test_matrix_3 = test_matrix_1.Transpose();
  bool res = test_matrix_3 == test_matrix_2;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 11_calc_complements) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = 2.0;
  test_matrix_1(0, 2) = 3.0;
  test_matrix_1(1, 0) = 0.0;
  test_matrix_1(1, 1) = 4.0;
  test_matrix_1(1, 2) = 2.0;
  test_matrix_1(2, 0) = 5.0;
  test_matrix_1(2, 1) = 2.0;
  test_matrix_1(2, 2) = 1.0;

  test_matrix_2(0, 0) = 0.0;
  test_matrix_2(0, 1) = 10.0;
  test_matrix_2(0, 2) = -20.0;
  test_matrix_2(1, 0) = 4.0;
  test_matrix_2(1, 1) = -14.0;
  test_matrix_2(1, 2) = 8.0;
  test_matrix_2(2, 0) = -8.0;
  test_matrix_2(2, 1) = -2.0;
  test_matrix_2(2, 2) = 4.0;

  S21Matrix test_matrix_3 = test_matrix_1.CalcComplements();
  bool res = test_matrix_3 == test_matrix_2;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 11_calc_complements_wrong_size) {
  S21Matrix a(3, 5);
  try {
    a.CalcComplements();
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 12_determ) {
  S21Matrix test_matrix_1(3, 3);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = 2.0;
  test_matrix_1(0, 2) = 3.0;
  test_matrix_1(1, 0) = 4.0;
  test_matrix_1(1, 1) = 5.0;
  test_matrix_1(1, 2) = 6.0;
  test_matrix_1(2, 0) = 7.0;
  test_matrix_1(2, 1) = 8.0;
  test_matrix_1(2, 2) = 9.0;

  double res = test_matrix_1.Determinant();
  ASSERT_LE(abs(res - (0)), DELTA);
}

TEST(S21Matrix, 12_determ_wrong_size) {
  S21Matrix a(3, 5);
  try {
    a.Determinant();
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 13_output) { S21Matrix test_matrix_1(3, 3); }

TEST(S21Matrix, 14_determ) {
  S21Matrix test_matrix_1(2, 2);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = -4.0;
  test_matrix_1(1, 0) = 21.0;
  test_matrix_1(1, 1) = 5.0;
  double res = test_matrix_1.Determinant();
  ASSERT_LE(abs(res - (89)), DELTA);
}

TEST(S21Matrix, 15_determ) {
  S21Matrix test_matrix_1(4, 4);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = 4.0;
  test_matrix_1(0, 2) = 5.0;
  test_matrix_1(0, 3) = 6.0;
  test_matrix_1(1, 0) = 4.0;
  test_matrix_1(1, 1) = 1.0;
  test_matrix_1(1, 2) = 5.0;
  test_matrix_1(1, 3) = 2.0;
  test_matrix_1(2, 0) = 1.0;
  test_matrix_1(2, 1) = 2.0;
  test_matrix_1(2, 2) = 4.0;
  test_matrix_1(2, 3) = 5.0;
  test_matrix_1(3, 0) = 3.0;
  test_matrix_1(3, 1) = 7.0;
  test_matrix_1(3, 2) = 1.0;
  test_matrix_1(3, 3) = 6.0;

  double res = test_matrix_1.Determinant();
  ASSERT_LE(abs(res - (-191)), DELTA);
}

TEST(S21Matrix, 16_inverse) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  test_matrix_1(0, 0) = 2.0;
  test_matrix_1(0, 1) = 5.0;
  test_matrix_1(0, 2) = 7.0;
  test_matrix_1(1, 0) = 6.0;
  test_matrix_1(1, 1) = 3.0;
  test_matrix_1(1, 2) = 4.0;
  test_matrix_1(2, 0) = 5.0;
  test_matrix_1(2, 1) = -2.0;
  test_matrix_1(2, 2) = -3.0;

  test_matrix_2(0, 0) = 1.0;
  test_matrix_2(0, 1) = -1.0;
  test_matrix_2(0, 2) = 1.0;
  test_matrix_2(1, 0) = -38.0;
  test_matrix_2(1, 1) = 41.0;
  test_matrix_2(1, 2) = -34.0;
  test_matrix_2(2, 0) = 27.0;
  test_matrix_2(2, 1) = -29.0;
  test_matrix_2(2, 2) = 24.0;

  S21Matrix test_matrix_3 = test_matrix_1.InverseMatrix();
  bool res = test_matrix_3 == test_matrix_2;
  ASSERT_EQ(res, true);
}

TEST(S21Matrix, 17_move) {
  S21Matrix a(4, 4);
  S21Matrix b(std::move(a));

  ASSERT_EQ(a.getCols(), 0);
  ASSERT_EQ(b.getRows(), 4);
}

TEST(S21Matrix, 18_plus) {
  S21Matrix a(4, 4);
  a(0, 0) = 5;
  S21Matrix b(a);
  a += b;
  ASSERT_EQ(a(0, 0), 10);
}

TEST(S21Matrix, 19_sets_big) {
  S21Matrix a(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  a.setCols(3);
  a.setRows(4);

  ASSERT_EQ(a.getCols(), 3);
  ASSERT_EQ(a.getRows(), 4);
}

TEST(S21Matrix, 19_sets_small) {
  S21Matrix a(3, 3);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 8;
  a(1, 0) = 3;
  a(1, 1) = 4;
  a(1, 2) = 10.5;
  a(2, 0) = 0.5;
  a(2, 1) = 5.75;
  a(2, 2) = 0.1;

  a.setCols(2);
  a.setRows(2);

  ASSERT_EQ(a.getCols(), 2);
  ASSERT_EQ(a.getRows(), 2);
}

TEST(S21Matrix, 20_equal) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 5.0;
  b = a;
  ASSERT_EQ(a(0, 0), 5);
  ASSERT_EQ(b(0, 0), 5);
}

TEST(S21Matrix, 21_mult) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  a * 2;
  ASSERT_EQ(a(0, 0), 4);
}

TEST(S21Matrix, 22_minus) {
  S21Matrix a(2, 2);
  a(0, 0) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 1;
  a -= b;
  ASSERT_EQ(a(0, 0), 3);
}

TEST(S21Matrix, 23_det) {
  S21Matrix a(1, 1);
  a(0, 0) = 5;
  double det = a.Determinant();
  ASSERT_EQ(det, 5.0);
}

TEST(S21Matrix, 24_const) {
  const S21Matrix a(2, 2);
  double b = a(0, 0);
  ASSERT_EQ(b, 0.0);
}

TEST(S21Matrix, 24_const_wrong_index) {
  const S21Matrix a(2, 2);
  try {
    a(10, 0);
  } catch (const std::out_of_range &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(S21Matrix, 25_inverse) {
  S21Matrix test_matrix_1(4, 4);
  S21Matrix test_matrix_2(4, 4);
  test_matrix_1(0, 0) = -1.0;
  test_matrix_1(0, 1) = 2.0;
  test_matrix_1(0, 2) = 7.0;
  test_matrix_1(0, 3) = 9.0;
  test_matrix_1(1, 0) = 1.0;
  test_matrix_1(1, 1) = 0.0;
  test_matrix_1(1, 2) = 0.0;
  test_matrix_1(1, 3) = 0.0;
  test_matrix_1(2, 0) = 47.0;
  test_matrix_1(2, 1) = 13.0;
  test_matrix_1(2, 2) = 17.0;
  test_matrix_1(2, 3) = 21.0;
  test_matrix_1(3, 0) = 22.0;
  test_matrix_1(3, 1) = 7.0;
  test_matrix_1(3, 2) = 1.0;
  test_matrix_1(3, 3) = 3.0;

  test_matrix_2(0, 0) = 0.0;
  test_matrix_2(0, 1) = 1.0;
  test_matrix_2(0, 2) = 0.0;
  test_matrix_2(0, 3) = 0.0;
  test_matrix_2(1, 0) = -5.0 / 23.0;
  test_matrix_2(1, 1) = -121.0 / 23.0;
  test_matrix_2(1, 2) = 2.0 / 23.0;
  test_matrix_2(1, 3) = 1.0 / 23.0;
  test_matrix_2(2, 0) = -18.0 / 23.0;
  test_matrix_2(2, 1) = -379.0 / 46.0;
  test_matrix_2(2, 2) = 19.0 / 46.0;
  test_matrix_2(2, 3) = -25.0 / 46.0;
  test_matrix_2(3, 0) = 53.0 / 69.0;
  test_matrix_2(3, 1) = 1061.0 / 138.0;
  test_matrix_2(3, 2) = -47.0 / 138.0;
  test_matrix_2(3, 3) = 19.0 / 46.0;

  S21Matrix test_matrix_3 = test_matrix_1.InverseMatrix();
  bool res = test_matrix_3 == test_matrix_2;
  ASSERT_EQ(res, true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
