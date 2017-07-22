#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newnode(int data){
	Node *root = new Node;
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void printKdistanceNodeDown(Node *root, int k){
	if(!root || k < 0) return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	} 
	printKdistanceNodeDown(root->left,k-1);
	printKdistanceNodeDown(root->right,k-1);
}

int printKdistanceNode(Node *root, Node *target, int k){
	if(!root) return -1;
	if(root == target){
		printKdistanceNodeDown(root,k);
		return 0;
	}
	int dl = printKdistanceNode(root->left, target, k);
	if(dl != -1){
		if(1+dl == k) cout<<root->data<<" ";
		else printKdistanceNodeDown(root->right,k-dl-2);
		return 1+dl;
	}
	int dr = printKdistanceNode(root->right, target, k);
	if(dr != -1){
		if(1+dr == k) cout<<root->data<<" ";
		else printKdistanceNodeDown(root->left,k-dr-2);
		return 1+dr;
	}
	return -1;
}

int main()
{
    /* Let us construct the tree shown in above diagram */
    Node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    Node * target = root->left->right;
    printKdistanceNode(root, target, 2);
    return 0;
}


