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

bool isSumTree(Node *root){
	if(!root ) return true;
	int left,right;
	if(isSumTree(root->left) || isSumTree(root->right)){
		if(!root->left) left = 0;
		else if(isLeaf(root->left)) left = root->left->data;
		else left = 2 * root->left->data;
		
		if(!root->right) right = 0;
		else if(isLeaf(root->right)) right = root->right->data;
		else right = 2 * root->right->data;
		return left+right == root->data;
	}
	return 0;
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
    Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");
 
    getchar();
    return 0;
}


