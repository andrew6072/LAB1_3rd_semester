#pragma once
#include <iostream>
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
using namespace std;

// template <class T>
// class ISorter
// {
// public:
//     virtual void quickSort(Sequence<T> *seq, int low, int high, bool (*function)(T data, T value)) = 0;
//     // virtual void mergeSort(Sequence<T> *seq, bool (*function)(T data, T value)) = 0;
//     // virtual void shellSort(Sequence<T> *seq, bool (*function)(T data, T value)) = 0; // int(*cmp)(T, T)
// };

template <class T>
class ArraySorter
{
public:
    // QUICK
    T partition(Sequence<T> *arr, unsigned int low, unsigned int high, bool (*function)(T data, T value))
    {
        T pivot;
        pivot = arr->get(high);
        unsigned int i = low - 1;
        for (unsigned int j = i + 1; j <= high - 1; j++)
        {
            if (function(arr->get(j), pivot))
            {
                i++;
                arr->swap(i, j);
            }
        }
        arr->swap(i + 1, high);
        return (i + 1);
    }

    // const T& data,const T& value
    void _quickSort(Sequence<T> *arr, unsigned int low, unsigned int high, bool (*function)(T data, T value)) // iterator
    {
        if (low <= high)
        {
            T pivot;
            pivot = partition(arr, low, high, function);
            _quickSort(arr, low, pivot - 1, function);
            _quickSort(arr, pivot + 1, high, function);
        }
    }

    void quickSort(Sequence<T> *arr, bool (*function)(T data, T value))
    {
        _quickSort(arr, 0, arr->getSize() - 1, function);
    }

    // SHELL
    void shellSort(Sequence<T> *arr, bool (*function)(T data, T value))
    {
        unsigned int n = arr->getSize();
        for (unsigned int gap = n / 2; gap > 0; gap /= 2)
        {
            for (unsigned int i = gap; i < n; i++)
            {
                for (unsigned int j = gap; j >= gap && function(arr->get(j), arr->get(j - gap)); j -= gap)
                {
                    arr->swap(j, j - gap);
                }
            }
        }
    }

    // MERGE
    void merge(Sequence<T> *left, Sequence<T> *right, Sequence<T> *bars, bool (*function)(T data, T value))
    {
        unsigned int nL = left->getSize();
        unsigned int nR = right->getSize();
        unsigned int i = 0;
        unsigned int leftLoop = 0;
        unsigned int rightLoop = 0;

        while (leftLoop < nL && rightLoop < nR)
        {
            if (function(left->get(leftLoop), right->get(rightLoop)))
            {
                bars->set(left->get(leftLoop), i);
                ++leftLoop;
            }
            else
            {
                bars->set(right->get(rightLoop), i);
                ++rightLoop;
            }
            ++i;
        }
        while (leftLoop < nL)
        {
            bars->set(left->get(leftLoop), i);
            ++leftLoop;
            ++i;
        }
        while (rightLoop < nR)
        {
            bars->set(right->get(rightLoop), i);
            ++rightLoop;
            ++i;
        }
    }

    void mergeSort(Sequence<T> *bar, bool (*function)(T data, T value))
    {
        if (bar->getSize() <= 1)
        {
            return;
        }

        unsigned int mid = bar->getSize() / 2;
        Sequence<T>* left = new ArraySequence<T>();
        Sequence<T>* right = new ArraySequence<T>();

        for (size_t j = 0; j < mid; ++j)
        {
            left->push_back(bar->get(j));
        }

        for (size_t j = 0; j < (bar->getSize()) - mid; ++j)
        {
            right->push_back(bar->get(mid + j));
        }

        mergeSort(left, function);
        mergeSort(right, function);
        merge(left, right, bar, function);
    }
};

//LIST SEQUENCE
template <class T>
class ListSorter
{
public:
    Node<T> *getTail(Node<T> *cur)
    {
        while (cur != NULL && cur->next != NULL)
        {
            cur = cur->next;
        }
        return cur;
    }

    Node<T> *partition(Node<T> *head, Node<T> *end, Node<T> **newHead, Node<T> **newEnd, bool (*function)(T data, T value))
    {
        Node<T> *pivot = end;
        Node<T> *prev = NULL;
        Node<T> *cur = head;
        Node<T> *tail = pivot;
        while (cur != pivot)
        {
            if (function(cur->data, pivot->data))
            {
                if (*newHead == NULL)
                {
                    *newHead = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                Node<T> *temp;
                temp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = temp;
            }
        }
        if (*newHead == NULL) // error here (forgot * before newHead)
        {
            *newHead = pivot;
        }
        *newEnd = tail;
        return pivot;
    }

    Node<T> *quickSortFunc(Node<T> *head, Node<T> *end, bool (*function)(T data, T value))
    {
        if (head == NULL || head == end)
        {
            return head;
        }
        Node<T> *newHead = NULL;
        Node<T> *newEnd = NULL;
        Node<T> *pivot;
        pivot = partition(head, end, &newHead, &newEnd, function);
        if (pivot != newHead)
        {
            Node<T> *temp = newHead;
            while (temp->next != pivot)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            newHead = quickSortFunc(newHead, temp, function);
            temp = getTail(newHead);
            temp->next = pivot;
        }
        if (pivot->next != NULL && pivot->next != newEnd)
        {
            pivot->next = quickSortFunc(pivot->next, newEnd, function);
        }
        return newHead;
    }

    void quickSort(ListSequence<T> *list, bool (*function)(T data, T value))
    {
        list->head = quickSortFunc(list->head, getTail(list->head), function);
    }

    void shellSort(ListSequence<T> *list, bool (*function)(T data, T value))
    {
        
    }

};

template <class T>
bool descending(T data, T value)
{
    return data >= value;
}

template <class T>
bool ascending(T data, T value)
{
    return data <= value;
}