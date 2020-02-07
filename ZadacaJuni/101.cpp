#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};
/*
struct Node *newNode(int data)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
*/
bool isSymmetric(Node *root) {
        Node *left, *right;
        if (!root)
            return true;

        queue<Node*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->data != right->data)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(!isSymmetric(root)) cout << "Tree is not symmetric..";
    else cout << "Tree is symmetric!";
}

