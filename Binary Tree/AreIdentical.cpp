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

bool AreIdentical(Node *root,Node *root1){
	
	if(!root && !root1) return true;
	if(!root || !root1) return false;
	return (root->data == root1->data && AreIdentical(root->left,root1->left) && AreIdentical(root->right,root1->right));	
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
     Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(8);
    root1->right->right = newNode(6);
 
	if(AreIdentical(root,root1)) cout<<"Are Identical";
	else cout<<"Not Identical";
	return 0;
}
