//
// Created by Xu,Ming(RCPT) on 17/7/28.
//

#include "demo.h"
#include <iostream>
int main() {
    std::cout << "Hello world!\n";
    std::cout << 5;
    ((((std::cout << " == ") << 3) << " + ") << 2) << "\n";

    std::cout << 3 << " plus " << 2 << " equals " << 5 << "\n";

    return 0;
}