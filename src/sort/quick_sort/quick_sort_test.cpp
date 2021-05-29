//
// Created by Sender on 5/26/21.
//
#include <iostream>
#include "quick_sort.cpp"

int main() {
    std::vector<std::string> vi = {"d", "e", "z", "a", "f", "w"};
    quick_sort(vi, 0, static_cast<int>(vi.size()) - 1);
    for (const std::string &it : vi) {
        std::cout << it;
    }
}