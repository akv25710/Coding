#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
    Node *next;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;
    return temp;
}
void InorderSuccessor(Node *root){
	if(!root) return;
	
	static Node *temp = NULL;
	InorderSuccessor(root->right);
	root->next = temp;
	temp = root;
	InorderSuccessor(root->left);	
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->left = newNode(7);
    
    InorderSuccessor(root);
    Node *temp = root->left->left;
    
    while(temp){
    	cout<<temp->data<<" ";
    	temp = temp->next;
	}
 
 
	
	return 0;
}
