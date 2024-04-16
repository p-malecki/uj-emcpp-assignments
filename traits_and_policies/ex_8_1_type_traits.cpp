#include <iostream>
using  namespace std;
/**
 * Outputs information about numerical type T:
 * (un)signed, (not) integer, min & max values
*/
template <typename T>
void info(T x){
    cout << ((is_signed_v<T> == true) ? "signed, " : "unsigned, ");
    cout << ((is_integral_v<T> == true) ? "integer, " : "not integer, ");
    cout << "min : " << numeric_limits<T>::min();
    cout << " max : " << numeric_limits<T>::max() << endl;
}

int main() {
    info(1);
    info(2.0f);
    info(3U);
    return 0;
}
/**
 * Expected output:
    signed,  integer, min : -2147483648 max : 2147483647
    signed, not integer, min : 1.17549e-38 max : 3.40282e+38
    unsigned,  integer, min : 0 max : 4294967295
 */