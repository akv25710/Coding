#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *Binary2DLL(Node *root){
	if(!root) return NULL;

    if(root->left != NULL){
    	Node *left = Binary2DLL(root->left);
    	while(left->right)
    	    left = left->right;
    	left->right = root;
		root->left  = left;      
	}
    if(root->right != NULL){
    	Node *right = Binary2DLL(root->right);
    	while(right->left)
    	    right = right->left;
    	right->left = root;
		root->right = right;     
	
	}
 	
	return root;
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
    
    Node *head = Binary2DLL(root);
    while(head->left ) 
         head = head->left;
    while(head){
    	cout<<head->data<<"	";
    	head = head->right;
	}
	
	return 0;
}
