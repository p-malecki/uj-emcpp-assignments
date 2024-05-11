#include <iostream>
#include <string>
#include <chrono>
#include <utility>
using namespace std::chrono;

class Timer {
    std::string name;
    std::chrono::steady_clock::time_point start;
public:
   Timer(std::string name) : name(std::move(name)), start(steady_clock::now()) {}

   ~Timer(){
       std::cout << name << " : " << duration_cast<microseconds>(steady_clock::now() - start).count() << " ms. " << std::endl;
   }
   auto durationInNanoseconds(){
       return duration_cast<nanoseconds>(steady_clock::now() - start).count();;
   }
};

long fibonacci(unsigned n){
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    Timer total("Total time");
    for(auto n : {1, 5, 15, 20, 25, 40, 45}){
        {
            Timer t("fibonacci(" + std::to_string(n) + ")");  // RAII
            fibonacci(n);

        }
    //2
    //3
    }
    std::cout << "Elapsed " << total.durationInNanoseconds() << " ns.\n";
}
/** Expected output similar to:

fibonacci(1) : 0.000619 ms.
fibonacci(5) : 0.000891 ms.
fibonacci(15) : 0.01025 ms.
fibonacci(20) : 0.094905 ms.
fibonacci(25) : 1.04443 ms.
fibonacci(40) : 989.97 ms.
fibonacci(45) : 8537.47 ms.
Elapsed 9528821533 ns.
Total time : 9528.84 ms.
*/