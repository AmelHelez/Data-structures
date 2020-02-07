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
    void reversee();
    void deletee(int);
    void update(int,int);
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

void List::reversee()
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

void List::deletee(int n)
{
    Node *traverse, *tail;
    int cnt = 1;
    traverse = head;
    if(n <= 0) cout << "Error..";
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
    if(cnt < n) cout << "Error.";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::update(int old,int neww)
{
    int pos = 0;
    if(head == NULL) {
        cout << "Problem.."; return;
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
    cout << endl;
}


int main()
{
    List myList;
    int sajz, nr;
    cout << "Enter length: "; cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> nr;
        myList.add(nr);
    }
    cout << "The list is: ";
    myList.display();
    cout << "Updated list is: ";
    myList.update(2,3);
    myList.display();
    cout << "Reversed list is: ";
    myList.reversee();
    myList.display();
}
