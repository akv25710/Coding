#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
    Node *nextRight;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    return temp;
}
void ConnectReccur(Node *root){
	if(!root) return;
    if(root->left) root->left->nextRight = root->right;
    if(root->right) {
    	if(root->nextRight){
    		if(root->nextRight->left) root->right->nextRight = root->nextRight->left;
    		else if(root->nextRight->right) root->right->nextRight = root->nextRight->right;
    		}
	}	
	ConnectReccur(root->left);
	ConnectReccur(root->right);
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    ConnectReccur(root);
    cout<<root->left->right->nextRight->data;
	
	return 0;
}
