#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
/* Function to insert a node at the beginning of the Doubly Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node;
	new_node->data = new_data; 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

Node *addTwoLists(Node *first, Node *second){
	Node *res=NULL;
	Node *temp,*prev;
	int data1,data2;
	int sum,carry=0;
	while(first || second){
		if(first) data1 = first->data;
		else data1=0;
		if(second) data2 = second->data;
		else data2=0;
		sum = data1+data2+ carry;
		carry = sum/10;
		sum = sum%10;
		temp = newNode(sum);
		if(!res) res=temp;
		else prev->next=temp;
		prev=temp;
		if(first) first = first->next;
		if(second) second = second->next;
		
	}
	if(carry){
		temp = newNode(carry);
		prev->next = temp;
	} 
	return res;
}
 
void printList(Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
/* Driver program to test above function */
int main(void)
{
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);
 
   return 0;
}
