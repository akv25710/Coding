#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void pairWiseSwap(Node *head){
	Node *temp = head;
	while(temp && temp->next){
		swap(temp->data, temp->next->data);
		temp = temp->next->next;
	}
}

 
/* Function to add a node at the begining of Linked List */
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
 
/* Driver program to test above function */
int main()
{
    struct Node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("Linked list before calling  pairWiseSwap()\n");
    printList(start);
 
    pairWiseSwap(start);
 
    printf("\nLinked list after calling  pairWiseSwap()\n");
    printList(start);
 
    return 0;
}
