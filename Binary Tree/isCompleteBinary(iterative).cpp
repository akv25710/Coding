#include <iostream>
#include <queue>
#include <math.h>

using namespace std;


struct Node
{
    Node *left;
    int data;
    Node *right;
};
Node *newNode(int data){
    
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


bool isCompleteBinary(Node *root){
	
	if(!root) return true;
	Node *temp;
	queue <Node *> Q;
	Q.push(root);
    bool isNull =false;
	while(!Q.empty()){
		temp =Q.front(); Q.pop();
		if(temp != NULL){
			if(isNull) return false;
			Q.push(temp->left);
			Q.push(temp->right); 
		}
		else isNull = true;
         
	}
	return true;
	
}

int main() {
     Node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);
  root->right->left = newNode(7);
 
  if ( isCompleteBinary(root))
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");
 
 
 
	
	return 0;
}
