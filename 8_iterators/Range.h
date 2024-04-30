

#ifndef LAB6_RANGE_H
#define LAB6_RANGE_H

template <typename T>
class Range{
    T start;
    T stop;
    T step;

    class Iterator {
        T current;
        T stop;
        T step;
    public:
        Iterator(T start, T stop, T step) : current(start), stop(stop), step(step) {}

        T operator*() const {
            return current;
        }

        Range<T>::Iterator& operator++() {
            current += step;
            return *this;
        }

        Range<T>::Iterator operator++(int) {
            auto tmp = Iterator(current, stop, step);
            ++(*this);
            return tmp;
        }

//        T operator->() const {
//            return current;
//        }

        bool operator==(const Iterator& other) const {
            return current == other.current || (stop == other.stop && current >= stop && other.current >= other.stop);
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    };

public:
    explicit Range(T stop) : start(0), stop(stop), step(1) {}
    Range(T start, T stop, T step=1) : start(start), stop(stop), step(step) {}

    Range<T>::Iterator begin() const {
        return Iterator(start, stop, step);
    }

    Range<T>::Iterator end() const {
        return Iterator(stop, stop, step);
    }
};


template <typename T>
Range<T> make_range(T stop) {
    return Range(stop);
}

template <typename T>
Range<T> make_range(T start, T stop) {
    return {start, stop};
}

template <typename T>
Range<T> make_range(T start, T stop, T step) {
    return {start, stop, step};
}

#endif //LAB6_RANGE_H
