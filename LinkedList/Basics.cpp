#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};


void Insert(Node **head, int data, int pos){
	Node *newNode = new Node;
	newNode->data = data;
	Node *temp = *head;
	int k=1;
	if(pos==1){
		newNode->next = temp;
		*head = newNode;
	}
	else{
		while(temp!= NULL && k < pos){
			temp=temp->next;
			cout<<k<<endl;
			k++;
		}		
		newNode->next = temp->next;
		temp->next = newNode;
	}
	cout<<data<<" inserted at "<<pos<<endl;
}

void printList(struct Node *head)
{
	Node *node = head;
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  cout<<endl;
}
int numberOfNodes(Node *head){
	Node *next = head;
	int count = 0;
	while(next){
		count++;
		next = next->next;
	}	
	return count;
}

void Delete(Node **head, int data){
	Node *temp = *head;
	while(temp && temp->next->data!=data) temp = temp->next;
	temp->next = temp->next->next;
}

int main(){
	Node *head = NULL;
	Insert(&head,1,1);
	Insert(&head,2,1);
	Insert(&head,3,1);
	Insert(&head,4,3);
	Insert(&head,5,1);
	printList(head);
	Delete(&head,2);
	printList(head);
	return 0;
	
}
