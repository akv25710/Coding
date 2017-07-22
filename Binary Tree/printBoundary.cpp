#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void printLeaves(Node *root){
	if(!root) return;
	if(!root->left && !root->right) cout<<root->data<<"  ";
	printLeaves(root->left);
	printLeaves(root->right);
}

void leftBoundary(Node* root){
	if(!root) return;
	if(root->left || root->right) cout<<root->data<<"  ";
	leftBoundary(root->left);
}

void rightBoundary(Node* root){
	if(!root) return;
	rightBoundary(root->right);
	if(root->left || root->right) cout<<root->data<<"  ";
}

void printBoundary(Node *root){
	if(!root) return;
	leftBoundary(root);
	printLeaves(root);
	rightBoundary(root->right);
}

int main()
{
    // Let us construct the tree given in the above diagram
    Node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}
