#include <iostream>
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
        head = NULL; tail = NULL;
    }
    int get(int);
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
    else {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

int List::get(int index)
{
    Node *temp = head->next;
    for(int i = 0; i < index; i++) temp = temp->next;
    return temp->data;
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
    else {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::insertPosition(int pos,int value)
{
    Node *pre = new Node, *cur = new Node, *temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++) {
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
    Node *current = new Node, *prev = new Node;
    current = head;
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    tail = prev;
    prev->next = NULL;
    delete current;
}

void List::deletePosition(int pos)
{
    Node *current = new Node;
    Node *prev = new Node;
    current = head;
    for(int i = 1; i < pos; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
}

void List::deleteValue(int value)
{
    Node *prev = new Node;
    Node *current = head;
    while(current != NULL)
    {
        if(current->data == value) break;
        else {
            cout << "Value " << current->data << " does not match " << value << endl;
            prev = current;
            current = current->next;
        }
    }
    if(current == NULL)
    {
        cout << "No match found.\n";
    }
    else {
        prev->next = current->next;
        delete current;
    }
}

int main()
{
    List myList;
    int sajz, nr;
    cout << "Enter length: "; cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> nr;
        myList.insertEnd(nr);
    }
    cout << "The list is: ";
    myList.display();
    myList.deleteValue(4);
    myList.display();
    cout << myList.get(-1);
}
