#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printPathUtil(Node *root, int path[], int pathLen){
	if(!root) return;
	path[pathLen++] = root->data;
	if(!root->left && !root->right){
			for(int i=0;i<pathLen;i++) cout<<path[i]<<" ";
			cout<<endl;
		}
	printPathUtil(root->left, path, pathLen);
	printPathUtil(root->right, path, pathLen);		
}

void printPaths(Node *root){
	int path[9];
	printPathUtil(root, path, 0);
}

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    printPaths(root);
    return 0;
}
