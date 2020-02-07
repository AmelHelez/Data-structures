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
    void rotatee();
    void deletee(int);
    void removeNumber(int);
    void display();
};

void List::add(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = temp;
        temp = NULL;
    } else {
    tail->next = temp;
    tail = temp;
    temp = NULL;
    }
}

void List::rotatee()
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
    int cnt = 1;
    Node *tail,*traverse;
    traverse = head;
    if(n < 1) cout << "Wrong number..";
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
    if(cnt < n) cout << "Error!";
    else {
        tail->next = traverse->next;
        delete traverse;
    }
}

void List::removeNumber(int x)
{
    Node *current = head, *prev = new Node;
    while(current != NULL)
    {
        if(current->data == x) break;
        else {
            //cout << "Value " << current->data << " does not match..\n";
            prev = current;
            current = current->next;
        }
    }
    if(current == NULL) cout << "No match found.\n";
    else {
        prev->next = current->next;
        delete current;
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
    int n,s;
    cout << "Enter list length: "; cin >> s;
    for(int i = 0; i < s; i++) {
        cout << "Enter " << i+1 << " number: ";
        cin >> n;
        myList.add(n);
    }
    myList.display();
   // myList.rotatee();
    //cout << "Rotated list: "; myList.display();
    myList.removeNumber(3); myList.display();
}
