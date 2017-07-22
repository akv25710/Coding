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

int findMaxSumInTree(Node *root, int *sum){
	if(!root) return 0;
	int left = findMaxSumInTree(root->left,sum);
	int right = findMaxSumInTree(root->right,sum);
	*sum = max(*sum, left+right+root->data);
	return max(root->data, max(root->data+left, root->data+right));
}

int main(void)
{
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    
    int sum=0;
    findMaxSumInTree(root, &sum);
    cout << "Max path sum is " <<sum;
    return 0;
}
