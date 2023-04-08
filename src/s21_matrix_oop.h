#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H

#include <cmath>
#include <stdexcept>

#define DELTA 1e-7

#define OUT_OF_RANGE_MSG "Incorrect input, index is out of range"

class S21Matrix {
private:
    int _rows = 0;
    int _cols = 0;
    double** _matrix = nullptr;

public:
    void setRows(int rows);
    void setCols(int cols);
    void setMatrix(double **matrix);

    int getRows() const;
    int getCols() const;
    double **getMatrix() const;

    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    bool EqMatrix(const S21Matrix& other);
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();

    // TODO: overload operators
    double& operator()(int row, int col);
    bool operator==(const S21Matrix &other);
};


#endif //CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
