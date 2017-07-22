#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};


void push(struct Node** head_ref, int new_data)
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
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void swapNodes(Node **head, int data1, int data2){
	Node *currX = *head,*prevX;
	Node *currY = *head,*prevY;
	while(currX && currX->data != data1){
		prevX = currX;
		currX = currX->next;
	}
		while(currY && currY->data != data2){
		prevY = currY;
		currY = currY->next;
	
	}
	if(!currX || !currY) return;
	
	if(prevX) prevX->next = currY;
	else *head = currY;
	
	if(prevY) prevY->next = currX;
	else *head = currX;
	
	swap(currX->next,currY->next);
	
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
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
    swapNodes(&start, 4, 3);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 
    return 0;
}
