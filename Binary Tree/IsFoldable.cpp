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

bool isMirror(Node *root1, Node *root2){
	if(!root1 && !root2) return 1;
	if(!root1 || !root2) return 0;
	return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isFoldable(Node *root){
	if(!root) return true;
	return isMirror(root->left,root->right);
}

int main(void)
{
  /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left  = newNode(4);
  root->left->left = newNode(5);
 
  if(isFoldable(root) == 1)
  { printf("\n tree is foldable"); }
  else
  { printf("\n tree is not foldable"); }
 
  getchar();
  return 0;
}
