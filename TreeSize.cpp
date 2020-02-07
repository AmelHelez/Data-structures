#include <stdio.h>
#include <stdlib.h>
#include <array>
using namespace std;


struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
/*
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
};
*/

int sizee(struct Node *node)
{
    if(node==NULL) return 0;
    else return(sizeof(node->left) + 1 + sizeof(node->right));
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "The size is: " << sizee(root);
    return 0;
}
