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
    void deletee(int);
    void reverse();
    void display();
    void makeEmpty();
    void update(int,int);

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

void List::deletee(int n)
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
    while((traverse != NULL) && (cnt < n))
    {
        tail = traverse;
        traverse = traverse->link;
        cnt++;
    }
    if(cnt < n) {
        cout << "ERROR!";
    }
    else {
        tail->link = traverse->link;
        delete traverse;
    }
}

void List::reverse()
{
    Node *current = head;
    Node *next = NULL,*previous = NULL;
    while(current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void List::update(int old, int neww)
{
    int pos = 0;
    if(head == NULL) {
        cout << "List not initialized.";
        return;
    }
    Node *current = head;
    while(current->link != NULL)
    {
        if(current->data == old) {
            current->data = neww;
            return;
        }
        current = current->link;
        pos++;
    }
    cout << old << " does not exist in the list.";
}
void List::makeEmpty()
{
    Node *p;
    while(head)
    {
        p = head;
        head = head->link;
        delete p;
    }

}
void List::display()
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
    int size; cout << "Enter length: "; cin >> size;
    int n;
    for(int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    cout << "The list is: ";
    myList.display();
    cout << "\nReversed list is: ";
    //myList.deletee(5);
    myList.display();
    myList.update(2,3);
    cout << endl;
    myList.display();
}
