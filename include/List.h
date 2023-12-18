#pragma once
#ifndef LIST_H
#define LIST_H

#include<initializer_list>
#include<algorithm>
template<typename T>
class List{

public:
    

    List();
    
    List(int count);

    List(std::initializer_list<T> values);

    T operator[](int index) const;

    void Add(T object);

    void Insert(T object);

    void InsertAt(int index, T object);

    int Remove(T object);

    T RemoveAt(int index);

    int Find(T object) const;

    int GetCount() const;

    int GetCapacity() const;

    void Sort(bool order = true);
    

private:

    void Shift(int index, bool right = true);

    void Resize(bool increase = true, bool verbose = false);
    
   
    

    T *_data;
    int _capacity;
    int _count;
    int _initialSize = 10;

};

#include "List.cpp"

#endif