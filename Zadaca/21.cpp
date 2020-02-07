#include<iostream>
using namespace std;

struct Node
{
    //these will be used in every function
	int data;
	struct Node *next;
};

// Function to create newNode in a linkedlist
Node *newNode(int key)
{
	struct Node *temp = new Node;    //initialize new Node
	temp->data = key;                //add our number here
	temp->next = NULL;               //next will be logically empty
	return temp;                     //return this number
}

// A utility function to print linked list
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << "->";  //used for our output
		node = node->next;           //go to the next number
	}
}

Node *mergee(Node *h1, Node *h2)        //merges two lists
{
	if (!h1)                  //if h1 is empty
		return h2;
	if (!h2)                  //if h2 is empty
		return h1;

	// start with the linked list whose head data is the least
	if (h1->data < h2->data)
	{
		h1->next = mergee(h1->next, h2);
		return h1;
	}
	else
	{
		h2->next = mergee(h1, h2->next);
		return h2;
	}
}

//main program
int main()
{
	Node *head1 = newNode(1);
	head1->next = newNode(2);
	head1->next->next = newNode(4);

	// 1->2->4 LinkedList created

	Node *head2 = newNode(1);
	head2->next = newNode(3);
	head2->next->next = newNode(4);

	// 1->3->4 LinkedList created

	Node *mergedhead = mergee(head1, head2);

	printList(mergedhead);
	return 0;
}

