#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "list.h"

template <class T>
class stack : public list<T>
{
public:

    // конструктор пустого списка
    stack() : top(nullptr) {};

    // конструктор копирования
    stack(const stack& a);

    // конструктор перемещения
    stack(stack&& a) : top(a.top) { a.top = nullptr; };

    ~stack() { while (top != nullptr) (*this).pop(); }

    void free() { while (top) (*this).pop(); }

    void push(T e) override;

    T pop() override;

    const T& getFront() const override
    {
        if (!top) throw STACK_UNDERFLOW;
        return top->data;
    }

    int isEmpty() const override { return top == nullptr; }

    size_t size() const override;

    list<T>& operator = (const list<T>& a) override;

    stack<T>& operator = (const stack& a);

    stack<T>& operator = (stack&& a);

protected:
    void print(std::ostream& stream) const override;

private:
    node<T>* top;
};

#endif // STACK_H_INCLUDED
