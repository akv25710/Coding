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

Node *removeHalfNodes(Node *root){
 	if(!root) return NULL;
	root->left = removeHalfNodes(root->left);
	root->right = removeHalfNodes(root->right);
	if(!root->left && !root->right) return root;
	if(!root->left)
		return root->right;
	if(!root->right)
		return root->left;
	return root;
}

void printInoder(Node*root)
{
    if (root != NULL)
    {
        printInoder(root->left);
        printf("%d ",root->data);
        printInoder(root->right);
    }
}

int main(void)
{
    Node*NewRoot=NULL;
    Node *root = newNode(2);
    root->left        = newNode(7);
    root->right       = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
 
    printf("Inorder traversal of given tree \n");
    printInoder(root);
 
    NewRoot = removeHalfNodes(root);
 
    printf("\nInorder traversal of the modified tree \n");
    printInoder(NewRoot);
    return 0;
}
