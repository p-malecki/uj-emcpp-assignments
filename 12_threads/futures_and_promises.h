#ifndef INC_12_THREADS_FUTURES_AND_PROMISES_H
#define INC_12_THREADS_FUTURES_AND_PROMISES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <thread>
#include <future>


void computeAsciiSum(const std::string& filename, std::promise<int>&& promise) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        promise.set_value(-1);
        return;
    }

    int sum = 0;
    char c;
    while (file.get(c)) {
        sum += static_cast<unsigned char>(c);
    }
    file.close();
    promise.set_value(sum);
}


void computeFilesAsciiSum(std::vector<std::string> filenames) {
    std::vector<std::thread> threads;
    std::vector<std::future<int>> futures;
    std::vector<std::promise<int>> promises(filenames.size());

    for (auto i = 0; i < filenames.size(); ++i) {
        promises[i] = std::promise<int>();
        futures.push_back(promises[i].get_future());
        threads.emplace_back(computeAsciiSum, filenames[i], std::move(promises[i]));
    }

    for (auto& t : threads)
        t.join();


    for (auto i = 0; i < filenames.size(); ++i) {
        auto sum = futures[i].get();
        if (sum != -1) {
            std::cout << "file: " << filenames[i] << " sum: " << sum << std::endl;
        }
        else {
            std::cout << "error reading file: " << filenames[i] << std::endl;
        }
    }
}


#endif //INC_12_THREADS_FUTURES_AND_PROMISES_H
