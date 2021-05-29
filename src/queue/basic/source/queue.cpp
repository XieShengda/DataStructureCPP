//
// Created by Sender on 5/27/21.
//

typedef int Queue_entry;

#include "../../../util/util.h"
#include "../header/queue.h"

/**
 * 当count不为0时, front rear当前指向位置都有元素
 * 所以要新增元素时, rear要先指向下一个位置再放置元素
 */
Queue::Queue() {
    count = 0;
    front = 0;
    rear = max_queue - 1;
}

Error_code Queue::append(const Queue_entry &item) {
    if (count >= max_queue) return overflow;
    count++;
    next(rear);
    entry[rear] = item;
    return success;
}

Error_code Queue::serve() {
    if (count <= 0) return underflow;
    count--;
    next(front);
    return success;
}

Error_code Queue::retrieve(Queue_entry &item) const {
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

bool Queue::empty() const {
    return count == 0;
}

void Queue::next(int &i) {
//    i = (i + 1) % max_queue; // option 1
    i = i + 1 == max_queue ? 0 : i + 1;// option 2
}