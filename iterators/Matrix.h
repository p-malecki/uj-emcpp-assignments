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
