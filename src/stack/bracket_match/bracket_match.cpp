//
// Created by Sender on 5/26/21.
//

typedef char Stack_entry;

#include "bracket_match.h"
#include <iostream>
#include "../basic/stack.cpp"

using namespace std;

void bracket_match() {
    Stack<Stack_entry> brackets;
    Stack_entry symbol;
    bool is_matched = true;
    while (is_matched && (symbol = std::cin.get()) != '\n') {
        if (symbol == '(' || symbol == '{' || symbol == '[') {//todo
            brackets.push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {//todo
            char top_bracket;
            if (brackets.top(top_bracket) == underflow) {
                cout << "Brackets empty" << endl;
                break;
            }
            brackets.pop();
            //todo
            is_matched = top_bracket == '(' && symbol == ')'
                         || top_bracket == '[' && symbol == ']'
                         || top_bracket == '{' && symbol == '}';
            if (!is_matched) {
                cout << "Bad match" << endl;
            }
        }

        //todo
        if (!brackets.empty()) {
            cout << "Unmatched opening bracket(s) detected" << endl;
        }

    }

}
