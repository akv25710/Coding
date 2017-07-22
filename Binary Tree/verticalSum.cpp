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

void verticalSum(Node *root, int sum){
	if(!root) return;
	if(isLeaf(root)) cout<<sum+root->data<<endl;
	verticalSum(root->left, sum+root->data);
	verticalSum(root->right, sum+root->data);
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
    verticalSum(root,0);
    return 0;
}
