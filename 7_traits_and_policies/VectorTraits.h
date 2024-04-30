#ifndef LAB8_VECTORTRAITS_H
#define LAB8_VECTORTRAITS_H

template<typename T>
class VectorTraits {
public:
    typedef const T & ConstType;
    typedef const T & Scalar;
};

template<>
class VectorTraits<int> {
public:
    typedef const int ConstType;
    typedef const int Scalar;
};

template<>
class VectorTraits<double> {
public:
    typedef const double ConstType;
    typedef const double Scalar;
};

template<>
class VectorTraits<std::string> {
public:
    typedef const std::string ConstType;
    typedef const int Scalar;
};

template<typename T>
class is_string {
public:
    static constexpr bool value = false;
};

template<>
class is_string<std::string> {
public:
    static constexpr bool value = true;
};

#endif //LAB8_VECTORTRAITS_H
