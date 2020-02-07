#include <iostream>
#include <list>
using namespace std;

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
//typedef struct QUEUE Queue;


void Queue::create()
{
    front = NULL; back = NULL;
}

void Queue::close()
{
    Node *p;
    while(front) {
        p = front;
        front = front->next;
        delete p;
    }
}

void Queue::enqueue(QueueDataType newdata)
{
    Node *newnode = new Node;
    newnode->data = newdata;
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
    cout << "\n";
    if(isEmpty()) {
        cout << "Queue empty.\n";
    }
    cout << "QUEUE: ";
    while(p != NULL) {
        cout << p->data;
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    Queue q;
    q.create();
    q.enqueue('A'); q.enqueue('B'); q.enqueue('C');
    q.print();
    char c = q.dequeue();
    q.enqueue('D'); q.enqueue('E'); q.enqueue('F');
    c = q.dequeue();
    if(!q.isEmpty()) q.dequeue();
    q.print();
    q.close();
}


