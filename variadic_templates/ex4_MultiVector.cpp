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

int main(){

  MultiVector<int, string, double> m;
  m.push_back(5);
  m.push_back(string("text"));
  m.push_back(7);
  m.push_back(1.2);
  m.print();   // [ 5 7 ] [ text ] [ 1.2 ]
  auto v = std::move(m);
  for(auto x: { 1, 2, 3}){
	v.push_back(x+10);
	v.push_back(std::to_string(x));
	v.push_back(x/10.0);
  }
  m.print(); // [ ] [ ] [ ]   but can be undefined
  v.print(); // [ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
  MultiVector<int, int, double, int> w;
  w.push_back(1);
  w.push_back(2.0);
  w.print(); // [ 1 ] [ ] [ 2 ] [ ]
}
/*
[ 5 7 ] [ text ] [ 1.2 ]
[ ] [ ] [ ]
[ 5 7 11 12 13 ] [ text 1 2 3 ] [ 1.2 0.1 0.2 0.3 ]
[ 1 ] [ ] [ 2 ] [ ]  
 */