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
    Node *head,*tail;
    List()
    {
        head = NULL; tail = NULL;
    }
    void add(int);
    void rotate();
    void remove(int);
    void print();

};

void List::add(int n)
{
    Node *temp = new Node;
    temp->data = n;
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

void List::rotate()
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;
    while(current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void List::remove(int n)
{
    Node *traverse, *tail;
    int cnt = 1;
    traverse = head;
    if(n <= 0) {
        cout << "ERROR!"; return;
    }
    if(n == 1) {
        head = head->link;
        delete traverse;
    }
    while((traverse != NULL) && (cnt < n)) {
        tail = traverse;
        traverse = traverse->link;
        cnt++;
    }
    if(cnt < n) {
        cout << "Could not find record..";
    }
    else {
        tail->link = traverse->link;
        delete traverse;
    }

}
void List::print()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
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
    cout << "The list is: ";
    myList.print();
    myList.rotate();
    cout << "\nThe new ordered list is: ";
    myList.print();
    myList.remove(5); cout << "\nDeleted: ";
    myList.print();
}
