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

void printLeaves(Node *root){
	if(!root) return;
	if(!root->left && !root->right) cout<<root->data<<"	";
	printLeaves(root->left);
	printLeaves(root->right);
}

void PrintLeft(Node *root){
	if(!root) return;
	if(root->left){
	    cout<<root->data<<"	";
	    PrintLeft(root->left);
    }
    else if(root->right){
    	 cout<<root->data;
	     PrintLeft(root->right);
	}
}

void PrintRight(Node *root){
	if(!root) return;
	if(root->right){
	    
	    PrintRight(root->right);
	    cout<<root->data;
    }
    else if(root->left){
    	PrintRight(root->left);
    	 cout<<root->data<<"	";
	     
	}
}

void BoundaryTraversal(Node *root){
    if(!root) return;
	PrintLeft(root);
	printLeaves(root);
	PrintRight(root->right);
	
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
     BoundaryTraversal(root);
	
	return 0;
}
