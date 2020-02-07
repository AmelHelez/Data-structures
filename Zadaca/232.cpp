#include <iostream>
#include <stack>
using namespace std;

struct Queue
{
    stack<int> s1,s2;        //initialize two stacks
    void enqueue(int);       //similar to push in stacks
    int dequeue();           //similar to pop in stacks
    int peek();
    bool isEmpty();          //checks whether queue is empty or not
};

void Queue::enqueue(int x)
{
    while(!s1.empty()) {
        s2.push(s1.top());   //adds the number
        s1.pop();            //deletes the number
    }
    s1.push(x);
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue::dequeue()
{
    //if(s1.empty()) cout << "Queue is empty..";
    int x = s1.top();   //our first element
    s1.pop();           //delete it
    return x;           //output the first element
}

int Queue::peek()
{
    return s1.top();        //returns the first element
}

bool Queue::isEmpty()
{
    return (s1.size() == 0);
}
int main()
{
    Queue q;
    int sajz,nr;
    cout << "Enter the length of the queue: ";
    cin >> sajz;
    for(int i = 0; i < sajz; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> nr;
        q.enqueue(nr);
    }
    cout << "Peek: " << q.peek() << endl << "=========\n";  //returns 1
    /*for(int i = 0; i < sajz; i++) {
        cout << q.dequeue() << endl;
    }*/
    while(!q.isEmpty()) cout << q.dequeue() << endl;
}
