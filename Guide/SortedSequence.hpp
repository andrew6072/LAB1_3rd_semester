#pragma once

template <typename T>
class SortedSequence
{
protected:
    int length;

public:
    int GetLength() const;
    bool IsEmpty() const;

public:
    virtual T Get(int index) const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual SortedSequence<T> *GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual int IndexOf(T item) const = 0;

public:
    virtual void Set(int index, T item) = 0;
    virtual void Add(T item) = 0;
    virtual bool Remove(T item) = 0;
};

template <typename T>
int SortedSequence<T>::GetLength() const
{
    return this->length;
}

template <typename T>
bool SortedSequence<T>::IsEmpty() const
{
    return this->length == 0;
}