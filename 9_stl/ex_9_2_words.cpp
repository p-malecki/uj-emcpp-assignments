#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "toLowerAlpha.h"
using namespace std;

/**
 * Removes all non alphanumeric characters from given word and converts to lower case.
 * @param[in,out] word on return word consist only of lower case characters.
 */
//void toLowerAlpha(std::string & s1);


int main(){
    int count = 0;
    std::string word;
    map<string, int> c;
    std::vector<int> v;

    std::ifstream in("../hamletEN.txt");
    std::cin.rdbuf(in.rdbuf());

    while(cin >> word) {
       toLowerAlpha(word);
       if(!word.empty()){
           if (c[word] == 0) {
               count++;
           }
           c[word]++;
       }
    }

    multimap<int, string> m2;
    for (const auto& p : c) {
        m2.insert({p.second, p.first});
    }


    cout << "Number of distinct words : " << count << endl;
    cout << "\nThe top 20 most popular words: \n";

    auto it = rbegin(m2);
    for (int i = 0; i < 20 && it != m2.rend(); ++i, ++it) {
        std::cout << it->second << " : " << it->first << std::endl;
    }

    return 0;
}
/*
 * Expected output for ./words < hamletEN.txt

Number of distinct words : 4726

The top 20 most popular words:
the : 1145
and : 967
to : 745
of : 673
i : 569
you : 550
a : 536
my : 514
hamlet : 465
in : 437
it : 417
that : 391
is : 340
not : 315
lord : 311
this : 297
his : 296
but : 271
with : 268
for : 248
your : 242

 */