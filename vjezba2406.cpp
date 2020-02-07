#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node() : next(NULL), prev(NULL) {}
};

struct List
{
    struct Node *head,*tail;
    List() : head(NULL), tail(NULL) {}
    void addBegin(int);
    void addEnd(int);
    void removeBegin();
    void removeEnd();
    void reversee();
    void display();
};

void List::addBegin(int n)
{
    struct Node *temp = new Node;
    temp->data = n;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = head;
    } else {
    temp->next = head;
    head = temp;
    }
}

void List::addEnd(int n)
{
    struct Node *temp = new Node;
    temp->data = n;
    temp->prev = tail;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = head;
    } else {
     tail->next = temp;
     tail = tail->next;
    }
}

void List::removeBegin()
{
    if(head == NULL) return;
    struct Node *cur = head->next;
    delete head;
    head = cur;
}

void List::removeEnd()
{
    struct Node *temp = tail->prev;
    temp->next = NULL;
    delete tail;
    tail = temp;
}

void List::reversee()
{
    struct Node *cur = head, *pre = NULL, *next;
    while(cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    } head = pre;

}
void List::display()
{
    struct Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    List l1;
    l1.addBegin(1);
    l1.addBegin(2);
    l1.addEnd(3);
    l1.display();
    l1.reversee();
    l1.display();
    l1.removeBegin();
    l1.display();
}


struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int n) : key(n), left(NULL), right(NULL) {}
};

void inOrder(struct Node *root)
{
    if(root != NULL) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
    cout << endl;
}

struct Node *insert(struct Node *root,int key)
{
    if(root == NULL) return new Node(key);
    if(key < root->key) root->left = insert(root->left,key);
    else if(key > root->key) root->right = insert(root->right,key);
    return root;
};

struct Node *minValue(struct Node *root)
{
    if(root == NULL) return 0;
    struct Node *cur = root;
    while(cur->left != NULL) cur = cur->left;
    return cur;
};

struct Node *deletee(struct Node *root, int key)
{
    if(root == NULL) return root;
    if(key < root->key) root->left = deletee(root->left,key);
    else if(key > root->key) root->right = deletee(root->right,key);
    else {
        if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
        struct Node *temp = root->left;
        free(root);
        return temp;
        }

        struct Node *temp = minValue(root->right);
        root->key = temp->key;
        root->right = deletee(root->right,temp->data);
    }
    return root;
};

int sizeTree(struct Node *root)
{
    if(root == NULL) return 0;
    else return {size(root->left) + 1 + size(root->right); }
}

int areEqual(struct Node *root1,struct Node *root2)
{
    if(root1 == NULL && root2 == NULL) return 1;
    if(root1 != NULL && root2 != NULL) {
        return {root1->data == root2->data && areEqual(root1->left,root2->left) && areEqual(root1->right,root2->right); }
    }
}

int maxDepth(struct Node *root)
{
    if(root == NULL) return 0;
    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if(lDepth < rDepth) return(rDepth+1);
        else if(lDepth > rDepth) return(lDepth+1);
    }
};
*/

struct Graph
{
    int v;
    list<int> *adj;
    Graph(int v) {
     this->v = v;
     adj = new list<int> [v];
    }
    void addEdge(int v,int w);
    void BFS(int s);
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSSve(int v, bool visited [])
{
    visited[v] = true;
    cout << v << " ";
    list<int>:: iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) DFSSve(*i, visited);
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool [v];
    for(int i = 0; i < v; i++) visited[i] = false;
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) DFSSve(i,visited);
    }
}
