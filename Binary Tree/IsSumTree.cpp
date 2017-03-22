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

bool IsSumTree(Node *root, int root_data){
	if(!root) return root_data==0;
	int left=0,right=0;
    if(root->left) left = root->left->data;
    if(root->right) right = root->right->data;
    
	return (root_data == left + right) && IsSumTree(root->left,root_data-left) && IsSumTree(root->right,root_data-right);
}

int main() {
     Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
 
    cout<<IsSumTree(root,26);
	
	return 0;
}
