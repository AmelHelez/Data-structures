#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(NULL), next(NULL) {}
    Node(int x) : val(x), next(NULL) {}
};

bool hasCycle(Node *head)
{
    Node *p1 = head, *p2 = head;
    while(p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == p2) return true;
        else return false;
    }
}

int main()
{
     Node *n1;
     int br;
     for(int i = 0; i < 4; i++) {
        cout << "Enter a number: ";
        cin >> br;
        n1 = new Node(br);
     }
     if(!hasCycle(n1)) cout << "False."; else cout << "True.";
}
