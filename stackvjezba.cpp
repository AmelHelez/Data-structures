#include <iostream>
#define StackSize 5
using namespace std;

typedef char StackDataType;

struct Stack
{
    StackDataType element[StackSize];
    int top;
    void create();
    void close();
    bool push(StackDataType);
    StackDataType pop();
    bool isEmpty();
};

void Stack::create()
{
    top = 0;
}

void Stack::close() {}

bool Stack::push(StackDataType newData)
{
    if(top < StackSize) {
        element[top++] = newData;
        return true;
    }
    return false;
}

StackDataType Stack::pop()
{
    return element[--top];
}

bool Stack::isEmpty()
{
    return (top == 0);
}

int main()
{
    Stack s;
    s.create();
    s.push('A');
    s.push('B');
    s.push('C');
    while(!s.isEmpty())
    {
        cout << s.pop() << endl;
    }
    s.close();
    return 0;
}
