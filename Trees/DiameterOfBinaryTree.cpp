#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> dfs(TreeNode* root, int& res){
		if(root == NULL) return {0, 0};
		vector<int> l = dfs(root->left, res);
		vector<int> r = dfs(root->right, res);
		int path = max(l[0], l[1]) + 1 + max(r[0], r[1]);
		res = max(res, path);
		return max(l[0], l[1]) + 1, 1 + max(r[0], r[1]);
	}
int diameterOfBinaryTree(TreeNode* root) {
		if(root == NULL) return 0;
		int res = 0;
		dfs(root, res);
		return res - 1;
	}



int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << diameterOfBinaryTree(root);
}
