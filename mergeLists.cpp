#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

Node *mergee(Node *n1,Node *n2)
{
    if(!n1) return n2;
    if(!n2) return n1;
    if(n1->data < n2->data)
    {
        n1->next = mergee(n1->next,n2);
        return n1;
    } else {
    n2->next = mergee(n2->next,n1);
    return n2;
    }
}

void display(Node *node)
{
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{

}
