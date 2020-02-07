#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node

{

int data;

struct node* left;

struct node* right;

};


struct node* newNode(int data)
{

struct node* node = (struct node*)

malloc(sizeof(struct node));

node->data = data;

node->left = NULL;

node->right = NULL;

return(node);
}
 int res=0;

int DFS(node* n) {
        if(n==NULL) return 0;
        int l=DFS(n->left);
        int r=DFS(n->right);
        res+=abs(l-r);
        return l+r+n->data;
    }
    int findTilt(node* root) {
        DFS(root);
        return res;
    }




int main()

{

struct node *root = newNode(1);

root->left = newNode(2);

root->right = newNode(3);
/*
root->left->left = newNode(4);

root->left->right = newNode(5);
*/
cout << findTilt(root);

getchar();

return 0;

}
