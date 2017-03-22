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

void MorrisTraversalPreorder(Node *root){
	while(root){
		if(root->left == NULL){
			cout<<root->data<<"";
			root = root->right;
		}
		else{
			Node *pre = root->left;
			while(pre->right && pre->right != root)
			    pre = pre->right;
			if(pre->right == root){
				pre->right = NULL;
				root = root->right;
			}
			else{
				cout<<root->data<"";
				pre->right = root;
				root = root->left;
			}     
		}
	}
	
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    MorrisTraversalPreorder(root);
	
	return 0;
}
