#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
using namespace std;

template <typename T>  // A
T sqr(T x) {
    return  x * x;
}

template<>
string sqr(string x) {
    return  x + x;
}


template <int T>  // B
int mod(int a, int b) {
    return (a + b) % T;
}

template <>
int mod<0>(int a, int b) {
    return (a + b) % T;
}

template <typename T, typename Alloc, template<typename, typename> class Container>  // C
void print(const Container<T, Alloc >& container) {
    for_each(container.begin(), container.end(), [&container](const auto& x){ cout << x << " "; });
    cout << endl;
}

template <typename T, size_t sizeOfArray>
void print(T (&array)[sizeOfArray]) {
    for_each(array, array+sizeOfArray, [&array, i=0](const auto& x) mutable { cout << *(array + i++) << " "; });
    cout << endl;
}


template <typename C, typename F>  // D
C applyFun(const C& container, F f) {
    decltype(auto) result = C();
    for_each(container.begin(), container.end(), [&result, &f](const auto& x){ result.push_back(f(x)); });
    return result;
}


template <typename T, T (*f)(T), size_t N>  // E
void process(T (&array)[N]) {
    for_each(array, array+N, [&array, i=0](const auto& x) mutable { *(array + i++) = f(x); });
}



int main(){

    // function template  sqr<T>
    cout << sqr(4) << endl;             // 16
    cout << sqr(14.5) << endl;          // 210.25
    cout << sqr(string("hey")) << endl; // heyhey


    // function template mod<N>
    cout << mod<5>(130,1) << endl;        // 1
    cout << mod<7>(1,130) << endl;        // 5
    cout << mod<0>(13,14) << endl;        // 27


    //function template print
    std::vector<int> v = {1, 21, 34, 4, 15};
    print(v);                    // 1 21 34 4 15

    std::list<double> l = {1, 2.1, 3.2, 6.3};
    print(l);                    // 1 2.1 3.2 6.3

    double tab[] = {1.2, 3.4, 5.5};
    print(tab);                  // 1.2 3.4 5.5


    using namespace std::placeholders;  // for _1, _2, _3...
    // function template applyFun
    auto w = applyFun(v, sqr<int>);
    print(w);  // 1 441 1156 16 225

    // applyFun accepts unary function so we bind the first argument of mod<5>
    auto w2 = applyFun(w, std::bind(mod<5>, 4, _1));
    print(w2); // 0 0 0 0 4

    auto w3 = applyFun(w, [](int a){return mod<0>(a, 3);}  );
    print(w3); // 4 444 1159 19 228

    auto l2 = applyFun(l, sqr<double>);
    print(l2); // 1 4.41 10.24 39.69

    auto l3 = applyFun(l2, std::bind(mod<5>, _1, 2));
    print(l3); // 3 1 2 1

    // function sin is overloaded, we need to cast it
    auto l4 = applyFun(l3, static_cast<double(*)(double)>(std::sin));
    print(l4); // 0.14112 0.841471 0.909297 0.841471


    double a[] = {1, 2, 3, 4};
    process<double, sin, 4> (a);
    print(a);  // 0.841471 0.909297 0.14112 -0.756802

    return 0;
}
/**
16
210.25
heyhey
1
5
27
1 21 34 4 15
1 2.1 3.2 6.3
1.2 3.4 5.5
1 441 1156 16 225
0 0 0 0 4
4 444 1159 19 228
1 4.41 10.24 39.69
3 1 2 1
0.14112 0.841471 0.909297 0.841471
0.841471 0.909297 0.14112 -0.756802
*/