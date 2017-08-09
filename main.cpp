//
// Created by Xu,Ming(RCPT) on 17/7/28.
//

#include <iostream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>

class iterator;

void pair(const char string[4], double d);

using namespace std;

int main() {
    std::cout << "Hello world!\n";
    std::cout << 5 << "\n";

    map<char, int, less<char> > map1;
    map<char, int, less<char> >::iterator mapIter;
    map1['c'] = 3;
    map1['d'] = 4;
    map1['a'] = 1;
    map1['b'] = 2;

    for (mapIter = map1.begin(); mapIter != map1.end(); ++mapIter)
        cout << " " << (*mapIter).first << ": " << (*mapIter).second << endl;

    std::map<std::string, double> map2;
    map2[std::string("abc")] = 1.0;
    map2[std::string("def")] = 2.3;
    map2.insert(make_pair("sdf", 32));
    map2.insert(std::map<std::string, double>::value_type("sdf", 3));
    std::map<std::string, double>::iterator iter;

    for (iter = map2.begin(); iter != map2.end(); iter++) {
        printf("%s : %.1f\n", iter->first.c_str(), iter->second);
//        cout << iter->first << " : " << iter->second << endl;
    }
}
