#include <algorithm>
#include <iostream>
#include "Matrix.h"


Matrix::Matrix()
{
    n_size = 0;
    m_size = 0;
    data = nullptr;
}

Matrix::Matrix(const int n, const int m) : n_size(n), m_size(m)
{
    data = new double[m_size * n_size];
    std::fill_n(data, m_size * n_size, 0);
    std::cout << "constructor of " << n_size << "x" << m_size <<" matrix" << std::endl;
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<double>> lst) : n_size{lst.size()}, m_size{0}
{
    size_t max_m = 0;
    for (decltype(auto) row : lst)
        max_m = std::max(max_m, row.size());

    m_size = max_m;
    data = new double[n_size * m_size];
    std::fill_n(data, m_size * n_size, 0);

    auto it = lst.begin();
    for (size_t i=0; i < n_size; i++, it++)
        std::copy(it->begin(),it->end(), data+(i * n_size));
    std::cout << "constructor of " << n_size << "x" << m_size <<" matrix from initializer_list" << std::endl;
}

Matrix::Matrix(const Matrix& other) : n_size(other.n_size), m_size(other.m_size)
{
    data = new double[m_size * n_size];
    std::copy_n(other.data, n_size * m_size, data);
    std::cout << "copy constructor" << std::endl;
}

Matrix::Matrix(Matrix&& other) noexcept : Matrix()
{
    //swap(*this, other);
    n_size = std::move(other.n_size);
    m_size = std::move(other.m_size);
    data = std::move(other.data);
    std::cout << "move constructor" << std::endl;
}

Matrix::~Matrix()
{
    delete data;
    std::cout << "memory delocated" << std::endl;
}

Matrix& Matrix::operator=(const Matrix& other)
{
    n_size = other.n_size;
    m_size = other.m_size;
    std::copy_n(other.data, n_size * m_size, data);
    std::cout << "copy assignment operator" << std::endl;
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    n_size = std::move(other.n_size);
    m_size = std::move(other.m_size);
    data = std::move(other.data);
    std::cout << " move assignment operator" << std::endl;
    return *this;
}

double Matrix::operator()(const int a, const int b)
{
    if (a > n_size || b > m_size)
        throw std::out_of_range("index out of range");
    return data[(a-1) * n_size + b - 1];
}

Matrix Matrix::operator-() const
{
    Matrix tmp(*this);
    for (size_t i=0; i < n_size; i++)
        for (size_t j=0; j < m_size; j++)
            tmp.data[i * n_size + j] *= -1;
    return tmp;
}

void swap(Matrix& lhs, Matrix& rhs) noexcept
{
    using std::swap;
    swap(lhs.n_size, rhs.n_size);
    swap(lhs.m_size, rhs.m_size);
    swap(lhs.data, rhs.data);
}


std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
    for (size_t i=0; i < obj.n_size; i++)
    {
        os << "{";
        for (size_t j=0; j < obj.m_size - 1; j++)
            os << obj.data[i * obj.n_size + j] << ", ";
        os << obj.data[i * obj.n_size + obj.m_size - 1] << "}" << std::endl;
    }
    return os;
}
