#pragma once
#include <iostream>
#include <algorithm>
#include <memory>

#include "MyString.h"
using namespace std;

class String{
   using string = emcpp::MyString;
//    using string = std::string;

/// Store a pointer to dynamically allocated string!
    std::shared_ptr<string> pstring = nullptr;

public:
    String()     /// creates an empty string
    {
        pstring = make_shared<string>();
    }
    explicit String(const char* str)           /// copy C-string
    {
        pstring = make_shared<string>(str);
    }
    String(const String& str)           /// no copy
    {
        pstring = std::move(str.pstring);
    }
    String operator=(const String& s ) /// no copy
    {
        pstring = s.pstring;
    }

    void set(const int index, const char ch) /// makes a copy of a string if it has more than one reference.
    {
        if (pstring.use_count() > 1)
        {
            pstring = make_shared<string>(*pstring);
        }
        pstring->at(index) = ch;
    }
    [[nodiscard]] char get(const int index) const /// no copy
    {
        return pstring->at(index);
    }

    friend String operator+(const String& a, const String& b) /// creates a new string only if both strings are non empty
    {
        if (!a.pstring->empty() && !b.pstring->empty())
        {
            return String((static_cast<std::string>(*a.pstring) + static_cast<std::string>(*b.pstring)).c_str());
        }
        if (!b.pstring->empty()) return  b;
        return  a;
    }
    friend std::ostream& operator<<(std::ostream& out, const String& s)
    {
        return (out << *s.pstring);
    }

};
