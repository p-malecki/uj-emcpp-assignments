#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <typename T, size_t N, size_t M>
class Matrix{
	T data[N*M];

 public:
    constexpr size_t numberOfRows() const noexcept { return N; }
    constexpr size_t numberOfColumns() const noexcept { return M; }

    constexpr Matrix(int /*nrows*/ = N, int /*ncols*/ = M) noexcept {
	  std::fill_n(data, N*M, T{});
	}

    Matrix(const std::initializer_list<std::initializer_list<T>> & list) {
		T * p = data;
		for(const auto & row: list){
	  		T* p2 = std::copy(row.begin(), row.end(), p);
	  		std::fill(p2, p+=M, T{});
		}
    }

	Matrix(const Matrix & m) noexcept {
		std::copy_n(m.data, N*M, data);
	}

	Matrix & operator= (const Matrix & m) noexcept {
		if(&m != this){
			std::copy_n(m.data, N*M, data);
		}
		return *this;
	}

    T& operator()(int i, int j) noexcept {
        return data[(i-1)*M+j-1];
    }

	const T& operator()(int i, int j) const noexcept {
	   return data[(i-1)*M+j-1];
	}

    friend Matrix operator+(const Matrix & a, const Matrix &b) noexcept {
		Matrix r;
		for(size_t i = 1; i <= N; ++i){
			for(size_t j = 1; j <= M; ++j){
				r(i,j) = a(i,j) + b(i,j);
			}
		}
		return r;
	}


    class iterator {
    protected:
        Matrix<T, N, M>* matrix;
        size_t current_row;
        size_t current_col;
    public:
        explicit iterator(Matrix<T, N, M>* matrix, size_t row=1, size_t col=1) : matrix(matrix), current_row(row), current_col(col) {}

        virtual T& operator*() const {
            return matrix->operator()(current_row, current_col);\
        }

        virtual T* operator->() const {
            return &matrix->operator()(current_row, current_col);
        }

        iterator& operator++() {
            if (current_col < M)
                current_col++;
            else {
                current_row++;
                current_col = 1;
            }
            return *this;
        }

        iterator operator++(int) {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const iterator& left, const iterator& right) {
            return  left.matrix == right.matrix &&
                    left.current_row == right.current_row &&
                    left.current_col == right.current_col;
        }

        friend bool operator!=(const iterator& left, const iterator& right) {
            return !(left == right);
        }
    };

    class const_iterator : public iterator{
    public:
        explicit const_iterator(const Matrix<T, N, M>* matrix, size_t row=1, size_t col=1) : iterator(const_cast<Matrix<T, N, M>*>(matrix), row, col) {}

        const T& operator*() const override {
            return this->matrix->operator()(this->current_row, this->current_col);\
        }

        const T* operator->() const override {
            return &this->matrix->operator()(this->current_row, this->current_col);
        }

        const_iterator& operator++() {
            if (this->current_col < M)
                this->current_col++;
            else {
                this->current_row++;
                this->current_col = 1;
            }
            return *this;
        }

        const_iterator operator++(int) {
            auto temp = *this;
            this->operator++();
            return temp;
        }
    };

    class row_iterator : public iterator {
    public:
        explicit row_iterator(const Matrix<T, N, M>* matrix, size_t row=1, size_t col=1) : iterator(const_cast<Matrix<T, N, M>*>(matrix), row, col) {}

        row_iterator& operator++() {
            this->current_col++;
            return *this;
        }

        row_iterator operator++(int) {
            auto temp = row_iterator(this->matrix, this->current_row, this->current_col);//*this;
            this->operator++();
            return temp;
        }
    };

    class col_iterator : public iterator {
    public:
        explicit col_iterator(const Matrix<T, N, M>* matrix, size_t row=1, size_t col=1) : iterator(const_cast<Matrix<T, N, M>*>(matrix), row, col) {}

        col_iterator& operator++() {
            this->current_row++;
            return *this;
        }

        col_iterator operator++(int) {
            auto temp = *this;
            this->operator++();
            return temp;
        }
    };


    Matrix<T, N, M>::iterator begin()  {
        return iterator(this);
    }

    Matrix<T, N, M>::iterator end() {
        return iterator(this, N + 1, 1);
    }

    Matrix<T, N, M>::const_iterator begin() const {
        return const_iterator(this);
    }

    Matrix<T, N, M>::const_iterator end() const {
        return const_iterator(this, N + 1, 1);
    }

    Matrix<T, N, M>::row_iterator row_begin(int row) {
        return row_iterator(this, row, 1);
    }

    Matrix<T, N, M>::row_iterator row_end(int row) {
        return row_iterator(this, row, M + 1);
    }

    Matrix<T, N, M>::col_iterator col_begin(int col) {
        return col_iterator(this, 1, col);
    }

    Matrix<T, N, M>::col_iterator col_end(int col) {
        return col_iterator(this, N + 1, col);
    }
};


template <typename T, size_t N, size_t M>
void printMatrix(const Matrix<T,N,M> & m, int width = 10) noexcept {
    for(size_t i = 1; i <= m.numberOfRows(); ++i) {
        for(size_t j = 1; j <= m.numberOfColumns(); ++j) {
            if(j != 1)
                cout << " ";
            cout << setw(width) <<  m(i,j);
        }
        cout << endl;
    }
}
