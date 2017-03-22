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

int Diameter(Node *root, int *height){
	if(!root) return 0;
	int lh=0,rh=0;
	int lD=0,rD=0;
	
	lD = Diameter(root->left,&lh);
	rD = Diameter(root->right,&rh);
	
	*height = max(lh,rh)+1;
	return max(lh+rh+1,max(lD,rD));
}

int main() {
     Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
 
    int height=0;
	cout<<Diameter(root,&height); 
	
	return 0;
}
