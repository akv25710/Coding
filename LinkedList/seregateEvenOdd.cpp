#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void *segregateEvenOdd(Node *head){
	Node *odd=head;
	Node *even=head;
	while(odd && even){
		while(odd){
			if(((odd->data)%2 != 0)) break;
			else odd=odd->next;
		}even = odd;
		while(even){
			cout<<"  sds";
			if(((even->data)%2 == 0)) break;
			else even=even->next;
		}
		if(even && odd) swap(even->data,odd->data);
	}
}

void push(struct Node** head_ref, int new_data)
{
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
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 7);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}
