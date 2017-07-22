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

int deepestOddlevelLeaf(Node *root, int level){
	if(!root) return 0;
	if(!root->left && !root->right && level%2!=0) return level;
	return max(deepestOddlevelLeaf(root->left,level+1),deepestOddlevelLeaf(root->right,level+1));
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    root->right->right->right->right->left = newNode(11);
 
    printf("%d is the required depth\n", deepestOddlevelLeaf(root,1));
    getchar();
    return 0;
}
