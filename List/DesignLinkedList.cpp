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
    List() {head = NULL;tail = NULL;}
    void createNode(int);
    void insertStart(int);
    void insertEnd(int);
    void insertPosition(int,int);
    void deleteStart();
    void deleteEnd();
    void deletePosition(int);
    void deleteValue(int);
    void display();
};

void List::createNode(int n)
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
    else
    {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::insertStart(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void List::insertEnd(int n)
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
    else
    {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::insertPosition(int pos,int value)
{
    Node *cur = new Node,*prev = new Node, *temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    temp->data = value;
    prev->next = temp;
    temp->next = cur;
}

void List::deleteStart()
{
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}

void List::deleteEnd()
{
    Node *cur = new Node,*prev = new Node;
    cur = head;
    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    tail = prev;
    prev->next = NULL;
    delete cur;
}

void List::deletePosition(int pos)
{
    Node *cur = new Node,*prev = new Node;
    cur = head;
    for(int i = 1; i < pos;i++) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
}

void List::deleteValue(int value)
{
    Node *prev = new Node, *cur = head;
    while(cur != NULL)
    {
        if(cur->data == value) break;
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    if(cur == NULL) cout << "No match found.\n";
    else
    {
        prev->next = cur->next;
        delete cur;
    }
}

