#include <iostream>
using namespace std;


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};
/*
set<int> dict;
    int findSecondMinimumValue(TreeNode* root) {
        preorder(root);
        return dict.size()<=1?-1:*(++dict.begin());
    }

    void preorder(TreeNode* root){
        if (!root) return;
        dict.insert(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    */

    unsigned int minValue(TreeNode* r, int v) {
    return r->val != v ? r->val : r->left == NULL ? -1 : min(minValue(r->left, v), minValue(r->right, v));
}
int findSecondMinimumValue(TreeNode* root) {
    return minValue(root, root->val);
}


int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    cout << findSecondMinimumValue(root);
}
