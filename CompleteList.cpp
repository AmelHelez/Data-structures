#include <iostream>
#include <list>
#include <string>
#include <cstring>
using namespace std;

struct Node
{
    char name[30];
    char phonenum[15];
    Node *next;
};
struct List
{
    Node *head;
    int nodecount;
    void create();
    void close();
    void makeEmpty();
    void insert(Node *);
    void remove(int ordernum);
    int searc(char *);
    void update(int recordnum, Node *);
};

void List::create() {
 head = NULL;
 nodecount = 0;
}

typedef Node record;
typedef List Datastructure;

Datastructure book;

int List::searc(char * target)
{
    Node *traverse;
    int cnt = 0, found = 0;
    traverse = head;
    bool all = false;
    if(strcmp(target,"*") == 0) all = true;
    while(traverse) {
        cnt++;
        if(all) {
         cout << cnt << "." << traverse->name << " " << traverse->phonenum << endl;
         found++;
        }
        else if(strnicmp(traverse->name,target,strlen(target)) == 0)
        {
            found++;
            cout << cnt << "." << traverse->name << " " << traverse->phonenum << endl;
        }
        traverse = traverse->next;
    }
    return found;
}

void List::remove(int ordernum)
{
    Node *traverse,*tail;
    int cnt = 1;
    traverse = head;
    if(ordernum <= 0) {
        cout << "Invalid record order number.\n";
        return;
    }
    if(ordernum == 1) {
       head = head->next;
       delete traverse;
       nodecount--;
       return;
    }
    while((traverse != NULL) && (cnt < ordernum)) {
        tail = traverse;
        traverse = traverse->next;
        cnt++;
    }
    if(cnt < ordernum) {
        cout << "Could not find record to delete.\n";
    }
    else {
        tail->next = traverse->next;
        delete traverse;
        nodecount--;
    }
}

void List::makeEmpty()
{
    Node *p;
    while(head) {
        p = head;
        head = head->next;
        delete p;
    }
    nodecount = 0;
}

void List::insert(Node *toadd)
{
    Node *traverse, *tail;
    Node *newnode;
    traverse = head;
    newnode = new Node;
    *newnode = *toadd;
    newnode->next = NULL;
    if(head == NULL) {
        head = newnode;
        nodecount++;
        return;
    }
    if(strcmp(newnode->name,head->name) < 0) {
        newnode->next = head;
        head = newnode;
        nodecount++;
        return;
    }
    while(traverse && (strcmp(newnode->name,traverse->name)) > 0) {
        tail = traverse;
        traverse = traverse->next;
        if(traverse) {
            newnode->next = traverse;
            tail->next = newnode;
        }
        else {
            tail->next = newnode;
            nodecount++;
        }

    }
}

void List::update(int recordnum, Node *newnode)
{
    Node *traverse;
    int cnt = 1;
    traverse = head;
    while(traverse && (cnt < recordnum)) {
        cnt++;
        traverse = traverse->next;
    }
    if(traverse) {
        newnode->next = traverse->next;
        *traverse = *newnode;
        delete newnode;
    }
    else cout << "Invalid number for record updated.";
}

void List::close()
{
    makeEmpty();
}
int main()
{
    List l1;
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(9);
    for(int i = 0; i < 5; i++) cout << l1[i] << " ";
}
