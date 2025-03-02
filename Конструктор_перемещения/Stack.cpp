#include "Stack.h"

#include <iostream>

Stack::Stack() : Stack(1)
{
}

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

Stack::Stack(Stack&& other) noexcept : size(0), data(nullptr), top(-1)
{
    this->data = other.data;
    this->size = other.size;
    this->top = other.top;

    other.data = nullptr;
    other.size = 0;
    other.top = -1;
}

Stack::~Stack()
{
    delete[] data;
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] this->data;
        size = other.size;
        top = other.top;
        data = new int[size];
        for (int i = 0; i <= top; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        delete[] this->data;

        this->data = other.data;
        this->size = other.size;
        this->top = other.top;

        other.data = nullptr;
        other.size = 0;
        other.top = -1;
    }
    return *this;
}

Stack Stack::operator+(const Stack& other) const
{
    Stack result(this->size + other.size);
    for (int i = 0; i <= this->top; ++i)
        result.Push(this->data[i]);
    for (int i = 0; i <= other.top; ++i)
        result.Push(other.data[i]);
    return result;
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
