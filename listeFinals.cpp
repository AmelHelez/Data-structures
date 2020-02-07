#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct List
{
    Node *head,*tail;
    //List() : head(NULL),tail(NULL) {}
    void create();
    void close();
    void addBegin(int);
    void addEnd(int);
    void addAtIndex(int,int);
    void removeBegin();
    void removeEnd();
    void removeAtIndex(int);
    void removeValue(int);
    void update(int,int);
    void rewerse();
    void makeEmpty();
    int get(int);
    void display();
};

void List::create()
{
    head = NULL;
    tail = NULL;
}

void List::close()
{
    makeEmpty();
}

void List::addBegin(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void List::addEnd(int n)
{   //ne radi nesto
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    } else {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::addAtIndex(int pos,int value)
{
    Node *cur = new Node,*pre = new Node,*temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
    temp->next = cur;
}

void List::makeEmpty()
{
    Node *p;
    while(head) {
        p = head;
        head = head->next;
        delete p;
    }
}

void List::removeBegin()
{
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}

void List::removeEnd()
{
    Node *cur = new Node,*pre = new Node;
    while(cur->next != NULL) {
        pre = cur;
        cur = cur->next;
    }
    tail = pre;
    pre->next = NULL;
    delete cur;
}

void List::removeAtIndex(int pos)
{
    Node *cur = new Node,*pre = new Node;
    cur = head;
    for(int i = 1; i < pos; i++) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
}

void List::removeValue(int value)
{
    Node *cur = new Node, *pre = new Node;
    cur = head;
    while(cur != NULL) {
        if(cur->data == value) break;
        else {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }
    if(cur == NULL) cout << "No match.";
    else {
        pre->next = cur->next;
        delete cur;
    }
}

void List::update(int old,int nju)
{
    int pos = 0;
    Node *cur = new Node;
    cur = head;
    while(cur->next != NULL) {
        if(cur->data == old) {
            cur->data = nju;
            return;
        }
        cur = cur->next;
        pos++;
    }
}

void List::rewerse()
{
    Node *cur = head,*pre = NULL,*next = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    } head = pre;
}

void List::display()
{
    Node *cur = head;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int List::get(int index)
{
    Node *temp = head;
    for(int i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

int main()
{
    List l1;
    l1.create();
    l1.addBegin(2);
    l1.addBegin(4);
    l1.addAtIndex(2,7);
    //l1.addEnd(3);
    l1.display();
    cout << l1.get(0); //4
    l1.close();
}
