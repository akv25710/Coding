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

int isLeaf(Node *root){
	if(!root) return 0;
	if(!root->left && !root->right) return 1;
	return 0;
}

int isSumTree(Node *root){
	if(!root || isLeaf(root)) return 1;
	int left,right;
	
	if(isSumTree(root->left) && isSumTree(root->right)){
	
	    if(!root->left) left = 0;
	    else if(isLeaf(root->left)) left = root->left->data;
	    else left = 2*root->left->data;
	
	    if(!root->right) right = 0;
	    else if(isLeaf(root->right)) right = root->right->data;
	    else right = 2*root->right->data;
    }
	return root->data == left + right;
}

int main() {
     Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
 
    cout<<isSumTree(root);
	
	return 0;
}
