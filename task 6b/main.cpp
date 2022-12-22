#include <iostream>
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "queue_methods.h"
#include "stack_methods.h"

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::cout << s1 << std::endl;         

    return 0;
}