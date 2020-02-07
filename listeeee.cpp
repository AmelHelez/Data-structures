#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head,*tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void add(int);
    void deletee(int);
    void update(int,int);
    void rotate();
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

void List::rotate()
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

void List::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void List::deletee(int n)
{
    Node *traverse,*tail;
    int cnt = 1;
    traverse = head;
    if(n < 0) cout << "Error input..";
    if(n == 1) {
        head = head->next;
        delete traverse;
    }
    while((traverse != NULL) && (cnt < n)) {
        tail = traverse;
        traverse = traverse->next;
        cnt++;
    }
    if(cnt < n) cout << "Error input..";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::update(int old, int neww)
{
    int pos = 0;
    if(head == NULL) break;
    Node *current = head;
    while(current->next != NULL)
    {
        if(current->data == old) {
            current->data == neww;
            return;
        }
        current = current->next;
        pos++;
    }
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
