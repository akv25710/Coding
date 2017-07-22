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

void MorrisInorder(Node *root){
	if(!root) return;
	while(root){
		if(!root->left){
			cout<<root->data<<" ";
			root = root->right;
		}
		else{
			Node *pre = root->left;
			while(pre->right && pre->right != root)
				pre = pre->right;
			if(pre->right){
				cout<<root->data<<" ";
				pre->right = NULL;
				root = root->right;
			}
			else{
				pre->right = root;
				root = root->left;
			}
		}
	}
}

int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  MorrisInorder(root);
 
  getchar();
  return 0;
}

