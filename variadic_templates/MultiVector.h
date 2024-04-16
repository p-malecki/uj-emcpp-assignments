#ifndef VARIADIC_TEMPLATES_MULTIVECTOR_H
#define VARIADIC_TEMPLATES_MULTIVECTOR_H

#include <iostream>
#include <vector>
using namespace std;

template<typename... Types>
class MultiVector;

template<>
class MultiVector<> {
public:
    void push_back() {}
    void print() { cout << endl; }
};

template<typename T, typename... Rest>
class MultiVector<T, Rest...> {
    std::vector<T> data;
    MultiVector<Rest...> rest;

public:
    void push_back(const T& value) {
        data.push_back(value);
    }

    template<typename U>
    void push_back(const U& value) {
        rest.push_back(value);
    }

    void print() {
        cout << "[ ";
        std::for_each(data.begin(), data.end(), [](auto elem){ cout << elem << " "; });
        cout << "] ";

        rest.print();
    }

    std::vector<T>& getVector() {
        return data;
    }

    MultiVector<Rest...>& getNext() {
        return rest;
    }
};

#endif //VARIADIC_TEMPLATES_MULTIVECTOR_H
