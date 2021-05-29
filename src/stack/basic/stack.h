//
// Created by 谢胜达 on 5/25/21.
//

#ifndef DATASTRUCTURECPP_LINK_STACK_H
#define DATASTRUCTURECPP_STACK_H

#include "../../util/util.h"

const int max_stack = 10;

template<typename Stack_entry>
class Stack {
public:
    Stack();

    Error_code push(const Stack_entry &item);

    Error_code pop();

    Error_code top(Stack_entry &item) const;

    bool empty() const;

private:
    int count;
    Stack_entry entry[max_stack];
};


#endif //DATASTRUCTURECPP_LINK_STACK_H
