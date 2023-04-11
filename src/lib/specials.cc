#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

void S21Matrix::minus_row_col(const S21Matrix& origin_matrix,
                              S21Matrix& temp_matrix, int row, int col) {
  int miss_row = 0;

  for (int i = 0; i < origin_matrix.rows_ - 1; ++i) {
    if (i == row) {
      miss_row = 1;
    }
    int miss_col = 0;
    for (int j = 0; j < origin_matrix.rows_ - 1; ++j) {
      if (j == col) {
        miss_col = 1;
      }
      temp_matrix(i, j) = origin_matrix(i + miss_row, j + miss_col);
    }
  }
}

double S21Matrix::recursive_det(const S21Matrix& origin_matrix) {
  double temp_det = 0;
  if (origin_matrix.rows_ == 1) {
    temp_det = origin_matrix(0, 0);
    return temp_det;
  }

  if (origin_matrix.rows_ == 2) {
    temp_det = origin_matrix(0, 0) * origin_matrix(1, 1) -
               (origin_matrix(1, 0) * origin_matrix(0, 1));
    return temp_det;
  }

  int sign = 1;
  S21Matrix temp_matrix(origin_matrix.rows_ - 1, origin_matrix.cols_ - 1);
  for (int i = 0; i < origin_matrix.rows_; ++i) {
    minus_row_col(origin_matrix, temp_matrix, i, 0);
    temp_det =
        temp_det + sign * origin_matrix(i, 0) * recursive_det(temp_matrix);
    sign = -sign;
  }

  return temp_det;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  return recursive_det(*this);
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  if (rows_ == 1) {
    S21Matrix res(*this);
    res(0, 0) = 1;
    return res;
  }

  int sign;
  S21Matrix temp_matrix(rows_, cols_);
  for (int i = 0; i < temp_matrix.rows_; ++i) {
    for (int j = 0; j < temp_matrix.cols_; ++j) {
      S21Matrix additions_matrix(temp_matrix.rows_ - 1, temp_matrix.cols_ - 1);
      minus_row_col(*this, additions_matrix, i, j);
      if ((i + j) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      temp_matrix(i, j) = sign * recursive_det(additions_matrix);
    }
  }
  return temp_matrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  double temp_det = Determinant();
  if (std::abs(temp_det) < DELTA) {
    throw std::invalid_argument(INVALID_MATRIX_MSG);
  }

  S21Matrix result = CalcComplements().Transpose() * (1 / temp_det);
  return result;
}
