#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data) {
    this->data = data; left = NULL; right = NULL;
    }
};

int sameTrees(struct Node *tree1,struct Node *tree2)
{
    if(tree1 == NULL && tree2 == NULL) return 1;
    if(tree1 != NULL && tree2 != NULL) {
        return(tree1->data == tree2->data && sameTrees(tree1->left,tree2->left)
               && sameTrees(tree1->right,tree2->right));
    }
    return 0;
}

int main()
{
    struct Node *n1,*n2;
    n1 = new Node(7);
    n1->left = new Node(5);
    n1->right = new Node(9);
    n1->left->left = new Node(4);
    n1->left->right = new Node(6);
    n1->right->left = new Node(8);
    n1->right->right = new Node(10);

    n2 = new Node(7);
    n2->left = new Node(5);
    n2->right = new Node(11);
    n2->left->left = new Node(4);
    n2->left->right = new Node(6);
    n2->right->left = new Node(8);
    n2->right->right = new Node(10);
    if(sameTrees(n1,n2)) cout << "EQUAL!";
    else cout << "Not equal..";
}

