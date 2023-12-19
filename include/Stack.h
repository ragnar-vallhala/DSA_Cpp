
#pragma once
#ifndef STACK_H
#define STACK_H
#include <initializer_list>

template<typename T>
class Stack{

public:
    Stack(int capacity);

    void Push(T object);
    
    T Pop();

    T Top() const;


private:

    T *_data;
    int _top;
    int _capacity;
};

#include "Stack.cpp"
#endif