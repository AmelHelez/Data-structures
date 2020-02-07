#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};


void inorder(struct Node *node)
{
    if(node != NULL) {
        inorder(node->left);
        cout << node->key << endl;
        inorder(node->right);
    }
}

struct Node *insert(struct Node *root,int key)
{
    if(root == NULL) return new Node(key);
    if(key < root->key) root->left = insert(root->left,key);
    else if(key > root->key) root->right = insert(root->right,key);
    return root;
}

struct Node *minValue(struct Node *root)
{
    struct Node *cur = root;
    while(cur->left != NULL) cur = cur->left;
    return cur;
};

struct Node *deleteNode(struct Node *root,int key)
{
    if(root == NULL) return root;
    if(key < root->key) root->left = deleteNode(root->left,key);
    else if(key > root->key) root->right = deleteNode(root->right,key);
    else {
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
        struct Node *temp = root->left;
        free(root);
        return temp;
        }
        struct Node *temp = minValue(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
    }
    return root;
};

int main()
{
    struct Node *root = NULL;
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);
    inorder(root);
    cout << "\nDelete 20: ";
    root = deleteNode(root,20);
    inorder(root);

}
