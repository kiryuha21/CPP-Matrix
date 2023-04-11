#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>
#include <stdexcept>

#define DELTA 1e-7

#define OUT_OF_RANGE_MSG "Incorrect input, index is out of range"
#define EMPTY_MATRIX_MSG "Empty matrix!"
#define INVALID_MATRIX_MSG "Invalid matrix"
#define DIFFERENT_SIZES_MSG "Different matrix sizes!"

class S21Matrix {
 private:
  int _rows = 0;
  int _cols = 0;
  double** _matrix = nullptr;

  void free_matrix();
  void init_matrix(int rows, int cols);
  double recursive_det(const S21Matrix& origin_matrix);
  void minus_row_col(const S21Matrix& origin_matrix, S21Matrix& temp_matrix,
                     int row, int col);
 public:
  void setRows(int rows);
  void setCols(int cols);

  [[nodiscard]] int getRows() const;
  [[nodiscard]] int getCols() const;

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double num);
  bool operator==(const S21Matrix& other);
  bool operator!=(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  double& operator()(int row, int col);
  double operator()(int row, int col) const;
};

#endif  // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
