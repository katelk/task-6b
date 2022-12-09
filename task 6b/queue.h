#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "list.h"

template <class T>
class queue : public list<T>
{
public:

    // конструктор пустого списка
    queue() : head(nullptr), tail(nullptr) {};

    // конструктор копирования
    queue(const queue& a);

    // конструктор перемещения
    queue(queue&& a) : head(a.head), tail(a.tail)
    {
        a.head = nullptr;
        a.tail = nullptr;
    };

    ~queue() { while (head != nullptr) (*this).pop(); }

    void free() override { while (head) (*this).pop(); }

    void push(T e) override;

    T pop() override;

    const T& getFront() const override
    {
        if (!head) throw STACK_UNDERFLOW;
        return head->data;
    }

    int isEmpty() const override { return head == nullptr; };

    size_t size() const override;

    list<T>& operator = (const list<T>& a) override;

    queue<T>& operator = (const queue<T>& a);

    queue<T>& operator = (queue<T>&& a);

protected:
    void print(std::ostream& stream) const override;

private:
    node<T>* head;
    node<T>* tail;
};

#endif // QUEUE_H_INCLUDED
