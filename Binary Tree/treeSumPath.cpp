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

int treeSumPath(Node *root, int sum){
	if(!root) return 0;
	sum = sum*10+root->data;
	if(!root->left && !root->right) return sum;
	return treeSumPath(root->left,sum)+treeSumPath(root->right,sum);
}

int main()
{
    Node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    cout<<treeSumPath(root,0);
    return 0;
}
