#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node *next;
};

void InorderSuccessor(Node *root){
	if(!root) return;
	static Node* next = NULL;
	InorderSuccessor(root->right);
	root->next = next;
	next = root;
	InorderSuccessor(root->left);
}

Node* newnode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      12
        /
      3
    */
    Node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(12);
    root->left->left  = newnode(3);
 
    // Populates nextRight pointer in all nodes
    InorderSuccessor(root);
 
    // Let us see the populated values
    Node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
 
    return 0;
}



