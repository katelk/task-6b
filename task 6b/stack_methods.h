#ifndef STACK_METHODS_H_INCLUDED
#define STACK_METHODS_H_INCLUDED

#include "stack.h"

template <class T>
stack<T>::stack(const stack<T>& a) : top(nullptr)
{
    node<T>* t = a.top;
    node<T>** n = &top;

    while (t != nullptr)
    {
        *n = new node<T>;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }
}

template <class T>
void stack<T>::push(T e)
{
    node<T>* t = new node<T>;

    t->data = e;
    t->next = top;
    top = t;
}

template <class T>
T stack<T>::pop()
{
    if (!top) throw STACK_UNDERFLOW;

    node<T>* t = top;
    T e = t->data;

    top = t->next;
    delete t;

    return e;
}

template <class T>
size_t stack<T>::size() const
{
    size_t n = 0;
    node<T>* t = top;

    while (t != nullptr)
    {
        n++;
        t = t->next;
    }
    return n;
}

template <class T>
list<T>& stack<T>::operator = (const list<T>& a)
{
    if (this == &a) return *this;
    (*this).free();
    const stack& a2 = dynamic_cast<const stack&>(a);

    node<T>* t = a2.top;
    node<T>** n = &top;

    while (t != nullptr)
    {
        *n = new node<T>;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }

    return *this;
}

template <class T>
void stack<T>::print(std::ostream& stream) const
{
    node<T>* t = top;
    while (t != nullptr)
    {
        stream << t->data << " ";
        t = t->next;
    }
}

template <class T>
stack<T>& stack<T>::operator = (const stack& a)
{
    if (this == &a) return *this;

    (*this).free();

    node<T>* t = a.top;
    node<T>** n = &top;

    while (t != nullptr)
    {
        *n = new node<T>;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }
    return *this;
}

template <class T>
stack<T>& stack<T>::operator = (stack&& a)
{
    this->free();
    delete top;
    top = a.top;
    a.top = nullptr;
    return *this;
}



#endif // STACK_METHODS_H_INCLUDED
