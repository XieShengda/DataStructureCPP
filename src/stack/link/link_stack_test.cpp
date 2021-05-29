//
// Created by Sender on 5/29/21.
//

#include "link_stack.cpp"
#include <iostream>

using namespace std;

int main() {
    Stack stack{};
    int item = 1;
    cout << "Push item: " << item << endl;
    stack.push(item);
    int a;
    stack.top(a);

    cout << "Stack is empty? " << (stack.empty() ? "yes" : "no") << endl
         << "Top entry is: " << a << endl;
    stack.pop();
    cout << "Pop item" << endl;
    cout << "Pop success? " << (stack.empty() ? "yes" : "no") << endl;
}