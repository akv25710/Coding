#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void append(Node **head, int data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	Node *current = *head;
	Node *prev;
	if(!(*head)){
		*head = newNode;
		return;
	}
	while(current) {
		prev = current;
		current = current->next;
	}
	prev->next = newNode;
}

void AlternatingSplit(Node *head, Node **a, Node **b){
	Node *current = head;
	while(current){
		append(a,current->data);
		current = current->next;
		if(current){
			append(b,current->data);
			current = current->next;
		}
	}
	
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
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
  while(node!=NULL)
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
  struct Node* a = NULL;
  struct Node* b = NULL;  
 
  /* Let us create a sorted linked list to test the functions
   Created linked list will be 0->1->2->3->4->5 */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);                                    
  push(&head, 0);  
 
  printf("\n Original linked List:  ");
  printList(head); 
 
  /* Remove duplicates from linked list */
  AlternatingSplit(head, &a, &b); 
 
  printf("\n Resultant Linked List 'a' ");
  printList(a);            
 
  printf("\n Resultant Linked List 'b' ");
  printList(b);            
 
  getchar();
  return 0;
}
