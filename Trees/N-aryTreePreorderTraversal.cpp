#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node* root) {
    if(root==NULL) return {};
    stack<Node*> stk;
    vector<int> res;
    stk.push(root);
    while(!stk.empty()) {
        Node* temp=stk.top();
        stk.pop();
        for(int i=temp->children.size()-1;i>=0;i--) stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    return res;
}

int main()
{
    vector<int> v;
    Node *root = new Node()
}

