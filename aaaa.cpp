// C program to merge two sorted linked lists
// in-place.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	Node() {data = 0; next = NULL;}
};

// Function to create newNode in a linkedlist
Node *newNode(int key)
{
	struct Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}


// A utility function to print linked list
void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
Node *mergee(Node *h1, Node *h2)
{
	if (!h1)
		return h2;
	if (!h2)
		return h1;

	// start with the linked list
	// whose head data is the least
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

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Driver program
int main()
{


	// 0->2->4 LinkedList created


	Node *res = NULL, *a = NULL, *b = NULL;
    int sajz1, sajz2;
    int n1,n2;
    cout << "Enter length for the first list: ";
    cin >> sajz1;
    cout << "Now, enter length for the second one: ";
    cin >> sajz2;
    for(int i = 0; i < sajz1; i++)
    {
        cout << "Enter number " << i+1 << ": ";
        cin >> n1;
        push(&a,n1);
    }
    cout << "\nList 1 is completed. Now we go to the second one.\n";
    for(int j = 0; j < sajz2; j++)
    {
        cout << "Enter number " << j+1 << ": ";
        cin >> n2;
        push(&b,n2);
    }
    res = mergee(a,b);
    cout << "Merged list is: \n"; printList(res);
}

