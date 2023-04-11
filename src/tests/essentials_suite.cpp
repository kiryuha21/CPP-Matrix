#include "unit_tests.h"

TEST(S21Matrix, default_init) {
  S21Matrix a;
  ASSERT_EQ(a.getRows(), 0);
  ASSERT_EQ(a.getCols(), 0);
}

TEST(S21Matrix, normal_init) {
  S21Matrix a(5, 6);
  ASSERT_EQ(a.getRows(), 5);
  ASSERT_EQ(a.getCols(), 6);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      ASSERT_NEAR(a(i, j), 0, DELTA);
    }
  }
}

TEST(S21Matrix, init_with_copy) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b(a);

  ASSERT_EQ(a.getRows(), 5);
  ASSERT_EQ(a.getCols(), 6);
  ASSERT_TRUE(a == b);
}

TEST(S21Matrix, init_with_move) {
  S21Matrix a = random_matrix(5, 6);
  S21Matrix b(a);
  S21Matrix c(std::move(a));

  ASSERT_EQ(c.getRows(), 5);
  ASSERT_EQ(c.getCols(), 6);
  ASSERT_TRUE(b == c);
  ASSERT_TRUE(a.getCols() == 0);
  ASSERT_TRUE(a.getRows() == 0);
}

TEST(S21Matrix, init_with_negative_size) {
  ASSERT_THROW(S21Matrix a(-1, -1), std::length_error);
}

TEST(S21Matrix, init_with_overflow) {
  ASSERT_THROW(S21Matrix a(2000000000, 2000000000), std::bad_alloc);
}

TEST(S21Matrix, correct_element) {
  S21Matrix a(1, 1);
  ASSERT_EQ(a.getCols(), 1);
  ASSERT_EQ(a.getRows(), 1);

  a(0, 0) = 5;
  ASSERT_EQ(a(0, 0), 5);
}

TEST(S21Matrix, incorrect_element) {
  S21Matrix a(1, 1);
  ASSERT_EQ(a.getCols(), 1);
  ASSERT_EQ(a.getRows(), 1);

  ASSERT_THROW(a(2, 2) = 5, std::out_of_range);
}

TEST(S21Matrix, set_rows_increasing) {
  S21Matrix a = random_matrix(3, 3);
  a.setRows(10);

  ASSERT_EQ(a.getRows(), 10);
  for (int i = 3; i < 10; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_NEAR(a(i, j), 0, DELTA);
    }
  }
}

TEST(S21Matrix, set_rows_decreasing) {
  S21Matrix a = random_matrix(3, 3);
  a.setRows(2);

  ASSERT_EQ(a.getRows(), 2);
  ASSERT_THROW(a(2, 2), std::out_of_range);
}

TEST(S21Matrix, set_cols_increasing) {
  S21Matrix a = random_matrix(3, 3);
  a.setCols(10);

  ASSERT_EQ(a.getCols(), 10);
  for (int i = 0; i < 3; ++i) {
    for (int j = 3; j < 10; ++j) {
      ASSERT_NEAR(a(i, j), 0, DELTA);
    }
  }
}

TEST(S21Matrix, set_cols_decreasing) {
  S21Matrix a = random_matrix(3, 3);
  a.setCols(2);

  ASSERT_EQ(a.getCols(), 2);
  ASSERT_THROW(a(2, 2), std::out_of_range);
}
