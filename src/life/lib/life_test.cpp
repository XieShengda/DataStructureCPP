//
// Created by Sender on 5/27/21.
//

#include "life.cpp"
#include "../../util/util.cpp"

int main() {
    instructions();
    Life configuration{};
    configuration.initialize();
    configuration.print();
    string message = "Continue viewing new generations?\n";
    cout << message;
    while (user_says_yes()) {
        configuration.update();
        configuration.print();
        cout << message;
    }
}