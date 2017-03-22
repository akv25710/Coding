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
void Delete(Node *root){
	if(!root) return;
	Delete(root->left);
	Delete(root->right);
	delete(root);
}
int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
    Delete(root);
    cout<<root->data;
 
 
	
	return 0;
}
