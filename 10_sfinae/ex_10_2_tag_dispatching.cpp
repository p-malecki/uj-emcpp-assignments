#include <iostream>
#include <vector>
#include <list>
#include "tag_dispatching.h"
using namespace std;


int main() {
    std::list<int> a{3, 2, 5, 1, 4};
    cout << median(a) << endl; // 3
    std::vector<int> v{3, 1, 4, 2};
    cout << median(v) << endl; // 2.5
}