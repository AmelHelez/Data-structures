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
    int get(int);
    void addNode(int);
    void rewerse();
    void addAtHead(int);
    void addAtTail(int);
    void addAtIndex(int,int);
    void removeBegin();
    void removeEnd();
    void removePosition(int);
    void removeValue(int);
    void makeEmpty();
    bool isPalindrome();
    void removeDuplicates();
    void display();
};

void List::addNode(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    } else {
    tail->next = temp;
    tail = temp;
    temp = NULL;
    }
}

void List::removeDuplicates()
{
    Node *p1,*p2,*dup;
    p1 = head;
    while(p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while(p2->next != NULL) {
            if(p1->data == p2->next->data) {
                dup = p2->next;
                p2->next = p2->next->next;
                delete dup;
            }
            else p2 = p2->next;
        }
        p1 = p1->next;
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
    }
    head = pre;
}

void List::addAtHead(int n)
{
    Node *temp = new Node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void List::addAtIndex(int pos,int value)
{
    Node *cur = new Node,*pre = new Node,*temp = new Node;
    cur = head;
    for(int i = 1; i < pos; i++)
    {
        pre = cur; cur = cur->next;
    }
    temp->data = value;
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
    Node *pre = new Node,*cur = new Node;
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
    Node *cur = head,*pre = new Node;
    for(int i = 1; i < pos; i++)
    {
        pre = cur; cur = cur->next;
    }
    pre->next = cur->next;
}

void List::removeValue(int value)
{
    Node *cur = head,*pre = new Node;
    while(cur != NULL)
    {
        if(cur->data == value) break;
        else {
            pre = cur; cur = cur->next;
        }
    }
    if(cur == NULL) cout << "No match.\n";
    else
    {
        pre->next = cur->next;
        delete cur;
    }
}

int List::get(int n)
{
    Node *temp = head->next;
    for(int i = 0; i < n; i++) temp = temp->next;
    return temp->data;
}
void List::makeEmpty()
{
    Node *p;
    while(head)
    {
        p = head; head = head->next; delete p;
    }
}

bool List::isPalindrome()
{
    Node *a = head,*b = head,*c = new Node;
    while(b && b->next) {
        b = b->next->next;
        Node *tmp = a->next;
        a->next = c;
        c = a;
        a = tmp;
    }
    if(b) a = a->next;
    while(a && c) {
        if(a->data != c->data) return false;
        a = a->next; c = c->next;
    }
    return true;
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
    cout << "Enter length: ";
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n; myList.addNode(n);
    }
    myList.display();//myList.rewerse();myList.display();
   // if(!myList.isPalindrome()) cout << "False"; else cout << "True";
   myList.removeDuplicates(); myList.display();
}
