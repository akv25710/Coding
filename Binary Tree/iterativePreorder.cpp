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

void iterativePreorder(Node *root){
	stack<Node*> S;
	S.push(root);
	while(!S.empty()){
		Node *temp = S.top(); S.pop();
		cout<<temp->data<<" ";
		if(temp->right) S.push(temp->right);
		if(temp->left) S.push(temp->left);
	}
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
  iterativePreorder(root);
  return 0;
}
