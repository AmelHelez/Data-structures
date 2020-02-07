#include <iostream>
#include <list>
using namespace std;


struct node
{
    int data;
    node *next;
};

/*
void List::add(int n)
{
    Node *temp = new Node;
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
*/

node *creatnode(int key)
{
	struct node *temp = new node;    //initialize new Node
	temp->data = key;                //add our number here
	temp->next = NULL;               //next will be logically empty
	return temp;                     //return this number
}

void display(node *head)
{
	node* current = head; // current node set to head
	//traverse until current node isn't NULL
	while(current!=NULL){
		cout << current->data;
		current=current->next; // go to next node
	}
}

node* findIntersection(node* head1, node* head2){
	//base case
	if(head1==NULL && head2==NULL)
	return NULL;

	node* head4=NULL,*temp;
	//for inserting the first common node
	while( head1!=NULL && head2!=NULL && head4==NULL){
		if(head1->data<head2->data){
			head1=head1->next;
		}
		//intersection nodes(intersection)
		else if(head1->data==head2->data){
			head4=creatnode(head1->data);
			temp=head4;
			head1=head1->next;
			head2=head2->next;
		}
		else{
			head2=head2->next;
		}
	}

	//for other common nodes(intersection)
	while( head1!=NULL && head2!=NULL){
		if(head1->data<head2->data){
			head1=head1->next;
		}
		//intersection nodes
		else if(head1->data==head2->data){
			temp->next=creatnode(head1->data);
			temp=temp->next;

			head1=head1->next;
			head2=head2->next;
		}
		else{
			head2=head2->next;
		}
	}

	return head4;
}

int main(){
	cout << ("creating the linked list by inserting new nodes at the end\n");
	cout << ("enter 0 to stop building the list, else enter any integer\n");
	int k;
	node* curr,*temp;
	cout<<"enter list1...\n";
	cin >> k;
	node* head1=creatnode(k); //buliding list, first node
    cin >> k;
	temp=head1;

	///////////////////inserting at the end//////////////////////
	while(k){
		curr=creatnode(k);
		temp->next=curr;//appending each node
		temp=temp->next;
		cin >> k;
	}
	cout<<"displaying list1...\n";
	display(head1); // displaying the list
	cout<<"\nenter list2...\n";
	cin >> k;
	node* head2=creatnode(k); //buliding list, first node
	cin >> k;
	temp=head2;

	///////////////////inserting at the end//////////////////////
	while(k){
		curr=creatnode(k);
		temp->next=curr;//appending each node
		temp=temp->next;
		cin >> k;
	}
	cout<<"displaying list1...\n";
	display(head2);

	//sort both the lists
	//mergeSort(&head1);
	//mergeSort(&head2);

	cout<<"\ndisplaying their intersection...\n";

	node* head4=findIntersection(head1,head2);
	if(head4)
		display(head4);
	else
		cout<<"No intersection found\n";
	return 0;
}
