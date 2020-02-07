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
    List()
    {
        head = NULL; tail = NULL;
    }
    void add(int);
    void deletee(int);
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
    Node *prev,*ptr;
    if(head == NULL) return;
    if(head->data == n)
    {
        ptr = head;
        head = head->next;
        delete ptr;
    }
    else {
        ptr = head;
        while(ptr != NULL && ptr->data != n)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr != NULL)
        {
            prev->next = ptr->next;
            delete ptr;
        }
    }
}

void List::display()
{
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    List myList;
    int sajz,nr;
    cout << "Size: "; cin >> sajz;
    for(int i = 0; i < sajz; i++) {
        cout << "Number " << i+1 << ": ";
        cin >> nr;
        myList.add(nr);
    }
    myList.display();
    cout << "Delete nr 5: ";
    myList.deletee(5);
    myList.display();
}
