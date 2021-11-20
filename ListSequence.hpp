#pragma once
#include "Sequence.hpp"
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <class T>
class ListSequence : public Sequence<T>
{
public:
    Node<T> *head;
    int size;

public:
    ListSequence()
    {
        head = nullptr;
        size = 0;
    }

    ListSequence(const ListSequence<T> &list) : head(list.head), size(list.size) {}

    ~ListSequence()
    {
        delete (head);
    }

    // void setHead(Node<T> *newHead)
    // {
    //     this->head = newHead;
    // }
    // Node<T>* getHead()
    // {
    //     return this->head;
    // }
    Node<T> *getHead()
    {
        return this->head;
    }

    void setHead(Node<T> *new_head)
    {
        this->head = new_head;
    }

    void setSize(int size) override
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
            cout << "Sequence is empty!\n";
            return 0;
        }
        return head->data;
    }

    T getLast() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!\n";
            return 0;
        }
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    bool isEmpty() override
    {
        if (size == 0)
        {
            return true;
        }
        else
            return false;
    }

    bool IndexIsValid(int index)
    {
        return (index <= size && index >= 0);
    }

    T get(int index) override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty, cannot get anything!" << endl;
            return 0;
        }
        else
        {
            if (IndexIsValid(index))
            {
                Node<T> *p = head;
                int i = 0;
                while (i < index)
                {
                    p = p->next;
                    i++;
                }
                return p->data;
            }
            else
            {
                cout << "Input index is invalid!" << endl;
                return 0;
            }
        }
    }

    void push_back(T item) override
    {
        Node<T> *new_node = new Node<T>(item);
        if (head == nullptr)
        {
            head = new_node;
            size++;
        }
        else
        {
            Node<T> *p = head;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = new_node;
            size++;
        }
    }

    void push_front(T item) override
    {
        Node<T> *new_node = new Node<T>(item);
        if (head == nullptr)
        {
            head = new_node;
            size++;
        }
        else
        {
            new_node->next = head;
            head = new_node;
            size++;
        }
    }

    void insertAt(T item, int index) override
    {
        if (isEmpty())
        {
            push_back(item);
        }
        else
        {
            if (IndexIsValid(index))
            {
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
                    Node<T> *new_node = new Node<T>(item);
                    int i = 0;
                    Node<T> *p = head;
                    while (i < index - 1)
                    {
                        p = p->next;
                        i++;
                    }
                    new_node->next = p->next;
                    p->next = new_node;
                    size++;
                }
            }
            else
            {
                cout << "Input index is invalid!" << endl;
                return;
            }
        }
    }

    void deleteAt(int index) override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return;
        }
        else
        {
            if (IndexIsValid(index))
            {
                if (index == 0)
                {
                    deleteFirst();
                }
                else
                {
                    int i = 0;
                    Node<T> *p = head;
                    while (i < index - 1)
                    {
                        p = p->next;
                        i++;
                    }
                    p->next = (p->next)->next;
                    size--;
                }
            }
            else
            {
                cout << "Input index is invalid!" << endl;
            }
        }
    }

    void deleteLast() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return;
        }
        else
        {
            Node<T> *p = head;
            while (p->next->next != nullptr)
            {
                p = p->next;
            }
            p->next = nullptr;
            size--;
        }
    }

    void deleteFirst()
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return;
        }
        else
        {
            head = head->next;
            size--;
        }
    }

    Sequence<T> *con_cate(Sequence<T> *sequence)
    {
        if (sequence->isEmpty())
        {
            return this;
        }
        if (isEmpty())
        {
            return sequence;
        }
        Node<T> *p = head;
        while (p != nullptr)
        {
            sequence->push_back(p->data);
            p = p->next;
        }
        return sequence;
    }

    Sequence<T> *subSequence(int start, int end)
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!" << endl;
            return nullptr;
        }
        else
        {
            if (IndexIsValid(start) && IndexIsValid(end) && start <= end)
            {
                Node<T> *p = head;
                Sequence<T> *sub_seq = new ListSequence<T>();
                int i = 0;
                while (p != nullptr)
                {
                    if (i >= start && i <= end)
                    {
                        sub_seq->push_back(p->data);
                    }
                    p = p->next;
                    i++;
                }
                return sub_seq;
            }
        }
        return nullptr;
    }

    bool search(T key) override
    {
        Node<T> *current = this->head;
        while (current)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void map(T (*function)(T data, T value), T value) override
    {
        // Add condition when your data is empty
        Node<T> *p = head;
        for (int i = 0; i < size; i++)
        {
            p->data = function(p->data, value);
            p = p->next;
        }
    }

    void where(bool (*function)(T data, T value), T value) override
    {
        Node<T> *cur = head;
        Node<T> *pre = nullptr;
        while (cur)
        {
            if (!(function(cur->data, value)))
            {
                if (cur == head)
                {
                    head = head->next;
                    cur = head;
                    pre = cur;
                    size--;
                }
                else
                {
                    pre->next = cur->next;
                    cur = pre->next;
                    size--;
                }
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
    }

    void print() override
    {
        if (isEmpty())
        {
            cout << "Sequence is empty!\n";
            return;
        }
        else
        {
            Node<T> *p = head;
            while (p != nullptr)
            {
                cout << "| " << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};