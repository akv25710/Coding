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
void Inorder(Node *root){
	if(!root) return;
	Inorder(root->left);
	cout<<root->data;
	Inorder(root->right);
}

void Mirror(Node *root){
	Node *temp;
	if(!root)   return;
	
	Mirror(root->left);
	Mirror(root->right);
	
	
	temp = root->right;
	root->right = root->left;
	root->left = temp;
}


int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
    Mirror(root);
    Inorder(root);
 
	
	return 0;
}
