#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>


class Matrix
{
private:
    size_t n_size;
    size_t m_size;
    double* data;
public:
    Matrix();
    Matrix(int n, int m);
    Matrix(std::initializer_list<std::initializer_list<double>> lst);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix();

    double operator()(int a, int b);
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix operator-() const;

    friend void swap(Matrix& lhs, Matrix& rhs) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
};

#endif