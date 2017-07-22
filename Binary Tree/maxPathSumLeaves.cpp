#include <bits/stdc++.h>
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

int max(int a, int b)
{ return (a >= b)? a: b; }

int maxSum(Node *root, int *result){
	if(!root) return 0;
	if(!root->left && !root->right) return root->data;
	int ls = maxSum(root->left, result);
	int rs = maxSum(root->right, result);
	if(root->left && root->right){
		*result = max(*result,ls+rs+root->data);
		return max(ls,rs)+root->data;
	}
	return root->left?ls+root->data:rs+root->data;
}

int maxPathSum(Node *root){
	int result = INT_MIN;
    maxSum(root, &result);
    return result;
}

int main()
{
    Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is "
         << maxPathSum(root);
    return 0;
}


