#include <iostream>
#define QueueSize 6
using namespace std;

class Queue
{
    int element[QueueSize];
    int front;
    int back;
    void create();
    void close();
    bool enqueue(int);
    int dequeue();
    bool isEmpty();
};

void Queue::create()
{
    front = 0; back = 0;
}

void Queue::close() {}

bool Queue::enqueue(int newData)
{
    if(back < QueueSize) {
        element[back++] = newData;
        return true;
    } return false;
}

int Queue::dequeue()
{
    return element[front++];
}

bool Queue::isEmpty()
{
    return front == back;
}
