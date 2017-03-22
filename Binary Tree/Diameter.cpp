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

int Height(Node *root){
	if(!root) return 0;
	return(max(Height(root->left),Height(root->right))+1);
}

int Diameter(Node *root){
	if(!root) return 0;
	int lHeight = Height(root->left);
	int rHeight = Height(root->right);
	
	int lDiameter = Diameter(root->left);
	int rDiameter = Diameter(root->right);
     
    return max((lHeight+rHeight+1),max(lDiameter,rDiameter)); 
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    cout<<Diameter(root);
	
	return 0;
}
