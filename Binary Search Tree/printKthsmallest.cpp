#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

void printKthsmallest(Node *root, int k){
	if(!root) return;
	static int l = 0;
	printKthsmallest(root->left,k);
	l=l+1;
	if(l==k){
		cout<<root->data<<" ";
		return;
	}
	printKthsmallest(root->right,k);
}

int main(){
	Node* root = NULL;
 
  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);  
  root = insert(root, 14);
  printKthsmallest(root, 5);
}
