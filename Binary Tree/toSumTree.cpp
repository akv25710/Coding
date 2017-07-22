#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

int isLeaf(Node *root){
	if(!root) return 0;
	return !root->left && !root->right;
}

void toSumTree(Node *root){
	if(!root || isLeaf(root)) return;
	toSumTree(root->left);
	toSumTree(root->right);
	int left = root->left ? root->left->data:0;
	int right = root->right ? root->right->data:0;
	root->data = left + right;
	if(isLeaf(root->left)) root->left->data = 0;
	if(isLeaf(root->right)) root->right->data = 0;
}


Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void printInorder(Node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

int main()
{
  Node *root = NULL;
  int x;
 
  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
 
  toSumTree(root);
 
  // Print inorder traversal of the converted tree to test result of toSumTree()
  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
 
  getchar();
  return 0;
}

