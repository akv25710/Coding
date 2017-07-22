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

void print( Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d ",root->data);
        print(root->right);
    }
}

Node* prune(Node *root, int sum){
	if(!root) return NULL;
	root->left = prune(root->left,sum-root->data);
	root->right = prune(root->right,sum-root->data);
	if(!root->left && !root->right && root->data < sum){
		delete(root);
		return NULL;
	}
	return root;
}

int main()
{
    int k = 45;
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
 
    printf("Tree before truncation\n");
    print(root);
 
    root = prune(root, k); // k is 45
 
    printf("\n\nTree after truncation\n");
    print(root);
 
    return 0;
}
