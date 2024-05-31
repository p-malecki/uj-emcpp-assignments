#include <array>
#include <iostream>
#include <cmath>
#include "ex2_power_pascal.h"


int main(){

    static_assert(triangle(0,0) == 1);
    static_assert(triangle(5,3) == 10);
    static_assert(triangle(9,4) == 126);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            std::cout << triangle(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
