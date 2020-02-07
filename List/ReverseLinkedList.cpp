#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void reverse()
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
    void print()
    {
        struct Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList l1;
    int size; cout << "Size: "; cin >> size;
    for(int i = 0; i < size; i++) {
        int br; cin >> br;
        l1.push(br);
    }
    cout << "Given list: \n";
    l1.print();

    l1.reverse();
    cout << "\nReversed linked list: \n";
    l1.print();
    return 0;
}
