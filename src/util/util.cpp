//
// Created by 谢胜达 on 5/9/21.
//

#include <string>
#include <iostream>
#include "util.h"

using namespace std;

template<typename T>
void swap(T &a, T &b) {
//    a = a + b;
//    b = a - b;
//    a = a - b;
//此替换法弊端：a和b不能位于同一地址，否则最后两个值都会变为0

    T temp = a;
    a = b;
    b = temp;
}

bool user_says_yes() {
    char c;
    bool init_response = true; // It's the first time to input command.
    do {
        if (init_response) {
            cout << "(y,n)?" << flush;
        } else {
            cout << "Respond with either y or n:" << flush;
        }
        do {
            c = cin.get();
        } while (c == '\n' || c == ' ' || c == '\t'); // Ignore white space.
        init_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N'); // Loop when input is illegal.
    return c == 'y' || c == 'Y';
}