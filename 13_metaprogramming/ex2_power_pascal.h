#ifndef INC_13_METAPROGRAMMING_EX2_POWER_PASCAL_H
#define INC_13_METAPROGRAMMING_EX2_POWER_PASCAL_H

#include <cstdlib>


/**
 * Exercise 2a:
 * Implement function power that computes x^n
 * during compilation using recurrent formula
   x^2n = (x^n)^2
   x^2n+1 = (x^2n)*x
  */
consteval auto power(auto x, int n){
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return n;
    } else if (n % 2 == 0) {
        return 2 * power(x, n-1);
    } else {
        return x * power(x, n-1);
    }
}

constinit double fiveToPowerFour = power(5, 4);


/**
 *  Exercise 2b:
 * Implement function generate_triangle that during compilation
 * generates the Pascal trriangle of the given size N.
 * Pascal triangle
 * https://en.wikipedia.org/wiki/Pascal%27s_triangle
 *
 */


template <size_t N>
class PascalTriangle{
    std::array<int, N * (N + 1) / 2> triangle;
public:
    constexpr PascalTriangle() : triangle() {
        size_t index = 0;
        for (auto row = 0; row < N; ++row) {
            for (auto col = 0; col <= row; ++col) {
                if (col == 0 || col == row) {
                    triangle[index] = 1;
                } else {
                    auto prev_row_index = (row - 1) * row / 2;
                    triangle[index] = triangle[prev_row_index + col - 1] + triangle[prev_row_index + col];
                }
                ++index;
            }
        }
    }

    constexpr int operator()(size_t n, size_t m) const {
        auto row = n * (n + 1) / 2;
        return triangle[row + m];
    }

};

template <auto N>
constexpr PascalTriangle<N> generatePascalTriangle() {
    return {};
}


constexpr size_t n = 10;
constexpr auto triangle = generatePascalTriangle<n>();




#endif //INC_13_METAPROGRAMMING_EX2_POWER_PASCAL_H
