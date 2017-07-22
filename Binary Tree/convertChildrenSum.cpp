#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

void increment(Node* root, int diff){
	if(root->left){
		root->left->data += diff;
		increment(root->left,diff);
	}
	else if(root->right){
		root->right->data += diff;
		increment(root->right, diff);
	}
}

void convertTree(Node *root){
	if(!root) return;
	if(!root->left && !root->right) return;
	convertTree(root->left);
	convertTree(root->right);
	int left_data = root->left ? root->left->data : 0;
	int right_data = root->right ? root->right->data : 0;
	int diff = left_data + right_data - root->data;
	if(diff > 0) root->data += diff;
	else
		increment(root->left, -diff);
}

void printInorder(Node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
/* Driver program to test above functions */
int main()
{
  Node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
 
  getchar();
  return 0;
}

