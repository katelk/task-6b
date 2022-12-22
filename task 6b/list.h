#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstddef>

enum ERR_CODE { STACK_UNDERFLOW };

template<class T>
struct node
{
    T data;
    struct node<T>* next;
};

template <class T>
class list
{
public:
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual const T& getFront() const = 0;
    virtual int isEmpty() const = 0;
    virtual size_t size() const = 0;
    virtual list& operator = (const list& a) = 0;
    virtual void free() = 0;
    friend std::ostream& operator <<(std::ostream& os, const list& a)
    {
        a.print(os);
        return os;
    }
    friend std::istream& operator >> (std::istream& in, list& a)
    {
        T e;
        in >> e;
        a.push(e);
        return in;
    }

protected:
    virtual void print(std::ostream& stream) const = 0;
};

#endif // LIST_H_INCLUDED

