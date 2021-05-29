//
// Created by Sender on 5/27/21.
//

#ifndef DATASTRUCTURECPP_QUEUE_H
#define DATASTRUCTURECPP_QUEUE_H


#include "../../../util/util.h"

const int max_queue = 10;

/**
 * 实现:
 * 1.物理模型 缺点:多次移动
 * 2.线性实现 用两个指针(数组下标)指向头尾 缺点:报废的空间
 * 3.循环数组(ring buffer)
 *  - front和rear的指针值增长到与数组大小相同时置为0
 *  - 确定front和rear下标的方法:
 *    1. i = ((i+1) == max) ? 0 : (i+1);
 *    2. i = (i+1) % max;
 *  - 边界条件: 队列满时和队列为空时指针的状态相同(front,rear下标相同)
 *  - 解决方案:
 *    1.空位
 *      原理: 队列满时是rear移动,与front距离由2变1;队列空时时front移动,与rear距离由0变1
 *      所以只要rear移动时与front距离为2时判断为已满,则可以区分满与空
 *    2.标志
 *      flag成员变量指示当前状态, 或counter指示当前元素数量
 *    3.特殊值
 *      比如, 满的时候将rear下标设置为-1
 */
//template<typename Queue_entry>
class Queue {
public:
    Queue();

    Error_code append(const Queue_entry &item);

    Error_code serve();

    Error_code retrieve(Queue_entry &item) const;

    bool empty() const;

protected:
    int count;
    int front, rear;
    Queue_entry entry[max_queue];

    void next(int &);
};


#endif //DATASTRUCTURECPP_QUEUE_H
