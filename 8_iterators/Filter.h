
#ifndef LAB6_FILTER_H
#define LAB6_FILTER_H

#include <utility>


template < typename Container, typename Predicate>
class Filter {
    Container&& container;
    Predicate&& predicate;
public:
    class iterator {
        typename std::remove_reference_t<Container>::iterator current;
        typename std::remove_reference_t<Container>::iterator end;
        Predicate predicate;

        void find_next() {
            while (current != end && !predicate(*current)) {
                ++current;
            }
        }
    public:
        iterator(typename std::remove_reference_t<Container>::iterator begin,
                 typename std::remove_reference_t<Container>::iterator end,
                 Predicate p
                 ) : current(begin), end(end), predicate(p) {
            find_next();
        }

        decltype(auto) operator*() const {
            return *current;
        }

        decltype(auto) operator->() const {
            return &(*current);
        }

        iterator& operator++() {
            ++current;
            find_next();
            return *this;
        }

        iterator operator++(int) {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
    };

public:
    Filter(Container&& c, Predicate&& p) : container(std::forward<Container>(c)), predicate(std::forward<Predicate>(p)) {}

    iterator begin() const {
        return iterator(container.begin(), container.end(), predicate);
    }

    iterator end() const {
        return iterator(container.end(), container.end(), predicate);
    }
};


template <typename Container, typename Predicate>
Filter<Container, Predicate> make_filter(Container&& c, Predicate&& p) {
    return Filter<Container, Predicate>(std::forward<Container>(c), std::forward<Predicate>(p));
}


#endif //LAB6_FILTER_H
