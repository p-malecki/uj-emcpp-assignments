#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>
#include <ctime>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;


template <int N>
struct Array {
    std::mutex g1_mtx;
    std::mutex g2_mtx;
    std::mutex s_mtx;

    int a[N];
    int i  = 0;
    int j  = 0;
    int value = 1;
	long long sum = 0;

	int f(int x){
		int y = x%11;
		return (y*y+1);
	}

    void generateArray() {
        while (true) {
            int j;
            {
                const std::lock_guard<std::mutex> lock(g1_mtx);
                if (i >= N)
                    break;
                j = i++;
            }
            a[j] = rand();
        }

        while (true) {
            int k;
            {
                const std::lock_guard<std::mutex> lock(g2_mtx);
                if (i >= N * 2) break;
                k = i++ - N;
            }
            a[k] = f(a[k]);
        }
    }
	
	long long computeSum(){

	    sum = 0;
		for(int x : a){
            const std::lock_guard<std::mutex> lock(s_mtx);
            sum += x;
		}
		return sum;
	}
};


int main(){
	srand(2019);
	using A = Array<1000>;
	A array;

    auto start = std::chrono::high_resolution_clock::now();

    auto threads_num = 4;
    std::vector<std::thread> threads;
    threads.reserve(threads_num);
    for (auto i = 0; i < threads_num; ++i)
        threads.emplace_back(&A::generateArray, &array);
    for (auto i = 0; i < threads_num; ++i)
        threads[i].join();


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";


    for(int i=0; i<40; i++){
		cout << array.a[0+i] << "  ";
	}
	long long sum = array.computeSum();
	cout << "\n sum = " << sum << endl;	
}
