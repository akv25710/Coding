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

Node *removeOutsideRange(Node *root, int min, int max){
	if(!root) return NULL;
	root->left = removeOutsideRange(root->left,min,max);
	root->right = removeOutsideRange(root->right,min,max);
	if(root->data < min){
		Node *temp = root->right;
		delete(root);
		return temp;
	}
	if(root->data > max){
		Node *temp = root->left;
		delete(root);
		return temp;
	}
	return root;
}



// A utility function to insert a given key to BST
Node* insert(Node* root, int key)
{
    if (root == NULL)
       return newNode(key);
    if (root->data > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
 
// Utility function to traverse the binary tree after conversion
void inorderTraversal(Node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}
 

int main()
{
    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
 
    root = removeOutsideRange(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);
 
    return 0;
}
