#ifndef INC_10_SFINAE_SFINAE_H
#define INC_10_SFINAE_SFINAE_H
#import <type_traits>
#import <iostream>

template <typename T, typename = void>
struct hasSize : std::false_type {};

template <typename T>
struct hasSize<T, std::void_t<decltype(std::declval<T>().size())>> :  std::true_type {};

template <typename T>
inline constexpr bool hasSize_v = hasSize<T>::value;


template <typename T, typename = void>
struct hasValueType : std::false_type {};

template <typename T>
struct hasValueType<T, std::void_t<typename T::value_type>> :  std::true_type {};

template <typename T>
inline constexpr bool hasValueType_v = hasValueType<T>::value;



namespace v1 {

    template <typename T, std::enable_if_t<!std::conjunction_v<hasSize<T>, hasValueType<T>>, bool> = true>
    auto getSize(const T& x) {
        return sizeof(x);
    }

    template <typename T, std::enable_if_t<std::conjunction_v<hasSize<T>, hasValueType<T>>, bool> = true>
    auto getSize(const T& x) {
        return sizeof(typename T::value_type) * x.size();
    }
}

namespace v2 {

    template <typename T>
    auto getSize(const T& x) {
        if constexpr (std::conjunction_v<hasSize<T>, hasValueType<T>>) {
            return sizeof(typename T::value_type) * x.size();
        }
        else {
            return sizeof(x);
        }
    }
}


#endif //INC_10_SFINAE_SFINAE_H
