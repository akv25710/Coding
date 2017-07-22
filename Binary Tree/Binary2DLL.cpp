#include<iostream>
#include<stack>
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

void Binary2DLL(Node *root, Node **head){
	if(!root) return;
	static Node* prev = NULL;
	Binary2DLL(root->left, head);
	if(!prev) *head = root;
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	Binary2DLL(root->right, head);
}

int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  Node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  
  Node *head = NULL;
  Binary2DLL(root, &head);
  while(head){
  	cout<<head->data<<" ";
  	head = head->right;
  }
  return 0;
}
