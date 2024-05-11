#include <iostream>
#include <vector>
#include "sfinae.h"
using namespace std;


int main() {
    cout << hasSize_v<int> << endl; // false
    cout << hasSize_v<vector<int>> << endl; //true
    cout << hasValueType_v<int> << endl; // false
    cout << hasValueType_v<vector<int>> << endl; //true


    std::vector<int> v{1,2,3,4,5};
    cout << v1::getSize(5) << endl;  // 4
    cout << v1::getSize(v) << endl; // 20
    cout << v2::getSize(5) << endl;  // 4
    cout << v2::getSize(v) << endl; // 20

}