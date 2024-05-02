//
// Created by Paweł Małecki on 02/05/2024.
//

#ifndef LAB9_STL_TOLOWERALPHA_H
#define LAB9_STL_TOLOWERALPHA_H

/**
 * Removes all non alphanumeric characters from given word and converts to lower case.
 * @param[in,out] word on return word consist only of lower case characters.
 */
void toLowerAlpha(std::string & s1) {
    //2. Implement using stl algorithms only
    //   Hint: use remove_if, transform, erase

    s1.erase(std::remove_if(std::begin(s1), std::end(s1),
                            [](auto c) {return !std::isalnum(c);}),
             std::end(s1));
    std::transform(std::begin(s1), std::end(s1), std::begin(s1),
                   [](auto c){return tolower(c);}
    );
}

#endif //LAB9_STL_TOLOWERALPHA_H
