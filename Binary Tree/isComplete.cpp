#include<iostream>
#include<queue>
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

void printInorder (Node* node)
{
    if (node == NULL) return;
    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

bool isComplete(Node *root){
	queue<Node*> Q;
	bool flag = false;
	Q.push(root);
	while(!Q.empty()){
		Node *temp = Q.front();Q.pop();
		if(temp->left){
			if(flag) return false;
			Q.push(temp->left);
		}
		else 
			flag = true;
		if(temp->right){
			if(flag) return false;
			Q.push(temp->right);
		}
		else
			flag = true;
	}
	return true;
}

int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
  Node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->left = newNode(6);
 
  if ( isComplete(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");
 
  return 0;
}

