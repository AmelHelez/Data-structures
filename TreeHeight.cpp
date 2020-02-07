#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
    }
};

int maxDepth(Node *node)
{
    if(node == NULL) return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if(lDepth > rDepth) return(lDepth+1);
        else return(rDepth+1);
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of tree is " << maxDepth(root);
    return 0;
}
