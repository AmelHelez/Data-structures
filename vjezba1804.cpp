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
    List() {head = NULL; tail = NULL;}
    void add(int);
    void deletee(int);
    void update(int,int);
    void deleteValue(int);
    void transverse();
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

void List::deletee(int n)
{
    Node *tail,*traverse;
    int cnt = 1;
    traverse = head;
    if(n <= 0) cout << "The number is invalid.";
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
    if(cnt < n) cout << "Invalid number.";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::deleteValue(int x)
{
    Node *ptr,*prev;
    if(head == NULL) return;
    if(head->data == x)
    {
        ptr = head;
        head = head->next;
        delete ptr;
    }
    else {
        ptr = head;
        while(ptr != NULL && ptr->data != x)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr != NULL) {
            prev->next = ptr->next;
            delete ptr;
        }
    }
}

void List::update(int old,int neww)
{
    int pos = 0;
    if(head == NULL) return;
    Node *current = head;
    while(current->next != NULL) {
        if(current->data == old) {
            current->data = neww;
            return;
        }
        current = current->next;
    }
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

void List::transverse()
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
    cout << "Enter length: "; cin >> s;
    for(int i = 0; i < s; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    myList.display();
    cout << "Now,update 3 into 2.\n";
    myList.update(2,3); myList.display();
    cout << "Now,delete number 7.\n";
    myList.deleteValue(7); myList.display();
    cout << "Now, delete the last number.\n";
    myList.deletee(s-1); myList.display();
    cout << "Now, reverse the list.\n";
    myList.transverse(); myList.display();
    cout << "Now, make the list empty.\n";
    myList.makeEmpty(); myList.display();
}
