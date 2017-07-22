#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int countLeafNodes(Node *root){
	if(!root) return 0;
	if(!root->left && !root->right) return 1;
	return countRootLeaves(root->left) + countRootLeaves(root->right);
}

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    cout<<countLeafNodes(root);
    return 0;
}
