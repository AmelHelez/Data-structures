#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head,*tail;         //these two will be used in mostly all functions
    List()
    {
        head = NULL; tail = NULL;
    }
    void add(int);
    void deleteValue(int);
    void display();
};

void List::add(int n)
{
    Node *temp = new Node;    //initialize new Node
    temp->data = n;           //add the number to temp
    temp->next = NULL;        //next will be null
    if(head == NULL) {
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

void List::deleteValue(int value)
{
    Node *prev,*ptr;
    if(head == NULL) return;
    if(head->data == value)   //if one of the values equals our value
    {
        ptr = head;           //insert current number to ptr
        head = head->next;    //move head to the next one
        delete ptr;           //delete our number
    }
    else {
        ptr = head;
        while(ptr != NULL && ptr->data != value)
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
    int length, nr;
    cout << "Enter the length: ";
    cin >> length;
    for(int i = 0; i < length; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> nr;
        myList.add(nr);
    }
    cout << "The list: "; myList.display();
    cout << "Now, we delete number 4: ";
    myList.deleteValue(4);
    cout << "\nThe updated list is: ";
    myList.display();
}
