#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other){
  if (_matrix == nullptr || other._matrix == nullptr) {
    throw std::invalid_argument(EMPTY_MATRIX_MSG);
  }

  if (_rows != other._rows || _cols != other._cols) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(_rows, _cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other){
  if (_matrix == nullptr || other._matrix == nullptr) {
    throw std::invalid_argument(EMPTY_MATRIX_MSG);
  }

  if (_rows != other._rows || _cols != other._cols) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(_rows, _cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other){
  if (_matrix == nullptr || other._matrix == nullptr) {
    throw std::invalid_argument(EMPTY_MATRIX_MSG);
  }

  if (_cols != other._rows) {
    throw std::length_error(DIFFERENT_SIZES_MSG);
  }

  S21Matrix result(_rows, other._cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < other._cols; ++j) {
      result(i, j) = 0;
      for (int k = 0; k < _cols; ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }

  return result;
}

S21Matrix S21Matrix::operator*(const double num){
  if (_matrix == nullptr) {
    throw std::invalid_argument(EMPTY_MATRIX_MSG);
  }

  S21Matrix result(_rows, _cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      result(i, j) = (*this)(i, j) * num;
    }
  }

  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

bool S21Matrix::operator!=(const S21Matrix &other) {
  return !this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other){
  if (this == &other) {
    return *this;
  }
  free_matrix();

  init_matrix(other._rows, other._cols);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
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

  _rows = other._rows;
  _cols = other._cols;

  _matrix = other._matrix;
  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = other._matrix[i];
    other._matrix[i] = nullptr;
  }
  other._matrix = nullptr;
  other._rows = 0;
  other._cols = 0;

  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other){
    *this = *this + other;
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other){
    *this = *this - other;
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other){
    *this = *this * other;
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double num){
    *this = *this * num;
    return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row >= _rows || col >= _cols) {
    throw std::out_of_range(OUT_OF_RANGE_MSG);
  }
  return _matrix[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row >= _rows || col >= _cols) {
    throw std::out_of_range(OUT_OF_RANGE_MSG);
  }
  return _matrix[row][col];
}
