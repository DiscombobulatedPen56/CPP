#include "Stack.h"

#include <iostream>

Stack::Stack(int size)
{
    data = new int[size];
    this->size = size;
    top = -1;
}

Stack::Stack(const Stack& other)
{
    this->size = other.size;
    this->top = other.top;
    this->data = new int[size];
    for (int i = 0; i <= top; ++i)
        this->data[i] = other.data[i];
}

void Stack::Push(int value)
{
    if (!IsFull())
        data[++top] = value;
}

int Stack::Pop()
{
    if (!IsEmpty())
    {
        int x = data[top];
        top--;
        return x;
    }
}

int Stack::Peek()
{
    if (!IsEmpty())
        return data[top];
}

bool Stack::IsEmpty() const
{
    return top == -1;
}

bool Stack::IsFull()
{
    return top == size - 1;
}

int Stack::Size()
{
    return top + 1;
}

void Stack::TestPrint()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << data[i] << " " << std::endl;
    }
    std::cout << std::endl;
}
