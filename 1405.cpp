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
    List() {head = NULL; tail = NULL;}
    void add(int);
    void rewerse();
    void display();
    int get(int n);
    void addAtHead(int);
    void addAtTail(int);
    void addAtIndex(int,int);
    void removeBegin();
    void removeEnd();
    void removePosition(int);
    void removeValue(int);
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


int List::get(int index)
{
    Node *temp = head->next;
    for(int i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

void List::addAtHead(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = tail;
}

void List::addAtIndex(int pos,int index)
{
    Node *cur = new Node,*pre = new Node,*temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        pre = cur; cur = cur->next;
    }
    temp->data = index;
    pre->next = temp;
    temp->next = cur;
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
    cur = head;
    while(cur->next != NULL)
    {
        pre = cur; cur = cur->next;
    }
    tail = pre;
    pre->next = NULL;
    delete cur;
}

void List::removePosition(int pos)
{
    Node *cur = new Node,*pre = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        pre = cur; cur = cur->next;
    }
    pre->next = cur->next;
}

void List::removeValue(int value)
{
    Node *cur = new Node,*pre = new Node;
    cur = head;
    while(cur != NULL) {
        if(cur->data == value) break;
        else {
            pre = cur; cur = cur->next;
        }
    }
    if(cur == NULL) cout << "No match found..\n";
    else {
        pre->next = cur->next;
        delete cur;
    }
}

void List::makeEmpty()
{
    Node *p;
    while(head) {
        p = head; head = head->next; delete p;
    }
}
void List::rewerse()
{
    Node *current = head,*pre = NULL,*next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    } head = pre;
}

void List::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}

int main()
{
    List myList;
    int n,s;
    cout << "Enter length: ";
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    myList.rewerse(); myList.display();
}
