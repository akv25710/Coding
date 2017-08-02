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

void printRange(Node *root, int data1, int data2){
	if(!root) return;
	if(root->data > data1) printRange(root->left,data1,data2);
	if(root->data < data2 && root->data > data1)
		cout<<root->data<<endl;
	if(root->data < data2) printRange(root->right,data1,data2);	
	
}

int main()
{
  Node *root = new Node;
  int k1 = 10, k2 = 25;
 
  /* Constructing tree given in the above figure */
  root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
 
  printRange(root, k1, k2);
 
  getchar();
  return 0;
}

