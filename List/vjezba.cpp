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
    Node *head, *tail;
    List()
    {
        head = NULL; tail = NULL;
    }
    void add(int);
    void deletee(int);
    void update(int,int);
    void rotate();
    void display();
    void makeEmpty();
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

void List::deletee(int n)
{
    Node *traverse, *tail;
    traverse = head;
    int cnt = 1;
    if(n <= 0) cout << "ERROR!";
    if(n == 1) {
        head = head->next;
        delete traverse;
    }
    while((traverse != NULL) && (cnt < n))
    {
        tail = traverse;
        traverse = traverse->next;
        cnt++;
    }
    if(cnt < n) cout << "Wrong input..";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::rotate()
{
    Node *current = head;
    Node *next = NULL, *prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void List::update(int old,int neww)
{
    int pos = 0;
    if(head == NULL) {
        cout << "Wrong..";
        return;
    }
    Node *current = head;
    while(current->next != NULL)
    {
        if(current->data == old) {
            current->data = neww;
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

void List::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    List myList;
    int
}
