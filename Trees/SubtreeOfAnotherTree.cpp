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

bool isSame(TreeNode *s, TreeNode *t) {
        if (!s && !t)
            return true;

        if (!s && t || s && !t)
            return false;

        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s)
            return !t;
        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    TreeNode *rut = new TreeNode(4);
    rut->left = new TreeNode(1);
    rut->right = new TreeNode(2);
    if(isSubtree(root,rut)) cout << "True!";
    else cout << "False..";
    return 0;
}
