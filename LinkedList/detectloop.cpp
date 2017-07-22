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
 
void detectloop(Node *head){
	Node *fast = head;
	Node *slow = head;
	int flag=0;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			flag=1;
			cout<<"Detected";
			break;
		}
	}
	if(flag){
		slow = head;
		while(slow != fast){
			fast = fast->next->next;
			slow = slow->next;
		}
		cout<<endl<<slow->data;
	}
	
	
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    detectloop(head);
 
    return 0;
}
