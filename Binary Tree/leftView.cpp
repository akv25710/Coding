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

void leftView(Node *root, int level){
	if(!root) return;
	static int maxLevel = 0;
	if(maxLevel < level){
		cout<<root->data<<" ";
		maxLevel = level;
	}
	leftView(root->left,level+1);
	leftView(root->right, level+1);
}



int main()
{
    Node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
 
    leftView(root,1);
    return 0;
}
