#pragma once

class Stack
{
private:
    // Размер стека
    int size;
    // Содержимое стека
    int* data;
    // Указатель на верхний элемент стека
    int top;
public:
    Stack();
    Stack(int size);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    ~Stack();
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other) noexcept;
    Stack operator+(const Stack& other) const;

    void Push(int value);
    int Pop();
    int Peek();
    bool IsEmpty() const;
    bool IsFull();
    int Size();

    void TestPrint();
};
