#ifndef QUEUE_METHODS_H_INCLUDED
#define QUEUE_METHODS_H_INCLUDED

#include "queue.h"

template <class T>
queue<T>::queue(const queue<T>& a) : head(nullptr), tail(nullptr)
{
    node<T>* t = a.head;

    while (t != nullptr)
    {
        node<T>* n = new node<T>;

        n->data = t->data;
        n->next = nullptr;
        if (head == nullptr) head = n;
        else tail->next = n;
        tail = n;
        t = t->next;
    }
}

template <class T>
void queue<T>::push(T e)
{
    node<T>* n = new node<T>;

    n->data = e;
    n->next = nullptr;
    if (head == nullptr) head = n;
    else tail->next = n;
    tail = n;
}

template <class T>
T queue<T>::pop()
{
    node<T>* t = head;
    if (t == nullptr) throw STACK_UNDERFLOW;
    T e = t->data;

    head = t->next;
    delete t;

    if (head == nullptr) tail = nullptr;

    return e;
}
template <class T>
size_t queue<T>::size() const
{
    size_t n = 0;
    node<T>* t = head;

    while (t != nullptr)
    {
        n++;
        t = t->next;
    }

    return n;
}

template <class T>
list<T>& queue<T>::operator = (const list<T>& a)
{
    if (this == &a) return *this;
    const queue& a2 = dynamic_cast<const queue&>(a);

    node<T>* t = a2.head;

    while (t != nullptr)
    {
        node<T>* n = new node<T>;
        n->data = t->data;
        n->next = nullptr;
        if (head == nullptr) head = n;
        else tail->next = n;
        tail = n;
        t = t->next;
    }

    return *this;
}

template <class T>
void queue<T>::print(std::ostream& stream) const
{
    node<T>* t = head;
    while (t != nullptr)
    {
        stream << t->data << " ";
        t = t->next;
    }
}

template <class T>
queue<T>& queue<T>::operator = (const queue<T>& a)
{
    if (this == &a) return *this;

    (*this).free();

    node<T>* t = a.head;
    while (t != nullptr)
    {
        (*this).push(t->data);
        t = t->next;
    }
    return *this;
}

template <class T>
queue<T>& queue<T>::operator = (queue<T>&& a)
{
    this->free();
    delete head;
    delete tail;
    head = a.head;
    tail = a.tail;
    a.top = nullptr;
    a.tail = nullptr;
    return *this;
}

#endif // QUEUE_METHODS_H_INCLUDED
