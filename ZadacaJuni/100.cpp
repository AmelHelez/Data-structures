#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};


bool isSameTree(Node *p, Node *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}


int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    //root1->right = new Node(3);
    Node *root2 = new Node(1);
    root2->left = NULL;
    root2->right = new Node(2);
    if(isSameTree(root1,root2)) cout << "The trees are equal!";
    else cout << "The trees are not equal..";
}

