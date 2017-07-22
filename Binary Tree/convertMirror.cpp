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

void convertMirror(Node *root){
	if(!root) return ;
	convertMirror(root->left);
	convertMirror(root->right);
	swap(root->left, root->right);
}

void inOrder( Node* node) 
{
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}  

int main()
{
    Node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
    inOrder(root);
    cout<<endl;
    convertMirror(root);
    inOrder(root);
    return 0;
}
