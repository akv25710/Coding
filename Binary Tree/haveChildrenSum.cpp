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

bool haveChildrenSum(Node *root){
	if(!root) return 1;
	if(!root->left && !root->right) return 1;
	int data1 = root->left ? root->left->data:0;
	int data2 = root->right ? root->right->data:0;
	return root->data == data1+data2 && haveChildrenSum(root->left) && haveChildrenSum(root->right);
}

int main()
{
  Node *root         = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(haveChildrenSum(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  return 0;
}
