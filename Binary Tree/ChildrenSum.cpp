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

bool ChildrenSum(Node *root){
	if(!root) return true;
	if(!root->left && !root->right) return true;
	int left = 0, right=0;
	
	if(root->left) left = root->left->data;
	if(root->right) right = root->right->data;
	
	if(root->data==left+right && ChildrenSum(root->left) && ChildrenSum(root->right)) return true;
	
	return false;
	
}

int main() {
     Node *root = newNode(15);
    root->left = newNode(9);
    root->right = newNode(6);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    if(ChildrenSum(root)) cout<<"ChildrenSum";
    else cout<<"Not ChildrenSum";
	
	return 0;
}
