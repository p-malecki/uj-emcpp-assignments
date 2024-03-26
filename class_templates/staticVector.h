
#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H


#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

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
        fill_n(data, N, 0);
    }
    Vector(const Vector & v) {
        copy_n(v, N, data);
    }
    Vector& operator=(const Vector & m) {

    }
    Vector(const std::initializer_list<T>& list) {
        if (list.size() >= N) {
            copy_n(list, N, data);
        }
        else {
            fill_n(data, N, 0);
            copy_n(list, list.size(), data);
        }

    }

    friend Vector operator+ (const Vector& u, const Vector& v ){
        Vector t(u);
        for(int i=0; i < u.size(); i++)
            u[i] = u[i] + v[i];
        return t;
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

    reference operator[](size_type index){
        return data[index];
    }
    const_reference operator[](size_type index) const{
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for( auto elem: v.data ){
            out << elem << " ";
        }
        return out;
    }

};

#endif //STATIC_VECTOR_H