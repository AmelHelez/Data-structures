#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//obicna lista
/*
struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head,*tail;
    List() {head = NULL; tail = NULL;}
    void add(int);
    void remove(int);
    void update(int,int);
    void reverse();
    void deleteValue(int);
    void makeEmpty();
    void display();
};

void List::add(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::remove(int n)
{
    Node *tail,*traverse;
    int cnt = 1;
    traverse = head;
    if(n <= 0) cout << "The number is invalid.";
    if(n == 1)
    {
        head = head->next;
        delete traverse;
    }
    while((traverse != NULL) && (cnt < n))
    {
        tail = traverse;
        traverse = traverse->next;
        cnt++;
    }
    if(cnt < n) cout << "Error.";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::deleteValue(int x)
{
    Node *ptr,*prev;
    if(head == NULL) return;
    if(head->data == x) {
        ptr = head;
        head = head->next;
        delete ptr;
    }
    else {
        ptr = head;
        while(ptr != NULL && ptr->data != x) {
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr != NULL) {
            prev->next = ptr->next;
            delete ptr;
        }
    }
}

void List::update(int old,int neww)
{
    int pos = 0;
    if(head == NULL) return;
    Node *current = head;
    while(current->next != NULL)
    {
        if(current->data == old) {
            current->data = neww;
            return;
        }
        pos++;
        current = current->next;
    }
}

void List::reverse()
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void List::makeEmpty()
{
    Node *p;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void List::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    List myList;
    int n,size;
    cout << "Enter length: "; cin >> size;
    for(int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    myList.display();
    cout << "Now, replace the number 4 with 9.\n";
    myList.update(4,9);
    myList.display();
    cout << "Now, remove the number 9.\n";
    myList.deleteValue(9);
    myList.display();
    cout << "Now, remove the last number in the list.\n";
    myList.remove(size-1);
    myList.display();
    cout << "Now, reverse the list.\n";
    myList.reverse(); myList.display();
}


//stack using classes

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
    int n,size;
    cout << "Enter length: "; cin >> size;
    for(int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        s.push(n);
    }
    while(!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
*/

//queue using stacks

struct Queue
{
    stack<int> s1,s2;
    void enqueue(int);
    int peek();
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
    if(s1.size() == 0) return -1;
    int x = s1.top();
    s1.pop();
    return x;
}

int Queue::peek()
{
    return s1.top();
}

bool Queue::isEmpty()
{
    return s1.size() == 0;
}

int main()
{
    Queue q;
    int n,sajz;
    cout << "Enter length: "; cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        q.enqueue(n);
    }
    while(!q.isEmpty()) {
        cout << "Top: " << q.peek() << endl;
        cout << q.dequeue() << endl;
    }
    return 0;
}
