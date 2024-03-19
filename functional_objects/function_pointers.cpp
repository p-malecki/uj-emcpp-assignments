#include <iostream>
#include <cmath>
using namespace std;


/// Computes n-th root of x
double sqrtn(int n, double x){
	return exp( log(x) / n);
}

double power(double  x, double y){
	return exp( log(x) * y);
}

template <typename F, typename G>
double function(int n, double y, double z, F f, G g){
	return (f(n,y) > z) ? g(z, y) : g(y, z);
}

int main(){

	typedef double (*FunPtr1)(int, double);
	typedef double (*FunPtr2)(double, double);
	typedef double (*FunPtr3)(int, double, double, FunPtr1, FunPtr2);

	FunPtr1 fp1 = sqrtn;
	FunPtr2 fp2 = power;
	FunPtr3 fp3 = function<FunPtr1, FunPtr2>;

	cout << fp3(2, 10, 3, fp1, fp2) << endl;
	cout << fp3(3, 10, 3, fp1, fp2) << endl;
	return 0;
}