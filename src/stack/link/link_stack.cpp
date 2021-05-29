//
// Created by Sender on 5/29/21.
//

typedef int Stack_entry;

#include "link_stack.h"

Node::Node() {
    next = nullptr;
}

Node::Node(Node_entry item, Node *add_on) {
    entry = item;
    next = add_on;
}

Stack::Stack() {
    top_node = nullptr;
}

bool Stack::empty() const {
    return top_node == nullptr;
}

/**
 * Node new_top(item, top_node)
 * 如果按上面这样创建的话 new_top再push执行完后会被回收
 */
Error_code Stack::push(const Stack_entry &item) {
    Node *new_top = new Node(item, top_node);
    if (new_top == nullptr) return overflow;//没有可用的连续内存，无法分配空间
    top_node = new_top;
    return success;
}

Error_code Stack::pop() {
    if (top_node == nullptr) return underflow;
    Node *old_top = top_node;
    top_node = old_top->next;
    delete old_top;
    return success;
}

Error_code Stack::top(Stack_entry &item) const {
    if (top_node == nullptr) return underflow;
    item = top_node->entry;
    return success;
}

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

/**
 * overload assign operator
 */
void Stack::operator=(const Stack &original) {
    Node *new_top, *original_node = original.top_node;
    if (original_node == nullptr) { new_top = nullptr; }
    else {
        //new_top一直指向头结点
        Node *new_copy = new_top = new Node(original_node->entry); //new_copy从头结点开始
        while (original_node->next != nullptr) {
            original_node = original_node->next; //源数据结点指针指向下一结点
            new_copy->next = new Node(original_node->entry); //创建new_copy下一结点并将源结点数据复制给此结点
            new_copy = new_copy->next; //new_copy结点指针指向下一结点
        }
        //Node构造函数中next默认为nullptr，所以最后一个结点指向nullptr
    }
    while (!empty()) {
        pop();
    }
    top_node = new_top;
}

/**
 * copy constructor
 */
Stack::Stack(const Stack &original) {
    Node *original_node = original.top_node;
    if (original_node == nullptr) { top_node = nullptr; }
    else {
        Node *copy_node = top_node = new Node(original_node->entry);
        while (original_node->next != nullptr) {
            original_node = original_node->next;
            copy_node->next = new Node(original_node->entry);
            copy_node = copy_node->next;
        }
    }
}

