#include "futures_and_promises.h"
#include <iostream>
#include <vector>


int main(int argc, char* argv[]) {
    if (argc < 2)
        return 1;

    std::vector<std::string> filenames(argv + 1, argv + argc);
    std::cout << "SUMS:\n";
    computeFilesAsciiSum(filenames);

    return 0;
}

