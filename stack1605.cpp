#include <iostream>
#include <stack>
#define StackSize 5
using namespace std;

//typedef char StackDataType;

struct Stack
{
    int element[StackSize];
    int top;
    void create();
    void close();
    bool push(int);
    int pop();
    bool isEmpty();
};

void Stack::create() {top = 0;}
void Stack::close() {}
bool Stack::push(int newData)
{
    if(top < StackSize) {
        element[top++] = newData;
        return true;
    } return false;
}

int Stack::pop() {
return element[--top];
}

bool Stack::isEmpty()
{
    return top == 0;
}

int main()
{
    Stack s;
    s.create();
    s.push(4); s.push(3); s.push(2); s.push(7); s.push(1);
    while(!s.isEmpty()) cout << s.pop() << endl;
}
