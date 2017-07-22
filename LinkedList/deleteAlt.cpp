#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void deleteAlt(Node *head){
	Node *temp;
	temp = head;
	while(temp && temp->next){
		temp->next = temp->next->next;
		temp = temp->next;
	}
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
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions */
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Using push() to construct below list
      1->2->3->4->5  */
  //  push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("\nList before calling deleteAlt() \n");
    printList(head);
 
    deleteAlt(head);
 
    printf("\nList after calling deleteAlt() \n");
    printList(head);
 
    return 0;
}
