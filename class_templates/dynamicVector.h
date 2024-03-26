#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "staticVector.h"

class VectorException : public std::runtime_error {
public:
    VectorException(const std::string& message) : std::runtime_error(message) {}
};

template <typename T, size_t N>
class Vector;

template <typename T>
class Vector<T, 0>{
    std::unique_ptr<T[]> data;
    size_t currentSize;
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector(size_t newSize): currentSize(newSize) {
        data = std::make_unique<T[]>(currentSize);
        std::fill_n(data.get(), currentSize, 0);
    }

    Vector(const Vector& v): currentSize(v.size()) {
        data = std::make_unique<T[]>(currentSize);
        for (size_t i = 0; i < currentSize; i++) {
            data[i] = v.data[i];
        }
    }

    Vector(const std::initializer_list<T>& list) : currentSize(list.size()) {
        data = std::make_unique<T[]>(currentSize);
        std::copy(list.begin(), list.end(), data.get());
        std::fill_n(data.get() + list.size(), currentSize - list.size(), 0);
    }

    Vector& operator=(const Vector& m) {
        this->resize(m.size());
        std::copy_n(m.data.get(), currentSize, data);
        return *this;
    }

    template <typename S, size_t M>
    explicit Vector(const Vector<S, M>& other) : currentSize(M) {
        data = std::make_unique<T[]>(currentSize);
        for (size_type i=0; i < currentSize; i++) {
            data[i] = static_cast<T>(other[i]);
        }
    }

    template<size_t N>
    explicit Vector(const Vector<T, N>& other) : currentSize(N) {
        data = std::make_unique<T[]>(currentSize);
        std::copy(other.data.get(), other.data.get() + currentSize, data.get());
    }

    friend Vector operator+ (const Vector& u, const Vector& v ) {
        if (u.size() != v.size())
            throw VectorException("incompatible sizes in Vector::operator+");
        Vector result(u);
        for(int i=0; i < u.size(); i++)
            result[i] = u[i] + v[i];
        return result;
    }

    constexpr size_type size() const {
        return currentSize;
    }

    const_reference get(size_type index) const {
        return data[index];
    }

    void set(size_type index, const_reference value) {
        data[index] = value;
    }

    void resize(size_type newSize) {
        if (currentSize == newSize) return;

        std::unique_ptr<T[]> tmp = std::make_unique<T[]>(newSize);
        size_t copySize = std::min(currentSize, newSize);
        for (size_t i = 0; i < copySize; i++) {
            tmp[i] = data[i];
        }
        std::fill_n(tmp.get() + copySize, newSize - copySize, 0);
        data = std::move(tmp);
        currentSize = newSize;
    }

    reference operator[](size_type index){
        assert(index < currentSize);
        return data[index];
    }
    const_reference operator[](size_type index) const {
        assert(index < currentSize);
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        for (size_t i = 0; i < v.currentSize; ++i) {
            out << v.data[i] << " ";
        }
        return out;
    }
};


#endif //STATIC_VECTOR_H