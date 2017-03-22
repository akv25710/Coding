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

Node *getNextRight(Node *root){
    
	if(!root) return NULL;
	Node *temp = root->next;
	while(temp){
		if(temp->left)
		    return temp->left;
		else if(temp->right)
		    return temp->right;
		temp = temp->next;	     
	}	
	return NULL;
}

void ConnectingNodes(Node *root){
	
	if(!root) return;
	
	if(root->next)
	   ConnectingNodes(root->next);
	
	if(root->left){
		if(root->right){
		 root->left->next = root->right;
		 root->right->next = getNextRight(root);
	    }
	    else
	      root->left->next = getNextRight(root);
	    ConnectingNodes(root->left);  
    }
    
	else if(root->right){
	
	    root->right->next = getNextRight(root);
		ConnectingNodes(root->right);	
    }
    
    else
	    ConnectingNodes(getNextRight(root));    
		
}



int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
    ConnectingNodes(root);
 
    cout<<root->left->right->next->data;
	
	return 0;
}
