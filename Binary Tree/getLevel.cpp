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

int getLevel(Node *root, int level, int data){
	if(!root) return 0;
	if(data == root->data) return level;
	int k = getLevel(root->right,level+1, data);
	return k ? k : getLevel(root->left, level+1, data);
}

int main(void)
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  
  
  cout<<getLevel(root, 1, 4);
  
  return 0;
}
