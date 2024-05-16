#include <iostream>
#include <vector>
#include <numeric>
#include <iterator> // For std::accumulate
using namespace std;


template<typename T>
concept Printable = requires(T obj) {
    obj.print();
};

template<typename T>
concept Leftshift = requires(T obj) {
    std::cout << obj;
};

template <typename T>
concept Container = requires(T container) {
    std::accumulate(std::begin(container), std::end(container), typename T::value_type{});
};


template <typename  T>
class A{
protected:
    T x;
public:
    A(T x = T()) : x(x) {}
    void print() const{
        cout << "[" << x << "]";
    }
    friend A operator+(const A & a, const A & b){
        return a.x + b.x;
    }
};

template <typename T>
class B: public A<T>{
public:
    using A<T>::A;
    friend std::ostream & operator<<(std::ostream & out, const B & b){
        return (out << "#" << b.x << "#");
    }

    friend B operator+(const B & a, const B & b){
        return a.x + b.x;
    }
};


template<typename T>
void print(const T& obj) {
    if constexpr(Leftshift<T>) {
        std::cout << obj;
    }
    else if constexpr(Printable<T>) {
        obj.print();
    }
    cout << endl;
}

template<Container C>
void print(const C& container) {
    int i{};
    for (const auto& element : container) {
        cout << i++ << " : ";
        print(element);
        //cout << endl;
    }
    cout << "---------\n";
}

template<typename T>
auto sum(const T& vec) {
    return accumulate(vec.begin(), vec.end(), typename T::value_type());
}

int main() {
    vector<int> v{1,2,4,5};
    print(v);
    A<int> a{5};
    print(a);
    B<double> b{3.14};
    print(b);
    print(2.7);
    vector<A<int>> va{ 4, 5, 7, 9};
    vector<B<int>> vb{ 4, 5, 7, 9};
    print(va);
    print(vb);
    print( sum(v) );
    print( sum(vb) );
    return 0;
}


/**
* Expected output
0 : 1
1 : 2
2 : 4
3 : 5
-------
[5]
#3.14#
2.7
0 : [4]
1 : [5]
2 : [7]
3 : [9]
-------
0 : #4#
1 : #5#
2 : #7#
3 : #9#
-------
12
#25#
*/
