#ifndef MATRIXWITHLABEL_H
#define MATRIXWITHLABEL_H
#include "Matrix.h"



class MatrixWithLabel : public Matrix {
private:
    std::string label = "A";
public:
    using Matrix::Matrix;
    MatrixWithLabel(std::string label, int n, int m);
    MatrixWithLabel(std::string label, std::initializer_list<std::initializer_list<double>> lst);
    MatrixWithLabel(const MatrixWithLabel& other);
    MatrixWithLabel(MatrixWithLabel&& other) noexcept = default;

    MatrixWithLabel& operator=(const MatrixWithLabel& other);
    MatrixWithLabel& operator=(MatrixWithLabel&& other) noexcept = default;

    void setLabel(const std::string& new_label);
    std::string getLabel();
};



#endif //MATRIXWITHLABEL_H
