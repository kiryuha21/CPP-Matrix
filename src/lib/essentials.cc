#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() = default;

S21Matrix::S21Matrix(int rows, int cols) { init_matrix(rows, cols); }

S21Matrix::S21Matrix(const S21Matrix& other) { *this = other; }

S21Matrix::S21Matrix(S21Matrix&& other) noexcept { *this = std::move(other); }

S21Matrix::~S21Matrix() { free_matrix(); }

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

void S21Matrix::setRows(int rows) {
  S21Matrix res(rows, cols_);
  for (int i = 0; i < std::min(rows, rows_); ++i) {
    for (int j = 0; j < cols_; ++j) {
      res(i, j) = (*this)(i, j);
    }
  }
  (*this) = std::move(res);
}

void S21Matrix::setCols(int cols) {
  S21Matrix res(rows_, cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < std::min(cols, cols_); ++j) {
      res(i, j) = (*this)(i, j);
    }
  }
  (*this) = std::move(res);
}

void S21Matrix::free_matrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void S21Matrix::init_matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::length_error(INVALID_MATRIX_MSG);
  }

  rows_ = rows;
  cols_ = cols;

  try {
    matrix_ = new double*[rows];
    for (int i = 0; i < rows; ++i) {
      matrix_[i] = new double[cols];
    }
  } catch (std::bad_alloc& e) {
    std::throw_with_nested(e);
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix_[i][j] = 0;
    }
  }
}
