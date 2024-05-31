#ifndef INC_13_METAPROGRAMMING_EX3_INTEGERLIST_H
#define INC_13_METAPROGRAMMING_EX3_INTEGERLIST_H


template <int ... Args>
class IntegerList {
public:
    static constexpr size_t size = sizeof...(Args);

    static constexpr int get(int index) {
        int arr[] = { Args... };
        return arr[index];
    }

    static constexpr int max() {
        int arr[] = { Args... };
        int max = arr[0];
        for (auto elem : arr) {
            max = (elem > max) ? elem:max;
        }
        return max;
    }
};


template <int... Args>
std::ostream& operator<<(std::ostream& os, const IntegerList<Args...>&) {
    int arr[] = { Args... };
    for (size_t i = 0; i < sizeof...(Args); ++i)
        os << arr[i] << " ";
    return os;
}


template <size_t index, typename IntegerList>
struct getInt {
    static constexpr int value = IntegerList::get(index);
};


template <typename IntegerList1, typename IntegerList2>
struct Join {
    using type = IntegerList1;
};

template <int... Args1, int... Args2>
struct Join<IntegerList<Args1...>, IntegerList<Args2...>> {
    using type = IntegerList<Args1..., Args2...>;
};


template <typename IntegerList>
struct IsSorted {
    static const bool value = true;
};

template <>
struct IsSorted<IntegerList<>> {
    static const bool value = true;
};

template <int a>
struct IsSorted<IntegerList<a>> {
    static const bool value = true;
};

template <int a, int b, int... Args>
struct IsSorted<IntegerList<a, b, Args...>> {
    static const bool value = (a < b) && IsSorted<IntegerList<b, Args...>>::value;
};


template <typename IntegerList>
struct Max {
    static const int value = 0;
};

template <int a>
struct Max<IntegerList<a>> {
    static const int value = a;
};

template <int a, int b, int... Args>
struct Max<IntegerList<a, b, Args...>> {
    static const int value = (((a > b) ? a:b) > Max<IntegerList<Args...>>::value) ?
                             ((a > b) ? a:b) :
                             Max<IntegerList<Args...>>::value;
};

#endif //INC_13_METAPROGRAMMING_EX3_INTEGERLIST_H
