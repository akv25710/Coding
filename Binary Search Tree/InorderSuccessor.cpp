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

Node *InorderSuccessor(Node *root, Node *target){
	if(!root) return NULL;
	Node *succ;
	if(target->right){
		succ = target->right;
		while(succ->left)
			succ = succ->left;
		return succ;			
	}
	while(root){
		if(target->data < root->data){
			succ = root;
			root = root->left;
		}
		else if(target->data > root->data)
			root = root->right;
		else
		 	break;
	}
	return succ;
}

int main()
{
  Node* root = NULL, *temp, *succ, *min;
 
  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);  
  root = insert(root, 14);    
  temp = root->left->right->right;
 
  succ =  InorderSuccessor(root, temp);
  if(succ !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);    
  else
    printf("\n Inorder Successor doesn't exit");
 
  return 0;
}
