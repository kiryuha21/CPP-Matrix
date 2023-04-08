#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows),  _cols(cols) {
    _matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        _matrix[i] = new double[cols];
    }
}

S21Matrix::S21Matrix(const S21Matrix &other) {

}

S21Matrix::S21Matrix(S21Matrix &&other) {

}

S21Matrix::~S21Matrix() {

}

int S21Matrix::getRows() const {
    return _rows;
}

int S21Matrix::getCols() const {
    return _cols;
}

double **S21Matrix::getMatrix() const {
    return _matrix;
}

void S21Matrix::setRows(int rows) {
    _rows = rows;
}

void S21Matrix::setCols(int cols) {
    _cols = cols;
}

void S21Matrix::setMatrix(double **matrix) {
    _matrix = matrix;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
    bool return_code = true;
    if (this->_cols != other._cols || this->_rows != other._rows || this->_matrix == nullptr ||
        other._matrix == nullptr) {
        return_code = false;
    } else {
        int stop = 0;
        for (int i = 0; i < this->_rows && !stop; ++i) {
            for (int j = 0; j < this->_cols && !stop; ++j) {
                if (fabs(this->_matrix[i][j] - other._matrix[i][j]) >= DELTA) {
                    stop = 1;
                    return_code = false;
                }
            }
        }
    }
    return return_code;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {

}

void S21Matrix::SubMatrix(const S21Matrix &other) {

}

void S21Matrix::MulNumber(const double num) {

}

void S21Matrix::MulMatrix(const S21Matrix &other) {

}

S21Matrix S21Matrix::Transpose() {
    return S21Matrix();
}

S21Matrix S21Matrix::CalcComplements() {
    return S21Matrix();
}

double S21Matrix::Determinant() {
    return 0;
}

S21Matrix S21Matrix::InverseMatrix() {
    return S21Matrix();
}

double& S21Matrix::operator()(int row, int col) {
    if (row >= _rows || col >= _cols) {
        throw std::out_of_range(OUT_OF_RANGE_MSG);
    }
    return _matrix[row][col];
}

bool S21Matrix::operator==(const S21Matrix &other) {
    return this->EqMatrix(other);
}
