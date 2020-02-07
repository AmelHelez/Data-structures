#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root) {
			if(root == NULL)return 0;
			return max(height(root->left), height(root->right)) + 1;
		}
		bool isBalanced(TreeNode* root) {
			if(root == NULL)return true;
			return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
		}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    if(isBalanced(root)) cout << "BALANCED!";
    else cout << "Not balanced..";
}
