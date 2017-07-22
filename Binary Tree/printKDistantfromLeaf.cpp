#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}


void printKfromLeaf(Node *root, int path[], bool visited[], int pathlen, int k){
	if(!root) return;
	path[pathlen++] = root->data;
	if(!root->left && !root->right && !visited[pathlen-1-k]){
		cout<<path[pathlen-1-k]<<" ";
		visited[pathlen-1-k]=true;
		return;
	}
	printKfromLeaf(root->left,path,visited,pathlen,k);
	printKfromLeaf(root->right,path,visited,pathlen,k);
}

void printKDistantfromLeaf(Node *root, int k){
	int path[10];
	bool visited[10];
	printKfromLeaf(root,path,visited,0,k);
}
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    cout << "Nodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);
 
    return 0;
}
