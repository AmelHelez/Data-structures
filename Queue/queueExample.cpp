#include <iostream>
#define QUEUESIZE 10
using namespace std;

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
    return (front == back);
}

int main()
{
    Queue qq;
    qq.create();
    int sajz, nr;
    cout << "Length: "; cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> nr;
        qq.enqueue(nr);
    }
    while(!qq.isEmpty()) {
        cout << qq.dequeue() << endl;
    }
    qq.close();
}


