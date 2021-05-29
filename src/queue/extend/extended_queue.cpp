//
// Created by Sender on 5/27/21.
//

typedef int Queue_entry;

#include "extended_queue.h"

bool Extended_queue::full() const {
    return count == max_queue;
}

void Extended_queue::clear() {
    count = 0;
    front = 0;
    rear = max_queue - 1;
}

int Extended_queue::size() const {
    return count;
}

/**
 * retrieve(item); => serve_and_retrieve(item) => serve_and_retrieve(item)
 */
Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (serve() == underflow) return underflow;
    return retrieve(item);
}