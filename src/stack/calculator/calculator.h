//
// Created by Sender on 5/26/21.
//

#ifndef DATASTRUCTURECPP_CALCULATOR_H
#define DATASTRUCTURECPP_CALCULATOR_H


#include "../basic/stack.h"

char get_command();

bool do_command(const char &command, Stack<double> &numbers);

void instructions();

void introduction();


#endif //DATASTRUCTURECPP_CALCULATOR_H
