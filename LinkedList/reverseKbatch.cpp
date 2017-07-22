#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *reverseKbatch(Node *head, int k){
	Node *prev=NULL,*current=head,*next;
	for(int i=0;i<k && current;i++){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	if(next) head->next = reverseKbatch(next,k);
	return prev;
}

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
 
/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\nGiven linked list \n");
     printList(head);
     head = reverseKbatch(head, 3);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}
