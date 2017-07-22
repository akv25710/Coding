#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

int Diameter(Node* root, int *height){
	int lh=0,rh=0;
	if(!root){
		*height = 0;
		return 0;
	}
	int lDiameter = Diameter(root->left, &lh);
	int rDiameter = Diameter(root->right, &rh);
	*height = max(lh,rh)+1;
	return max(lh+rh+1,max(lDiameter, rDiameter));	
}


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
  int height = 0;
  cout<<Diameter(root,&height);
  return 0;
}

