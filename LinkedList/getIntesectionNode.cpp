#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

int getCount(struct Node* head)
{
  Node* current = head;
  int count = 0;
 
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
 
  return count;
}

int getIntesectionNode(Node *head1, Node* head2){
	int m = getCount(head1);
	int n = getCount(head2);
	
	if(m>n){
		int d = m-n;
		for(int i=0;i<d;i++) head1 = head1->next;
	}
	else{
		int d = n-m;
		for(int i=0;i<d;i++) head2 = head2->next;
	}
	while(head1 && head2){
		if(head1->data == head2->data) return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
	return -1;
}



 
int main()
{ 
  Node* newNode;
  Node* head1 = new Node;
  head1->data  = 10;
 
  Node* head2 = new Node;
  head2->data = 3;
  
  newNode = new Node;
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = new Node;
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = new Node;
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = new Node;
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));
 
  getchar();
}
