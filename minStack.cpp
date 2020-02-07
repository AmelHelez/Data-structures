#include <iostream>
#include <stack>
using namespace std;

struct MinStack
{
    stack<int> s1;
    stack<int> s2;
    void push(int x)
    {
        s1.push(x);
        if(s2.empty() || x <= getMin()) s2.push(x);
    }
    void pop()
    {
        if(s1.top() == getMin()) s2.pop();
        s1.pop();
    }
    int top()
    {
        return s1.top();
    }
    int getMin()
    {
        return s2.top();
    }
};

int main()
{
    MinStack m;
    m.push(-2); m.push(0); m.push(-3);
    cout << m.getMin() << endl;
    m.pop();
    cout << m.top() << endl;
    cout << m.getMin() << endl;

}
