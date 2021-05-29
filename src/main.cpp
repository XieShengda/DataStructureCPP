#include "stack/basic/stack.h"
#include <iostream>
int main() {
    Stack<double> stack;
    stack.push(1.1);
    double d;
    stack.top(d);
    std::cout<<d;
}