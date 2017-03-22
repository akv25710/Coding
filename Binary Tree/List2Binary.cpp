#include <iostream>
#include <queue>

using namespace std;

struct List{
	int data;
	List *next;
};
struct Node
{
    Node *left;
    int data;
    Node *right;
};

List *newList(int data){
	List *temp = new List;
	temp->data = data;
	temp->next = NULL;
}

Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void Inorder(Node *root){
	if(!root) return;
	Inorder(root->left);
	cout<<root->data<<"	";
	Inorder(root->right);
}

Node *List2Binary(List *head){
	if(!head) return NULL;
	Node *root = newNode (head->data);
	
	queue<Node *> Q;
	Q.push(root);
	
	while(!Q.empty()){
		Node *temp = Q.front();Q.pop();
		if(head->next) {
			temp->left = newNode(head->next->data);
			Q.push(temp->left);
			head = head->next;
		}
		if(head->next) {
			temp->right = newNode(head->next->data);
			Q.push(temp->right);
			head = head->next;
		}
	}
	return root;
}

int main() {
	List *head = newList(5);
	head->next = newList(10);
	head->next->next = newList(15);
	head->next->next->next = newList(20);
    head->next->next->next->next = newList(30);
    head->next->next->next->next->next = newList(40);
    
    Node *root = List2Binary(head);
    Inorder(root);
    
	 
	return 0;
}
