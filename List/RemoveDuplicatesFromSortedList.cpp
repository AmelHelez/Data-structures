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
    List() {head = NULL;tail = NULL;}
    void add(int);
    void deleteDuplicates();
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

void List::deleteDuplicates()
{
   Node *p1,*p2,*dup;
   p1 = head;
   while(p1 != NULL && p1->next != NULL)
   {
       p2 = p1;
       while(p2->next != NULL)
       {
           if(p1->data == p2->next->data)
           {
               dup = p2->next;
               p2->next = p2->next->next;
               delete(dup);
           }
           else p2 = p2->next;
       }
       p1 = p1->next;
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
    int n,s;
    cout << "Enter length: ";
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> n;
        myList.add(n);
    }
    cout << "Input: "; myList.display();
    myList.deleteDuplicates();
    cout << "Output: "; myList.display();
}
