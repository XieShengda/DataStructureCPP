//
// Created by Sender on 5/29/21.
//

#ifndef DATASTRUCTURECPP_LINK_STACK_H
#define DATASTRUCTURECPP_LINK_STACK_H

#include "../../util/util.h"

typedef Stack_entry Node_entry;

struct Node {
    Node_entry entry;
    Node *next;

    Node();

    Node(Node_entry item, Node *add_on = nullptr);
};

class Stack {
public:
    Stack();
    bool empty() const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    Error_code top(Stack_entry &item) const;

// Safety features for linked structures
    ~Stack();
    Stack(const Stack &original);
    void operator=(const Stack &original);

protected:
    Node *top_node;
}; //todo end with ";"


#endif //DATASTRUCTURECPP_LINK_STACK_H
