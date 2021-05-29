//
// Created by Sender on 5/26/21.
//
#include "calculator.cpp"

int main() {
    Stack<double> stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));
}