
#ifndef LAB8_VECTOR_H
#define LAB8_VECTOR_H

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "VectorTraits.h"
#include "VectorPolicy.h"


template <typename T,
        size_t N,
        typename ClassPolicy=FastPolicy>
class Vector : ClassPolicy {
  T data[N];
 public:
  typedef T value_type;
  typedef std::size_t size_type;
  typedef T* pointer;
  typedef T& reference;
  typedef typename VectorTraits<T>::ConstType const_reference;
  typedef typename VectorTraits<T>::Scalar scalar;
  using ClassPolicy::init;
  using ClassPolicy::check;

  Vector() {
      init(data, N);
  }
  Vector(const Vector & v) = default;
  Vector &operator=(const Vector & m) = default;

  Vector(const std::initializer_list<T> & list){
	std::copy(list.begin(), list.end(), data);
  }

  size_type size() const {
	return N;
  }

  const_reference get(size_type index) const {
      check(index, N);
	  return data[index];
  }

  void set(size_type index, const_reference value) {
      check(index, N);
      data[index] = value;
  }

  // TODO FIX
  friend Vector operator* (const scalar && x, const Vector & v){
	Vector result;
    if constexpr(is_string<T>::value) {
//        for(auto i=0; i < v.size(); i++){
//            std::string concatenated_str;
//            for (auto j=0; j < x; j++)
//                concatenated_str += v.get(i);
//            result.set(i, concatenated_str);
//        }
    }
    else {
        for(int i=0; i < v.size(); i++){
            result.set(i, ClassPolicy::multiply(x, * v.get(i)));
        }
    }
	return result;
  }

  friend std::ostream &operator<<(std::ostream & out, const Vector & v) {
	for(int i=0; i < v.size(); ++i){
	  out << v.get(i) << " ";
	}
	return out;
  }

  friend std::istream &operator>>(std::istream & in, Vector & v) {
	Vector::value_type value;
	for(int i=0; i < v.size(); ++i){
	  in >> value;
	  if(in)
		v.set(i, value);
	}
	return in;
  }

};

#endif // LAB8_VECTOR_H