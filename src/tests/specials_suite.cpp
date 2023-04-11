#include "unit_tests.h"

TEST(SpecialsSuite, correct_transpose) {
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
  ASSERT_TRUE(test_matrix_3 == test_matrix_2);
}

TEST(SpecialsSuite, invalid_transpose) {
  S21Matrix a;
  ASSERT_THROW(a.Transpose(), std::length_error);
}

TEST(SpecialsSuite, correct_complements) {
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
  ASSERT_TRUE(test_matrix_3 == test_matrix_2);
}

TEST(SpecialsSuite, wrong_size_calc_complements) {
  S21Matrix a(3, 5);
  ASSERT_THROW(a.CalcComplements(), std::length_error);
}

TEST(SpecialsSuite, signular_size_complements) {
  S21Matrix a(1, 1);
  a(0, 0) = 5;
  S21Matrix b = a.CalcComplements();
  ASSERT_EQ(b(0, 0), 1);
}

TEST(SpecialsSuite, correct_zero_det) {
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
  ASSERT_NEAR(res, 0, DELTA);
}

TEST(SpecialsSuite, det_wrong_size) {
  S21Matrix a(3, 5);
  ASSERT_THROW(a.Determinant(), std::length_error);
}

TEST(SpecialsSuite, correct_nonzero_det_1) {
  S21Matrix test_matrix_1(2, 2);

  test_matrix_1(0, 0) = 1.0;
  test_matrix_1(0, 1) = -4.0;
  test_matrix_1(1, 0) = 21.0;
  test_matrix_1(1, 1) = 5.0;

  double res = test_matrix_1.Determinant();
  ASSERT_NEAR(res, 89, DELTA);
}

TEST(SpecialsSuite, correct_nonzero_det_2) {
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
  ASSERT_NEAR(res, -191, DELTA);
}

TEST(SpecialsSuite, signular_det) {
  S21Matrix a(1, 1);
  a(0, 0) = 5;
  double det = a.Determinant();
  ASSERT_EQ(det, 5.0);
}

TEST(SpecialsSuite, correct_inverse_1) {
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
  ASSERT_TRUE(test_matrix_2 == test_matrix_3);
}

TEST(SpecialsSuite, correct_inverse_2) {
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
  ASSERT_TRUE(test_matrix_3 == test_matrix_2);
}

TEST(SpecialsSuite, singular_inverse) {
  S21Matrix a = random_matrix(1, 1);
  S21Matrix b = a.InverseMatrix();
  ASSERT_EQ(b(0, 0), 1 / a(0, 0));
}

TEST(SpecialsSuite, invalid_inserse) {
  S21Matrix a(3, 3);

  a(0, 0) = 1.0;
  a(0, 1) = 2.0;
  a(0, 2) = 3.0;
  a(1, 0) = 4.0;
  a(1, 1) = 5.0;
  a(1, 2) = 6.0;
  a(2, 0) = 7.0;
  a(2, 1) = 8.0;
  a(2, 2) = 9.0;

  ASSERT_THROW(a.InverseMatrix(), std::invalid_argument);
}
