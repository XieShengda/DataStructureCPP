//
// Created by Sender on 5/26/21.
//

#include <iostream>
#include "calculator.h"
#include "../basic/stack.cpp"

using namespace std;

char get_command() {
    char command;
    bool waiting = true;
    cout << "Select command and press<Enter>:";
    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q') {
            waiting = false;
        } else {
            cout << "Please enter a valid command:" << endl
                 << "[?]push to stack[=]print top" << endl
                 << "[+][-][*][/] are arithmetic operations" << endl
                 << "[Q]uit." << endl;
        }
    }
    return command;
}

bool do_command(const char &command, Stack<double> &numbers) {
    double p, q;
    switch (command) {
        case '?':
            cout << "Enter a real number:" << flush;
            cin >> p;
            if (numbers.push(p) == overflow) {
                cout << "Warning: Stack full, lost number" << endl;
            }
            break;
        case '=':
            if (numbers.top(p) == underflow) {
                cout << "Stack empty" << endl;
            } else {
                cout << p << endl;
            }
            break;
        case '+':
            if (numbers.top(p) == underflow) {
                cout << "Warning: Stack empty\n";
            } else {
                numbers.pop();
                if (numbers.top(q) == underflow) {
                    cout << "Warning: stack has just one entry" << endl;
                    numbers.push(p);
                } else {
                    numbers.pop();
                    numbers.push(q + p);
                }
            }
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case 'q':
            cout << "Calculation finished.\n";
            return false;
    }
    return true;
}

void instructions() {

}

void introduction() {

}