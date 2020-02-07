#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 && t2 ) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
}

void display(TreeNode *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        cout<<ptr->val;
        display(ptr->left, level+1);
    }
}
int main()
{
    TreeNode *tn1 = new TreeNode(1);
    tn1->left = new TreeNode(3);
    tn1->right = new TreeNode(2);
    tn1->left->left = new TreeNode(5);
    TreeNode *tn2 = new TreeNode(2);
    tn2->left = new TreeNode(1);
    tn2->right = new TreeNode(3);
    tn2->left->right = new TreeNode(4);
    tn2->right->right = new TreeNode(7);
    TreeNode *mergee = mergeTrees(tn1,tn2);
    display(mergee,1);

}
