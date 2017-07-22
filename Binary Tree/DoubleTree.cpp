#include<iostream>
#include<algorithm>
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

void DoubleTree(Node *root){
	if(!root) return;
	Node *temp;
	if(root->left){
		temp = root->left;
		root->left = newNode(root->data);
		root->left->left = temp;
	}
	else	
		root->left = newNode(root->data);
	DoubleTree(root->left->left);
	DoubleTree(root->right);
}

void printInorder(Node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left); 
  printf("%d ", node->data);
  printInorder(node->right);
}
  
  
/* Driver program to test above functions*/
int main()
{
  
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  
  printf("Inorder traversal of the original tree is \n");
  printInorder(root);
 
  DoubleTree(root);
   
  printf("\n Inorder traversal of the double tree is \n");  
  printInorder(root);
    
  getchar();
  return 0;
}
