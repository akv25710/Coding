#include <iostream>
#include <math.h>

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

int Height(Node *root){
	if(!root) return 0;
	return max(Height(root->left),Height(root->right))+1;
}

int IsBalancedTree(Node *root){
	if(!root) return 1;
	int lHeight = Height(root->left);
	int rHeight = Height(root->right);
	
	if(abs(lHeight-rHeight)<2 && IsBalancedTree(root->left) && IsBalancedTree(root->right)) return 1;
	 
	else return 0;
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    cout<<IsBalancedTree(root);
    
	
	return 0;
}
