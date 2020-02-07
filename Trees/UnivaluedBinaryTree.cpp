#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node* newNode(int val)
{
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return(node);
};

 bool isUnivalTree(node* root) {
        return (!root->left || root->left->val == root->val && isUnivalTree(root->left)) &&
               (!root->right || root->right->val == root->val && isUnivalTree(root->right));
    }

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(1);
    root->right = newNode(1);
    root->left->left = newNode(1);
    root->left->right = newNode(1);
    root->right->left = newNode(5);
    root->right->right = newNode(1);
    if(!isUnivalTree(root)) cout << "Not univalued..";
    else cout << "Univalued!";
}
