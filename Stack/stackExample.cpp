#include <iostream>
//#include <stack>
#define StackSize 5
using namespace std;

typedef char StackDataType;

struct STACK
{
    StackDataType element[StackSize];
    int top;

    void create();
    void close();
    bool push(StackDataType);
    StackDataType pop();
    bool isEmpty();
};

typedef struct STACK Stack;

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
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    if(!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    s.close();
    return 0;
}



