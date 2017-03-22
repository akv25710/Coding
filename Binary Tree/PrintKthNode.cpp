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

void PrintKthNode(Node *root,int k){
	
	if(!root) return;
	
	if(k==0){
		cout<<root->data<<" ";
		return;
	} 
	
	PrintKthNode(root->left,k-1);
	PrintKthNode(root->right,k-1);
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    PrintKthNode(root,2);
	
	return 0;
}
