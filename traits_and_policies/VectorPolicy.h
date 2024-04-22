
#ifndef LAB8_VECTORPOLICY_H
#define LAB8_VECTORPOLICY_H

template <typename InitPolicy, typename CheckPolicy>
class VectorPolicy : InitPolicy, CheckPolicy {
public:
    using InitPolicy::init;
    using CheckPolicy::check;
};


class InitPolicy{
public:
    template <typename T>
    static void init(T& data, size_t size) {
        std::fill(data, data + size, 0); // T()
    }
};

class NoInitPolicy{
public:
    template <typename T>
    static void init(T& data, size_t size) {}
};

class CheckPolicy{
public:
    static void check(int index, size_t size) {
        if (index < 0 || size <= index)
            throw std::runtime_error("Index out of bounds XXX");
    }
};

class NoCheckPolicy{
public:
    static void check(int index, size_t size) {}
};


typedef VectorPolicy<InitPolicy, CheckPolicy> SafePolicy;
typedef VectorPolicy<NoInitPolicy, NoCheckPolicy> FastPolicy;
typedef VectorPolicy<InitPolicy, NoCheckPolicy> InitFastPolicy;
typedef VectorPolicy<NoInitPolicy, CheckPolicy> NoInitSafePolicy;


#endif //LAB8_VECTORPOLICY_H
