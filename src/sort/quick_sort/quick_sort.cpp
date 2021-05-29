//
// Created by Sender on 5/26/21.
//

#include "quick_sort.h"
#include <vector>

template<typename T>
int partition(std::vector<T> &vi, int low, int up) { // c++容器的常量引用，容器内的元素也无法被修改
    //todo i作为counter记录比pivot下的值的index
    int i = low;
    T pivot = vi[up];
    //todo j作为循环变量
    for (int j = low; j < up; ++j) {
        if (vi[j] < pivot) { // <, <= 结果相同
            swap(vi[i++], vi[j]);
        }
    }
    swap(vi[i], vi[up]);
    return i;
}

template<class T>
void quick_sort(std::vector<T> &vi, int low, int up) {
    if (low < up) {// todo
        int mid = partition(vi, low, up);
        //当low与up相差1时，执行partition后mid的值为up
        quick_sort(vi, low, mid - 1);
        quick_sort(vi, mid + 1, up);
    }
}
