//
// Created by Sender on 5/29/21.
//

#include "../link/link_queue.cpp"
#include <iostream>

using namespace std;

int main() {
    Queue queue{};
    cout << "Empty? " << (queue.empty() ? "yes" : "no") << endl;
    cout << "Appending..." << endl;
    for (int i = 0; i < 10; ++i) {
        queue.append(i);
    }
    cout << "Empty? " << (queue.empty() ? "yes" : "no") << endl;

    Queue_entry entry;
    while (!queue.empty()) {
        queue.retrieve(entry);
        cout << "Retrieve " << entry << endl;
        queue.serve();
    }
}