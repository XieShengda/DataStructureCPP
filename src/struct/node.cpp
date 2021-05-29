//
// Created by Sender on 5/29/21.
//
typedef int Node_entry;

#include "node.h"

Node::Node() {
    next = nullptr;
}

Node::Node(const Node_entry &item, Node *add_on) {
    entry = item;
    next = add_on;
}