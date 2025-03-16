#include "Stack.h"

Stack CreateStack(int size)
{
    Stack s(size);
    return s;
}

int main(int argc, char* argv[])
{
    Stack stack1(5);
    Stack stack2(10);
    Stack s2(5);
    s2 = (stack1 + stack2);
    return 0;
}
