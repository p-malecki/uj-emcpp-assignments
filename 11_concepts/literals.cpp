#include <iostream>
using namespace std;


/**
    Computes velocity in meters per seconds.
    @param distance  distance in meters
    @param time      time in seconds
    @return velocity in meters per seconds.
*/
double computeVelocity(double distance, double time){
    return distance/time;
}


long double constexpr operator ""_cm(long double value) {
    return value / 100;
}
long double constexpr operator ""_cm(unsigned long long value) {
    return (long double)value / 100.0;
}

long double constexpr operator ""_m(long double value) {
    return value;
}
long double constexpr operator ""_m(unsigned long long value) {
    return (long double)value;
}

long double constexpr operator ""_km(long double value) {
    return value * 1000;
}
long double constexpr operator ""_km(unsigned long long value) {
    return (long double)value * 1000;
}

long double constexpr operator ""_ms(long double value) {
    return value / 1000;
}
long double constexpr operator ""_ms(unsigned long long value) {
    return (long double)value / 1000;
}

long double constexpr operator ""_s(long double value) {
    return value;
}
long double constexpr operator ""_s(unsigned long long value) {
    return (long double)value;
}

long double constexpr operator ""_h(long double value) {
    return value * 3600;
}
long double constexpr operator ""_h(unsigned long long value) {
    return (long double)value * 3600;
}


int main(){
    cout << computeVelocity(100_m, 5_s) << endl;     //20
    cout << computeVelocity(360_km, 2.0_h) << endl;  //50
    cout << computeVelocity(3.6_km, 0.02_h) << endl; //50
    cout << computeVelocity(250_cm, 2.5_ms) << endl; //1000
    return 0;
}
