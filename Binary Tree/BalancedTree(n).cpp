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

int BalancedTree(Node *root,int *height){
	int lh=0,rh=0;
	int l=0,r=0;
	if(!root) { 
	     *height = 0;
		 return 1;   
	}
	l = BalancedTree(root->left,&lh);
	r = BalancedTree(root->right,&rh);
	
	*height = (lh>rh?lh:rh)+1;
	 
	if(lh-rh>=2 ||rh-lh>=2) return 0;
	return 1&&r;
}

int main() {
	int height = 0;
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    
	cout<<BalancedTree(root,&height);
 	return 0;
}
