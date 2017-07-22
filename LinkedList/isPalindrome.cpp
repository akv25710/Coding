#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

bool isPalindromeUtil(Node **left, Node *right){
	if(!right) return true;
	bool isp = isPalindromeUtil(left, right->next);
	if(!isp) return false;
	bool isp1 = (right->data == (*left)->data);
	*left = (*left)->next;
	return isp1;
}

bool isPalindrome(Node *head)
{
   return isPalindromeUtil(&head, head);
}

void push(struct Node** head_ref, char new_data)
{
    /* allocate node */
    Node *new_node = new Node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}
 
// A utility function to print a given linked list
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printList(head);
       isPalindrome(head)? printf("Is Palindrome\n\n"):
                           printf("Not Palindrome\n\n");
    }
 
    return 0;
}
