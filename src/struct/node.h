//
// Created by Sender on 5/29/21.
//

#ifndef DATASTRUCTURECPP_NODE_H
#define DATASTRUCTURECPP_NODE_H

struct Node {
    Node_entry entry;
    Node *next;

    Node();

    Node(const Node_entry &entry, Node *add_on = nullptr);
};

#endif //DATASTRUCTURECPP_NODE_H
