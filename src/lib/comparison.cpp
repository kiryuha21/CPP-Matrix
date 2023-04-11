#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    return false;
  }

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      if (std::abs((*this)(i, j) - other(i, j)) >= DELTA) {
        return false;
      }
    }
  }

  return true;
}
