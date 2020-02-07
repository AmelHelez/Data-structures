#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

struct Graph
{
    int v;
    list <int> *adj;
    Graph(int v)
    {
        this->v = v;
        adj = new list<int> [v];
    }
    void addEdge(int v, int w);
    void DFS(int s);
    void DFSUntil(int v, bool visited[]);
    void BFS(int s);
};


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUntil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";
    list<int>:: iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
       if(!visited[*i]) DFSUntil(*i,visited);
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool [v];
    for(int i = 0; i < v; i++) visited[i] = false;

    for(int i = 0; i < v; i++)
        if(visited[i] == false) DFSUntil(i,visited);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>:: iterator i;
    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); i++)
        if(!visited[*i]) {
            visited[*i] = true;
            queue.push_back(*i);
        }
    }
}


int main() {

    Graph g(10);
    g.addEdge(1, 3);
    g.addEdge(1,2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    cout << "BFS: \n";
    g.BFS(1);
    cout << "\nDFS: \n";
    g.DFS(1);
}
