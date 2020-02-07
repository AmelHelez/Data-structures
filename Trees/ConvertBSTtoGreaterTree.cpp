#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define COUNT 10
using namespace std;

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *newNode(int val)
{
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

    int cur_sum = 0;
    void travel(node* root){
        if (!root) return;
        if (root->right) travel(root->right);

        root->val = (cur_sum += root->val);
        if (root->left) travel(root->left);
    }
    node* convertBST(node* root) {
        travel(root);
        return root;
    }


void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->val<<"\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
int main()
{
    struct node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(13);
    struct node *konvert = convertBST(root);
    print2D(root);
}

