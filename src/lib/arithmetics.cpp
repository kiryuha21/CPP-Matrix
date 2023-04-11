#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
  (*this) += other;
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  (*this) -= other;
}

void S21Matrix::MulNumber(const double num) {
  (*this) *= num;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  (*this) *= other;
}
