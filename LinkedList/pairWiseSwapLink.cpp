#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void pairWiseSwap(Node **head){
	Node *curr = *head;
	if(curr->next) *head = curr->next;
	Node *next;
	while(curr && curr->next){
		if(next && next->next) next->next->next = curr->next;
		next = curr->next;
		curr->next = next->next;
		next->next = curr;
		curr = curr->next;
	}
}

void push( Node** head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList( Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct Node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    pairWiseSwap(&start);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
 
    getchar();
    return 0;
}
