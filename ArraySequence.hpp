#pragma once
#include "Sequence.hpp"
#include <iostream>
using namespace std;

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    T *data;
     int size;
     int capacity = 8;

public:
    ArraySequence<T>()
    {
        data = new T[capacity];
        size = 0;
    }

    ArraySequence<T>(const ArraySequence<T> &src) : size(src.size), capacity(src.capacity)
    {
        this->data = new T[size];
        copy(src.data, src.data + size, data);
    }

    ArraySequence<T>(ArraySequence &&src) : data(src.data), size(src.size), capacity(src.capacity)
    {
        src.data = nullptr;
        src.size = src.capacity = 0;
    }

    ~ArraySequence<T>()
    {
        delete[] data;
    }

    void setSize( int size) override
    {
        this->size = size;
    }

     int getSize() const override
    {
        return size;
    }

    T getFirst() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return 0;
        }
        else
        {
            return data[0];
        }
    }

    T getLast() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return 0;
        }
        else
        {
            return data[size - 1];
        }
    }

    bool isEmpty() override
    {
        return size == 0;
    }

    bool IndexIsValid( int index)
    {
        return (index <= size && index >= 0);
    }

    T get( int index) override
    {
        if (IndexIsValid(index))
        {
            if (isEmpty())
            {
                cout << "Sequence is empty, cannot get any value!" << endl;
                return 0;
            }
            else
            {
                return data[index];
            }
        }
        else
        {
            cout << "Input index is invalid!" << endl;
            return 0;
        }
    }

    void push_back(T item) override
    {
        if (size == capacity)
        {
             int new_cap = capacity * 2;
            T *new_arr = new T[new_cap];
            for ( int i = 0; i < size; i++)
            {
                new_arr[i] = data[i];
            }
            delete[] data;
            data = new_arr;
            capacity = new_cap;
        }
        data[size] = item;
        size++;
    }

    void push_front(T item) override
    {
        if (size == capacity)
        {
            capacity *= 2;
        }
        T *new_arr = new T[capacity];
        for ( int i = 0; i < size; i++)
        {
            new_arr[i + 1] = data[i];
        }
        delete[] data;
        data = new_arr;
        data[0] = item;
        size++;
    }

    void insertAt(T item,  int index) override
    {
        if (isEmpty())
        {
            push_back(item);
        }
        else
        {
            if (IndexIsValid(index))
            {
                if (size == capacity)
                {
                    capacity *= 2;
                }
                if (index == 0)
                {
                    push_front(item);
                }
                else if (index == size)
                {
                    push_back(item);
                }
                else
                {
                    T *new_arr = new T[capacity];
                    copy(data, data + index, new_arr);
                    for ( int i = index; i < size; i++)
                    {
                        new_arr[i + 1] = data[i];
                    }
                    delete[] data;
                    data = new_arr;
                    data[index] = item;
                    size++;
                }
            }
            else
            {
                cout << "Input index undefined!" << endl;
            }
        }
    }

    void deleteAt( int index) override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!";
        }
        else
        {
            if (index == 0)
            {
                deleteFirst();
            }
            else
            {
                T *new_arr = new T[capacity];
                copy(data, data + index, new_arr);
                for ( int i = index; i < size; i++)
                {
                    new_arr[i] = data[i+1];
                }
                delete[] data;
                data = new_arr;
                size--;
            }
        }
    }

    void deleteLast() override
    {
        if (isEmpty())
        {
            cout << "Cannot delete any more!" << endl;
        }
        else
        {
            T *new_arr = new T[capacity];
            copy(data, data + size - 1, new_arr);
            delete[] data;
            data = new_arr;
            size--;
        }
    }

    void deleteFirst() override
    {
        if (isEmpty())
            cout << "Cannot delete any more!" << endl;
        else
        {
            T *new_arr = new T[capacity];
            copy(data + 1, data + size, new_arr);
            delete[] data;
            data = new_arr;
            size--;
        }
    }

    Sequence<T> *con_cate(Sequence<T> *sequence) override
    {
        for ( int i = 0; i < size; i++)
        {
            sequence->push_back(data[i]);
        }
        return sequence;
    }

    Sequence<T> *subSequence( int start,  int end) override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty" << endl;
            return this;
        }
        else
        {
            if (IndexIsValid(start) && IndexIsValid(end) && start <= end)
            {
                Sequence<T> *sub_sequence = new ArraySequence<T>();
                for ( int i = start; i <= end; i++)
                {
                    sub_sequence->push_back(data[i]);
                }
                return sub_sequence;
            }
            else
            {
                cout << "Input indexes are in valid!" << endl;
                return nullptr;
            }
        }
    }

    bool search(T item) override
    {
        if (isEmpty())
            return false;
        else
        {
            for ( int i = 0; i < size; i++)
            {
                if (item == data[i])
                {
                    return true;
                }
            }
            return false;
        }
    }

    void map(T (*function)(T data, T option), T option) override
    {
        for ( int i = 0; i < size; ++i)
        {
            data[i] = function(data[i], option);
        }
    }

    void where(bool (*function)(T data, T option), T option) override
    {
        T *new_array = new T[capacity];
         int j = 0;
        for ( int i = 0; i < size; i++)
        {
            if (function(data[i], option))
            {
                new_array[j] = data[i];
                j++;
            }
        }
        delete[] data;
        data = new_array;
        size = j;
    }

    void print() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
        }
        else
        {
            for ( int i = 0; i < size; i++)
            {
                cout << "| " << data[i] << " ";
            }
            cout << endl;
        }
    }
};