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

void iterativePostorder(Node *root){
	stack<Node*> S1;
	stack<Node*> S2;
	S1.push(root);
	while(!S1.empty()){
		Node *temp = S1.top(); S1.pop();
		S2.push(temp);
		if(temp->left) S1.push(temp->left);
		if(temp->right) S1.push(temp->right);
	}
	while(!S2.empty()){
		cout<<S2.top()->data<<" ";
		S2.pop();
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
  iterativePostorder(root);
  return 0;
}
