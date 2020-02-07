#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> s1,s2; //declare two stacks
public:
    void push(int x)
    {
        s1.push(x); // insert the number in the first stack
        if(s2.empty() || x <= getMin()) s2.push(x);  //s2 is empty, so add x
    }
    void pop()
    {
        if(s1.top() == getMin()) s2.pop(); // if the last numbers are equal, remove it from the second stack
        s1.pop(); // remove the last entered number
    }
    int top()
    {
        return s1.top(); //return the last number
    }
    int getMin()
    {
        return s2.top(); //return the lowest number
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
