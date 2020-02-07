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
    List() {head = NULL; tail = NULL;}
    void add(int);
    void rev();
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

void List::rev()
{
    Node *current = head;
    Node *prev = NULL,*next = NULL;
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
    cout << endl;
}

int main()
{
    List myList;
    int n,s;
    cout << "LEngth: "; cin >> s;
    for(int i = 0; i < s; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    myList.display(); myList.rev(); myList.display();
}
