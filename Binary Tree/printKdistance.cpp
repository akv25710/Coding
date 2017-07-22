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

void printKdistance(Node *root, int k){
	if(!root) return;
	if(k==0) cout<<root->data<<" ";
	printKdistance(root->left,k-1);
	printKdistance(root->right,k-1);
}

int main(void)
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  
 
  printKdistance(root,2);
 
  getchar();
  return 0;
}
