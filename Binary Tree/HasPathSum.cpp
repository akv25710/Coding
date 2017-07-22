#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

int hasPathSum(Node* root, int sum){
	if(!root) return (sum==0);
	return hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data);
}


Node* newnode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int main()
{
 
  int sum = 14;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  Node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);
 
  getchar();
  return 0;
}


