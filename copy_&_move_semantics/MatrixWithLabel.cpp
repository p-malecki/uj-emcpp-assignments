#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include "MatrixWithLabel.h"


MatrixWithLabel::MatrixWithLabel(std::string label, const int n, const int m) : Matrix(n, m), label(std::move(label)) { }

MatrixWithLabel::MatrixWithLabel(std::string label, std::initializer_list<std::initializer_list<double>> lst) :  Matrix(lst), label(std::move(label)) { }

MatrixWithLabel::MatrixWithLabel(const MatrixWithLabel& other) : Matrix(other)
{
    label = other.label;
    std::cout << "copy constructor (MatrixWithLabel)" << std::endl;
}

MatrixWithLabel& MatrixWithLabel::operator=(const MatrixWithLabel& other)
{
    n_size = other.n_size;
    m_size = other.m_size;
    std::copy_n(other.data, n_size * m_size, data);
    label = other.label;
    std::cout << "copy assignment operator (MatrixWithLabel)" << std::endl;
    return *this;
}

std::string MatrixWithLabel::getLabel()
{
    return label;
}

void MatrixWithLabel::setLabel(const std::string& new_label)
{
    label = new_label;
}

