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

bool PrintAncestors(Node *root, int data){
	if(!root) return false;
	if(root->data == data) return true;
	
	if(PrintAncestors(root->left,data)||PrintAncestors(root->right,data)){
		cout<<root->data<<" ";
		return true;
	}
	return false;
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    PrintAncestors(root,6);
	
	return 0;
}
