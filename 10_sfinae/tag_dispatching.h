#ifndef INC_10_SFINAE_TAG_DISPATCHING_H
#define INC_10_SFINAE_TAG_DISPATCHING_H
#include <type_traits>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>


template <typename Container>
double median_helper(Container first, Container last, std::random_access_iterator_tag) {
    auto n = std::distance(first, last);
    std::sort(first, last);
    return (n % 2 == 0) ? static_cast<double>(first[n/2 - 1] + first[n/2]) / 2. : first[n/2];
}

template <typename Container>
double median_helper(Container first, Container last, std::forward_iterator_tag) {
    auto n = std::distance(first, last);
    std::vector<typename std::iterator_traits<Container>::value_type> tmp(first, last);
    std::sort(tmp.begin(), tmp.end());
    return (n % 2 == 0) ? static_cast<double>(tmp[n/2-1] + tmp[n/2]) / 2. : tmp[n/2];
}

template <typename Container>
double median(Container set) {
    using iterator = typename Container::iterator;
    using category = typename std::iterator_traits<iterator>::iterator_category;
    return median_helper(set.begin(), set.end(), category());
}


#endif //INC_10_SFINAE_TAG_DISPATCHING_H


// https://stackoverflow.com/questions/25478892/correct-way-to-test-if-a-container-implements-at-member-access-stdsort-co