#include <iostream>
#include <queue>
using namespace std;

struct Stack
{
    queue<int> q1,q2; //initialize two queues
    //int curr_size;
    void push(int);   //insertion of numbers
    void pop();       //deletion of numbers
    int top();
    bool isEmpty();   //checks if the stack is empty
};

void Stack::push(int x)
{
    //curr_size++;
    q2.push(x);  //insert a number to q2
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
    if(q1.empty()) return;  //if q1 empty just return
    q1.pop();
    //curr_size--;
}

int Stack::top()
{
    if(q1.empty()) return -1;
    return q1.front();  //return the front number
}

bool Stack::isEmpty()
{
    return q1.size() == 0;  //if there are no numbers, return it
}

int main()
{
    Stack s;
    int sajz,n;
    cout << "Enter stack length: "; cin >> sajz;
    for(int i = 0; i < sajz; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        s.push(n);
    }
    while(!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }
}
