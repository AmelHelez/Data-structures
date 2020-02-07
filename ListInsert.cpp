#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

struct List
{
    Node *head, *tail;
    List() {
    head = NULL; tail = NULL;
    }
    void add(int);
    void transverse();
};


void List::add(int newNode)
{
    Node *temp = new Node;
    temp->data = newNode;
    temp->link = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->link = temp;
        tail = temp;
        temp = NULL;
    }
}

void List::transverse()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
}

int main()
{
    List myList;
    int n;
    for(int i = 0; i < 7; i++) {
            cin >> n;
        myList.add(n);
    }
    myList.transverse();
}
