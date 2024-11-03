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
    Stack(int size);
    Stack(const Stack& other);
    void Push(int value);
    int Pop();
    int Peek();
    bool IsEmpty() const;
    bool IsFull();
    int Size();

    void TestPrint();
};
