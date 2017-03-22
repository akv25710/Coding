#include <iostream>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int NumberOfLeafNode(Node *root)
{
	if(!root) return 0;
	if(!root->left && !root->right)    return 1;
	return NumberOfLeafNode(root->left)+NumberOfLeafNode(root->right);
}
int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
   cout<<NumberOfLeafNode(root);
	
	return 0;
}
