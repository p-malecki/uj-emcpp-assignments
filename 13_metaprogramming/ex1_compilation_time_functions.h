#ifndef INC_13_METAPROGRAMMING_EX1_COMPILATION_TIME_FUNCTIONS_H
#define INC_13_METAPROGRAMMING_EX1_COMPILATION_TIME_FUNCTIONS_H

using ll = long long;



template<int number, int N>
struct Power {
    static const int value = number * Power<number, N-1>::value;
};

template<int number>
struct Power<number, 1> {
    static const int value = number;
};

template<int number>
struct Power<number, 0> {
    static const int value = 1;
};



template<int a, int b>
struct Min {
    static const int value = (a < b) ? a:b;
};

template<int n, int k>
struct Binomial {
    static const int new_k = Min<k, n-k>::value;
    static const ll value = Binomial<n-1, new_k>::value + Binomial<n-1, new_k-1>::value;
};

template<int n>
struct Binomial<n, n> {
    static const ll value = 1;
};

template<int n>
struct Binomial<n, 0> {
    static const ll value = 1;
};


#endif //INC_13_METAPROGRAMMING_EX1_COMPILATION_TIME_FUNCTIONS_H
