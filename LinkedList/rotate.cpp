#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void rotate(Node **head, int k){
	Node *temp=*head;
	Node *kthNode;
	for(int i=1;i<k;i++) temp =temp->next;
	if (temp == NULL)
        return;
	kthNode = temp;
	
	while(temp->next)
		temp=temp->next;
	temp->next = *head;
	*head = kthNode->next;
	kthNode->next = NULL;
}

void push (Node** head_ref, int new_data)
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
void printList( Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    rotate(&head, 4);
 
    printf("\nRotated Linked list \n");
    printList(head);
 
    return (0);
}
