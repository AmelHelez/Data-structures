#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

struct Graph
{
    int v;
    list<int> *adj;
    Graph(int v) {
    this->v = v;
    adj = new list<int> [v];
    }
    void addEdge(int v,int w);
    void DFSUntil(int v, bool visited[]);
    void DFS(int s);
    void BFS(int s);
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool [v];
    for(int i = 0; i < v; i++) visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>:: iterator i;
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

void Graph::DFSUntil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>:: iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!visited[*i]) DFSUntil(*i,visited);
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool [v];
    for(int i = 0; i < v; i++) visited[i] = false;
    for(int i = 0; i < v; i++) {
        if(visited[*i] == false) DFSUntil(i,visited);
    }
}


struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
    Node() : prev(NULL),next(NULL) {}
};

struct List
{
    struct Node *head,*tail;
    List() : head(NULL), tail(NULL);
    void addBegin(int);
    void addEnd(int);
    void display();
    void reversee();
    void removeBegin();
    void removeEnd();
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
    }
    else {
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
    struct Node *temp = head->next;
    delete head;
    haed = temp;
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
    struct Node *cur = head,*next,*prev = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } head = prev;
}



