//
// Created by Sender on 5/26/21.
//

typedef char Stack_entry;

#include <iostream>
#include "stack.cpp"
#include <sstream>

int main() {
    Stack<Stack_entry> stack;
    for (int i = 0; i < 10; ++i) {
        std::stringstream ss;
        ss << i;
        stack.push(ss.str().c_str()[0]);
    }
    while (!stack.empty()) {
        Stack_entry item;
        stack.top(item);
        stack.pop();
        std::cout << item;
    }
}
