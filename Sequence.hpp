#pragma once
#include <iostream>
using namespace std;

template <class T>
class Sequence
{
public:
    virtual void setSize( int size) = 0;
    virtual  int getSize() const = 0;
    virtual T getFirst() = 0;
    virtual T getLast() = 0;
    virtual bool isEmpty() = 0;
    virtual T get( int index) = 0;
    virtual void push_back(T item) = 0;
    virtual void push_front(T item) = 0;
    virtual void insertAt(T item,  int index) = 0;
    virtual void deleteAt( int index) = 0;
    virtual void deleteLast() = 0;
    virtual void deleteFirst() = 0;
    virtual Sequence<T> *con_cate(Sequence<T> *sequence) = 0;
    virtual Sequence<T> *subSequence( int start,  int end) = 0;
    virtual bool search(T item) = 0;
    virtual void map(T (*function)(T data, T option), T option) = 0;
    virtual void where(bool (*function)(T data, T option), T option) = 0;
    virtual void print() = 0;

public:
    virtual void swap(const  int i1, const  int i2)
    {
        T tmp = this->get(i1);
        this->set(this->get(i2), i1);
        this->set(tmp, i2);
    }
    virtual void set(T item,  int index)
    {
        deleteAt(index);
        insertAt(item, index);
    }
    virtual void generator( int n)
    {
        for ( int i = 0; i < n; i++)
        {
            T a;
            a = (rand() % 1000000001) + 1;
            push_back(a);
        }
    }
};