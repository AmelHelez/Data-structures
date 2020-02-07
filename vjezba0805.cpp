#include <iostream>
#include <list>
using namespace std;

//reverseLinkedList

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head,*tail;
    List() {head = NULL;tail = NULL;}
    void addNode(int);
    void display();
    void update(int,int);
    void reversee();
    void makeEmpty();
    void addStart(int);
    void addEnd(int);
    void addPosition(int);
    void removeBegin();
    void removeEnd();
    void removePosition(int);
    void removeValue(int);
};

void List::addNode(int n)
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


void List::addStart(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void List::addPosition(int pos,int value)
{
    Node *pre = new Node, *cur = new Node, *temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
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
    Node *pre = new Node,*cur = new Node;
    cur = head;
    while(cur->next != NULL)
    {
        pre = cur;
        cur = cur->next;
    }
    tail = pre;
    pre->next = NULL;
    delete cur;
}

void List::deletePosition(int pos)
{
    Node *pre = new Node, *cur = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
}

void List::deleteValue(int value)
{
    Node *pre = new Node, *cur = new Node;
    cur = head;
    while(cur != NULL)
    {
        if(cur->data == value) break;
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    if(cur == NULL) cout << "No match found.\n";
    else {
        pre->next = cur->next;
        delete cur;
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

void List::reversee()
{
    Node *cur = head,*prev = NULL,*next = NULL;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
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
    cout << endl;
}
int main()
{
    List myList;
    int n,s; cout << "Enter length: "; cin >> s;
    for(int i = 0; i < s; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.addNode(n);
    }

}
