//
// Created by Sender on 5/29/21.
//

#include "../../struct/node.cpp"

typedef Node_entry Queue_entry;

#include "link_queue.h"

Queue::Queue() {
    front = rear = nullptr;
}

Error_code Queue::append(const Queue_entry &item) {
    Node *new_node = new Node(item);
    if (new_node == nullptr) return overflow;
    if (front == nullptr) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    return success;
}

Error_code Queue::serve() {
    if (front == nullptr) return underflow;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        Node *old_front = front;
        front = front->next;
        delete old_front;
    }
    return success;
}

Error_code Queue::retrieve(Queue_entry &item) const {
    if (front == nullptr) {
        return underflow;
    }
    item = front->entry;
    return success;
}

bool Queue::empty() const {
    return front == nullptr;
}

//todo
Queue::~Queue() {}

Queue::Queue(const Queue &original) {}

void Queue::operator=(const Queue &original) {}