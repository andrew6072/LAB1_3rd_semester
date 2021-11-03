#pragma once
#include <iostream>
#include "Sequence.hpp"
using namespace std;
// template<typename T>
// Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T, T));

template <typename T>
class ISorter
{
public:
    virtual Sequence<T> *Sort(Sequence<T> *seq, int (*cmp)(T, T)) = 0;
    // virtual Sequence<T> *Sort(Sequence<T> *seq, int (*cmp)(T, T))
    // {
    //     if ((ArraySequence<T>*) seq)
    //     {
    //         //...
    //     }
    //     ArraySequence<T>* as = static_cast<ArraySequence<T>*>(seq);
    //     if (as)
    //     {
            
    //     }
    //     else 
    //     {
    //         ListSequence<T>* ls = static_cast<ListSequence<T>*>(seq);
    //         if (ls)
    //         {

    //         }
    //         else
    //         {

    //         }
    //     }
    // }
    // virtual Sequence<T> *Sort(ArraySequence<T> *seq, int (*cmp)(T, T)) = 0;
    // virtual Sequence<T> *Sort(ListSequence<T> *seq, int (*cmp)(T, T)) = 0;
    virtual Sequence<T> *operator()(Sequence<T> *seq, int (*cmp)(T, T)) = 0;
};
// ISorter<int>* quickSort = new QuickSorter();
// Sequence<int>* seq;
// Sequence<int>* s2 = quickSort->Sort(seq, [](int a, int b) { return (a-b); });

template <typename T>
class ISwapSorter
{
protected:
    virtual void Swap(Sequence<T> *seq, size_t index, size_t index2) = 0;
    //it's not good
    //virtual void Swap(T& index, T& index2) = 0;
    //in the case of linked list, not good too because work only for linked list
    //virtual void Swap(ListNode<T>* node1, ListNode<T>* ndoe2) = 0;
};

template <class T>
class Swapper
{
public:
    static void SwapItems(Sequence<T> *seq, size_t index, size_t index2) { throw; }
};

template <class T>
class ArraySwapper
{
protected:
    virtual void Swap(Sequence<T> *seq, size_t index, size_t index2) = 0;
};

template <class T>
class ListSwapper
{
protected:
    virtual void Swap(ListNode<T> *node1, ListNode<T> *ndoe2) = 0;
};

template <typename T>
class QuickSorter : ISorter<T>
{
public:
    virtual Sequence<T> *Sort(Sequence<T> *seq, int (*cmp)(T, T)) override
    {
        //
        ISorter<int> *quickSort = new QuickSorter();
        Sequence<int> *seq;
        Sequence<int> *s2 = quickSort->Sort(seq, [](int a, int b)
                                            { return (a - b); });
        //Sequence<int>* s2 = quickSort(seq, [](int a, int b) { return (a-b); });
        throw;
    }

    virtual Sequence<T> *operator()(Sequence<T> *seq, int (*cmp)(T, T)) override
    {
        throw;
    }
};

//Alternative
//1.
class Sorting
{
public:
    template <typename T>
    static Sequence<T> *QuickSort(Sequence<T> *seq, int (*cmp)(T, T)) { throw; }
    template <typename T>
    static Sequence<T> *MergeSort(Sequence<T> *seq, int (*cmp)(T, T)) { throw; }
};

//2.
template <typename T>
static Sequence<T> *QuickSort(Sequence<T> *seq, int (*cmp)(T, T)) { throw; }
template <typename T>
static Sequence<T> *MergeSort(Sequence<T> *seq, int (*cmp)(T, T)) { throw; }

//type summa (google search sum type)
template <class T1, class T2>
class Either //Union, Variant, ...
{
public:
    Either(T1 item) { throw; }
    Either(T2 item) { throw; }

public:
    T1 First() { throw; };
    T2 Second() { throw; };
    bool IsFirst() { throw; };
    bool IsSecond() { throw; };
};