//
// Created by Sender on 5/29/21.
//

#ifndef DATASTRUCTURECPP_LINK_QUEUE_H
#define DATASTRUCTURECPP_LINK_QUEUE_H

#include "../../util/util.h"
#include "../../struct/node.h"

class Queue {
public:
    Queue();

    Error_code append(const Queue_entry &item);

    Error_code serve();

    Error_code retrieve(Queue_entry &item) const;

    bool empty() const;

// Safety feature for linked structure
    ~Queue();

    Queue(const Queue &original);

    void operator=(const Queue &original);

protected:
    Node *front, *rear;

};


#endif //DATASTRUCTURECPP_LINK_QUEUE_H
