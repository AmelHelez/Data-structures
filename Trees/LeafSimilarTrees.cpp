#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};

void inOrder(TreeNode* root, vector<int> & leafValues) {
        if(!root->left && !root->right) {
            leafValues.push_back(root->val);
        }

        if(root->left) {
            inOrder(root->left, leafValues);
        }

        if(root->right) {
            inOrder(root->right, leafValues);
        }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1;
        vector<int> leafValues2;

        inOrder(root1, leafValues1);
        inOrder(root2, leafValues2);

        return leafValues1 == leafValues2;
}

int main()
{
    TreeNode *tn1 = new TreeNode(3);
    tn1->left = new TreeNode(5);
    tn1->right = new TreeNode(1);
    tn1->left->left = new TreeNode(6);
    tn1->left->right = new TreeNode(2);
    tn1->left->right->left = new TreeNode(7);
    tn1->left->right->right = new TreeNode(4);
    tn1->right->left = new TreeNode(9);
    tn1->right->right = new TreeNode(8);

    TreeNode *tn2 = new TreeNode(4);
    tn2->left = new TreeNode(6);
    tn2->right = new TreeNode(2);
    tn2->left->left = new TreeNode(6);
    tn2->left->right = new TreeNode(3);
    tn2->left->right->left = new TreeNode(7);
    tn2->left->right->right = new TreeNode(4);
    tn2->right->left = new TreeNode(9);
    tn2->right->right = new TreeNode(8);
    if(!leafSimilar(tn1,tn2)) cout << "False.";
    else cout << "True!";
}

