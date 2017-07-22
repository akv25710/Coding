#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

bool printAncestors(Node *root, int data){
	if(!root) return false;
	if(root->data == data) return true;
	if(printAncestors(root->left, data) ||	printAncestors(root->right, data)){
		cout<<root->data;
		return true;
	}
	return false;
	
}

int main(void)
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  
  
  printAncestors(root, 4);
  
  return 0;
}
