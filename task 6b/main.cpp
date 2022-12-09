#include <iostream>
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "queue_methods.h"
#include "stack_methods.h"

int main()
{
    stack<double> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.pop();
    std::cin >> a;
    stack<double> a2(a);
    std::cout << a2 << std::endl;
    std::cout << a2.size() << std::endl;


    queue<double> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    std::cin >> s;
    queue<double> l2;
    queue<double>& ss = s;
    l2 = ss;
    std::cout << l2 << std::endl;
    std::cout << l2.size() << std::endl;

    return 0;
}