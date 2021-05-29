//
// Created by Sender on 5/27/21.
//

#ifndef DATASTRUCTURECPP_EXTENDED_QUEUE_H
#define DATASTRUCTURECPP_EXTENDED_QUEUE_H

#include "../basic/header/queue.h"

//template<typename Queue_entry>
class Extended_queue : public Queue { //派生类关系：每个A是一个B，就吧A看做是B的派生类/子类
public:
    bool full() const;

    void clear();

    int size() const;

    Error_code serve_and_retrieve(Queue_entry &item);
};


#endif //DATASTRUCTURECPP_EXTENDED_QUEUE_H
