#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int isBST(Node *root,int min, int max){
	if(!root) return 1;
	if(root->data < min || root->data > max) return 0;
	return isBST(root->left, min,root->data-1) && isBST(root->right,root->data+1,max);
}

int main()
{
    struct Node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
 
    if (isBST(root,INT_MIN,INT_MAX))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}
