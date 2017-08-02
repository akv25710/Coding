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

Node * LCA(Node *root, int data1, int data2){
	if(!root) return NULL;
	if(root->data > data1 && root->data > data2)
		return LCA(root->left,data1,data2);
	if(root->data < data1 && root->data < data2)
		return LCA(root->right,data1,data2);
	return root;
}

int main()
{
    // Let us construct the BST shown in the above figure
    Node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct Node *t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    return 0;
}
    
