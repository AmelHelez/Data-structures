#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
#include <utility>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

bool isCousins(Node* root, int x, int y, bool siblings = false, bool cousin = false) {
  queue<Node*> q, q1;
  q.push(root);
  while (!q.empty() && !cousin) {
    while (!q.empty()) {
      Node* n = q.front();
      q.pop();
      if (n == NULL) siblings = false;
      else {
        if (n->data == x || n->data == y) {
          if (!cousin) cousin = siblings = true;
          else return !siblings;
        }
        q1.push(n->left), q1.push(n->right), q1.push(NULL);
      }
    }
    swap(q, q1);
  }
  return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    if(!isCousins(root,5,4)) cout << "Not cousins..";
    else cout << "Cousins!";
}
