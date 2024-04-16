#ifndef VARIADIC_TEMPLATES_PROXY_H
#define VARIADIC_TEMPLATES_PROXY_H

#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>
using namespace std;


template <typename... Ts>
void showNames(Ts&&... args) {
    int i = 1;
    ((cout << i++ << " > " << boost::typeindex::type_id_with_cvr<Ts>().pretty_name() << " [" << typeid(Ts).name() << "] = " << args << endl), ...);
}

template <typename F>
class Proxy {
    const F function;
public:
    explicit Proxy(F func) : function(func) {}

    template <typename... Ts>
    auto operator()(Ts&&... args) const {
        showNames(std::forward<Ts>(args)...);
        return function(std::forward<Ts>(args)...);
    }
};


template <typename F>
Proxy<F> make_proxy(F&& func) {
    return Proxy<F>(std::forward<F>(func));
}


#endif //VARIADIC_TEMPLATES_PROXY_H
