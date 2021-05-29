//
// Created by Sender on 5/25/21.
//

#include "stack.h"

template<typename Stack_entry>
Stack<Stack_entry>::Stack() {
    count = 0;
}

template<typename Stack_entry>
bool Stack<Stack_entry>::empty() const {
    return count == 0;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item) {
    Error_code outcome = success;
    if (count >= max_stack)
        outcome = overflow;
    else
        entry[count++] = item;
    return outcome;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::pop() {
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        count--;
    return outcome;
}

template<typename Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item) const {
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else
        item = entry[count - 1];
    return outcome;
}

