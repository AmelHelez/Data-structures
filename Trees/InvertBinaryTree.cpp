#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

struct Trunk
{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if(p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}



/*
TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}
*/
TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}

void printTree(TreeNode *root, Trunk *prev, bool isLeft)
{
    if (root == NULL)
        return;

    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->left, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->right, trunk, false);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    TreeNode *root2 = invertTree(root);
    printTree(root2,NULL,false);

}
