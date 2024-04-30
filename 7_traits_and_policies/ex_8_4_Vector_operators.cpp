#include <iostream>
using namespace std;

template <int N>
class Vector{
  int data[N];
 public:
  Vector(){
	cout << " Default constr" << endl;
  }
  Vector(std::initializer_list<int> list){
	cout << " Init list constr" << endl;
	auto it = list.begin();
	for(int i=0; i<N; i++) {
	  data[i] = *it++;
	}
  }
  Vector(const Vector & m){
	std::copy(m.data, m.data+N, data);
	cout << " Copy constr" << endl;
  }

  int operator[](int index) const {
	return data[index];
  }
  int & operator[](int index){
	return data[index];
  }

  friend ostream & operator << (ostream & out, const Vector & m){
	for(auto x : m.data){
	  cout << x << ", ";
	}
	return out;
  }
};

template <typename L, typename R>
struct AddNode {
    L left;
    R right;

    auto operator[] (int i) const {
        return left[i] + right[i];
    }

    template<int T>
    operator Vector<T>() const {
        Vector<T> result;
        for (auto i=0; i < T; i++) {
            result[i] = this[i];
        }
        return result;
    }
};

template <typename L, typename R>
struct SubNode {
    L left;
    R right;

    decltype(auto) operator[] (int i) const {
        return left[i] - right[i];
    }

    template<int T>
    operator Vector<T>() const {
        Vector<T> result;
        for (auto i=0; i < T; i++) {
            result[i] = left[i] - right[i];
        }
        return result;
    }
};

template <typename R>
struct MultiplyNode {
    int left;
    R right;

    auto operator[] (int i) const {
        return left * right[i];
    }

    template<int T>
    operator Vector<T>() const {
        Vector<T> result;
        for (auto i=0; i < T; i++)
            result[i] = this[i];
        return result;
    }
};


// TODO ADD OP POLICIES, RM ADDNODE, SUBNODE
template <typename L, typename R, typename Op>
struct Node {
    L left;
    R right;

    auto operator[] (int i) const {
        return Op::op(left[i], right[i]);
    }

    template<int T>
    operator Vector<T>() const {
        Vector<T> result;
        for (auto i=0; i < T; i++) {
            result[i] = this[i];
        }
        return result;
    }
};


template<typename L, typename R>
AddNode<L, R> operator+(L && l, R && r) {
    return {l, r};
}

template<typename L, typename R>
SubNode<L, R> operator-(L && l, R && r) {
    return {l, r};
}

template<typename R>
MultiplyNode<R> operator*(int l, R && r) {
    return {l, r};
}



int main(){
  using V = Vector<10>;
  V v{1,2,3,4,5,6,7,8,9,10};
  V x(v);
  V y{4,4,2,5,3,2,3,4,2,1};

  cout << "Lazy operations :\n";
  // It does not create temporary Vectors
  // It computes resulting vector coordinate by coordinate
  // (evaluating whole expression)
  V z = v + x + 3 * y - 2 * x;
  cout << z << endl;

  // Computes only one coordinate of Vector
  int e = (z+x+y)[2];
  cout << " e = " << e << endl;
  return 0;
}
/**
 Init list constr
 Copy constr
 Init list constr
Lazy operations :
 Default constr
12, 12, 6, 15, 9, 6, 9, 12, 6, 3,
e = 11
 */
