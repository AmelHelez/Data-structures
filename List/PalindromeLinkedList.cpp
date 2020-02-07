#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};


struct List
{
    ListNode *head,*tail;
    List() {head = NULL;tail = NULL;}
    void add(int);
    bool isPalindrome();
};
void List::add(int n)
{
    ListNode *temp = new ListNode;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {
        tail->next = temp;
        tail = temp;
        temp = NULL;
    }
}
/*
bool List::isPalindrome() {
	ListNode *slowp = head, *fastp = head, *revp = NULL;
	while (fastp && fastp->next){
		fastp = fastp->next->next;
		ListNode* tmp = slowp->next;
		slowp->next = revp;
		revp = slowp;
		slowp = tmp;
	}
	if (fastp) slowp = slowp->next;
	while (slowp && revp){
		if (slowp->data != revp->data) return false;
		slowp = slowp->next;
		revp = revp->next;
	}
	return true;
}
*/
bool List::isPalindrome()
{
    ListNode *a = head,*b = head,*c = NULL;
    while(b && b->next) {
        b = b->next->next;
        ListNode *tmp = a->next;
        a->next = c;
        c = a;
        a = tmp;
    }
    if(b) a = a->next;
    while(a && c) {
        if(a->data != c->data) return false;
        a = a->next;
        c = c->next;
    }
    return true;
}
int main()
{
    List myList;
    int n,s;
    cout << "Enter length: "; cin >> s;
    for(int i = 0; i < s; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> n;
        myList.add(n);
    }
    if(!myList.isPalindrome()) cout << "False.";
    else cout << "True.";
    return 0;
}
