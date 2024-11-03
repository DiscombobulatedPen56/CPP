#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[])
{
    Stack stack(5);
    stack.Push(4);
    stack.Push(7);
    stack.TestPrint();
    Stack stack2(stack);
    stack2.TestPrint();
    stack2.Pop();
    stack.TestPrint();
    return 0;
}
