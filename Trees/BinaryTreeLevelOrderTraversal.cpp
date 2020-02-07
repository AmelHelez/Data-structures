#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};


vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if(!root)
            return ret;
        queue<TreeNode*> cur_que,next_que;
        vector<int> tem;
        cur_que.push(root);
        while(!cur_que.empty())
        {
            TreeNode* top = cur_que.front();
            tem.push_back(top->val);
            cur_que.pop();

            if(top->left) {next_que.push(top->left);}
            if(top->right) {next_que.push(top->right);}

            if(cur_que.empty())
            {
                ret.push_back(tem);
                tem.clear();
                cur_que = next_que;
                next_que = queue<TreeNode*>();
            }


        }
        reverse(ret.begin(),ret.end());
        return ret;
}

int main()
{
      vector<vector<int> > vec;
      TreeNode *root = new TreeNode(3);
      root->left = new TreeNode(9);
      root->right = new TreeNode(20);
      root->right->left = new TreeNode(15);
      root->right->right = new TreeNode(7);
      vec = levelOrderBottom(root);
      for(int i = 0; i < vec.size(); i++)
      {
          for(int j = 0; j < vec[i].size(); j++) cout << "[" << vec[i][j] << "," << "]\n";
      }

}
