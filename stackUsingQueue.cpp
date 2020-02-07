#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
    queue<int> q1,q2;
    int cur_size;
    Stack() { cur_size = 0;}
    void push(int);
    void pop();
    int top();
    int size();
};

void Stack::push(int x)
{
    cur_size++;
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void Stack::pop()
{
    if(q1.empty()) return;
    q1.pop();
    cur_size--;
}

int Stack::top()
{
    if(q1.empty()) return -1;
    return q1.front();
}

int Stack::size()
{
    return cur_size;
}

int main()
{
    Stack s;
    s.push(1); s.push(2); s.push(3);
    cout << "Current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "Current size: " << s.size() << endl;
    return 0;
}

