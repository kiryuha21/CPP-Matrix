#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      result(i, j) = 0;
      for (int k = 0; k < cols_; ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }

  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = (*this)(i, j) * num;
    }
  }

  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) {
    return *this;
  }
  free_matrix();

  init_matrix(other.rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) = other(i, j);
    }
  }

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this == &other) {
    return *this;
  }
  free_matrix();

  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  *this = *this + other;
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  *this = *this - other;
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  *this = *this * other;
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  *this = *this * num;
  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range(OUT_OF_RANGE_MSG);
  }
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range(OUT_OF_RANGE_MSG);
  }
  return matrix_[row][col];
}
