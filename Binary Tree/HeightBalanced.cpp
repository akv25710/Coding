#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

int HeightBalanced(Node* root, int *height){
	int lh=0,rh=0;
	if(!root){
		*height = 0;
		return 1;
	}
	int l = HeightBalanced(root->left, &lh);
	int r = HeightBalanced(root->right, &rh);
	*height = max(lh,rh)+1;
	return abs(lh-rh)<2 && l && r;	
}


Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  Node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(HeightBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  getchar();
  return 0;
}

