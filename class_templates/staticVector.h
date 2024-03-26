
#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

template <typename T, size_t N>
class Vector{
    T data[N];

public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector() {
        std::fill_n(data, N, 0);
    }

    Vector(const Vector& v) {
        std::copy_n(v.data, N, data);
    }

    Vector& operator=(const Vector& m) {
        std::copy_n(m.data, N, data);
        return *this;
    }

    Vector(const std::initializer_list<T>& list) {
        std::copy_n(list.begin(), std::min(N, list.size()), data);
        std::fill_n(data + list.size(), N - list.size(), 0);
    }

    template <typename S, size_t M>
    explicit Vector(const Vector<S, M>& other) {
        size_type copySize = std::min(N, M);
        for (size_type i=0; i < copySize; i++) {
            data[i] = static_cast<T>(other[i]);
        }
    }

    explicit Vector(const Vector<T, 0>& other) {
        std::copy_n(other.data.get(), N, data);
        std::fill_n(data + other.size(), N - other.size(), 0);
    }

    constexpr size_type size() const {
        return N;
    }

    const_reference get(size_type index) const {
        return data[index];
    }

    void set(size_type index, const_reference value) {
        data[index] = value;
    }

    reference operator[](size_type index) {
        return data[index];
    }
    const_reference operator[](size_type index) const {
        return data[index];
    }

    friend Vector operator+ (const Vector& u, const Vector& v ) {
        Vector t(u);
        for(int i=0; i < u.size(); i++)
            t[i] = u[i] + v[i];
        return t;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for(auto elem: v.data)
            out << elem << " ";
        return out;
    }

};

#endif //STATIC_VECTOR_H