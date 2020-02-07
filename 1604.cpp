#include <iostream>
#include <stack>
#include <queue>
#define QUEUESIZE 10
#define STACKSIZE 5
using namespace std;

//stack
/*
typedef char StackDataType;

struct Stack
{
   StackDataType element[STACKSIZE];
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
    if(top < STACKSIZE) {
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
    return top == 0;
}

int main()
{
    Stack s;
    s.create();
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    while(!s.isEmpty()) cout << s.pop() << endl;
    s.close();
}


//queue

typedef int QueueDataType;

struct Queue
{
    QueueDataType element[QUEUESIZE];
    int front;
    int back;
    void create();
    void close();
    bool enqueue(QueueDataType);
    QueueDataType dequeue();
    bool isEmpty();
};

void Queue::create()
{
    front = 0; back = 0;
}

void Queue::close() {}

bool Queue::enqueue(QueueDataType newData)
{
    if(back < QUEUESIZE) {
        element[back++] = newData;
        return true;
    }
    return false;
}

QueueDataType Queue::dequeue()
{
    return element[front++];
}

bool Queue::isEmpty()
{
    return front == back;
}

int main()
{
    Queue q;
    q.create();
    int size = 10, n;
    for(int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        q.enqueue(n);
    }
    while(!q.isEmpty()) cout << q.dequeue() << endl;
    q.close();
}


//queue using stack

struct Queue
{
    stack<int> s1,s2;
    void enqueue(int);
    int dequeue();
    bool isEmpty();
};

void Queue::enqueue(int x)
{
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue::dequeue()
{
    if(s1.empty()) return -1;
    int x = s1.top();
    s1.pop();
    return x;
}

bool Queue::isEmpty()
{
    return s1.size() == 0;
}

int main()
{
    Queue q;
    int n,sajz = 7;
    for(int i = 0; i < sajz; i++) {
        cin >> n;
        q.enqueue(n);
    }
    while(!q.isEmpty()) cout << q.dequeue() << endl;

}



//stack using queue

struct Stack
{
    queue<int> q1,q2;
    void push(int);
    void pop();
    int top();
    bool isEmpty();
};

void Stack::push(int x)
{
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
}

int Stack::top()
{
    if(q1.empty()) return -1;
    return q1.front();
}

bool Stack::isEmpty()
{
    return q1.size() == 0;
}

int main()
{
    Stack s;
    int n;
    for(int i = 0; i < 7; i++)
    {
        cin >> n;
        s.push(n);
    }
    while(!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }
}
*/

//queue using list

typedef char QueueDataType;

struct Node
{
    QueueDataType data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *back;
    void create();
    void close();
    void enqueue(QueueDataType);
    QueueDataType dequeue();
    bool isEmpty();
    void print();
};

void Queue::create()
{
    front = NULL; back = NULL;
}

void Queue::close()
{
    Node *p;
    while(front)
    {
        p = front;
        front = front->next;
        delete p;
    }
}

void Queue::enqueue(QueueDataType newData)
{
    Node *newnode = new Node;
    newnode->data = newData;
    newnode->next = NULL;
    if(isEmpty()) {
        back = newnode;
        front = back;
    }
    else {
        back->next = newnode;
        back = newnode;
    }
}

QueueDataType Queue::dequeue()
{
  Node *topnode;
  QueueDataType temp;
  topnode = front;
  front = front->next;
  temp = topnode->data;
  delete topnode;
  return temp;
}

bool Queue::isEmpty()
{
    return front == NULL;
}

void Queue::print()
{
    Node *p = front;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
