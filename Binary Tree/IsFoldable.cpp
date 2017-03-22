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

bool AreMirrors(Node *root1, Node *root2){
	if(!root1 && !root2) return 1;
	if(!root1 || !root2) return 0;
	
	return AreMirrors(root1->left,root2->right)&&AreMirrors(root1->right,root2->left);
}

bool IsFoldable(Node *root){
	if(!root) return true;
    return AreMirrors(root->left,root->right);
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    cout<<IsFoldable(root);
	
	return 0;
}
