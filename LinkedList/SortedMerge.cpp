#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *SortedMerge(Node *a, Node*b){
	Node *newNode = new Node;
	newNode->next = NULL;
	Node *temp = newNode;
	while(a && b){
		if(a->data <= b->data){
			temp->next = a;
			temp = temp->next;
			a = a->next; 
		}
		else{
			temp->next = b;
			temp = temp->next;
			b = b->next;
		}
	}
	if(a) temp->next=a;
	else temp->next=b;
	temp = newNode->next;
	return temp;	
}

Node *sortRecursion(Node *a, Node *b){
	if(!a) return b;
	if(!b) return a;
	Node *result;
	if(a->data <= b->data){
		result = a;
		result->next = sortRecursion(a->next,b);
	}
	else{
		result = b;
		result->next = sortRecursion(a,b->next);
	}
	return result;
}

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    Node * new_node = new Node;
 
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
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 4);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = sortRecursion(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
 
    return 0;
}
