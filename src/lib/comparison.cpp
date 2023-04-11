#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (_cols != other._cols || _rows != other._rows) {
    return false;
  }

  for (int i = 0; i < this->_rows; ++i) {
    for (int j = 0; j < this->_cols; ++j) {
      if (std::abs((*this)(i, j) - other(i, j)) >= DELTA) {
        return false;
      }
    }
  }

  return true;
}
