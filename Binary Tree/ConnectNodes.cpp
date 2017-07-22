#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node *nextRight;
};

Node* newnode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

Node* getNextRight(Node *p){
	Node *temp = p->nextRight;
	while(temp){
		if(temp->left) return temp->left;
		if(temp->right) return temp->right;
		temp = temp->nextRight;
	}
	return NULL;
}

void connectRecur(Node *p){
	if(!p) return;
	if(p->nextRight) connectRecur(p->nextRight);
	if(p->left){
		if(p->right){
			p->left->nextRight = p->right;
			p->right->nextRight = getNextRight(p);
		}
		else
			p->left->nextRight = getNextRight(p);
		connectRecur(p->left);
	}
	else if(p->right){
		p->right->nextRight = getNextRight(p);
		connectRecur(p->right);
	}
	else
		connectRecur(getNextRight(p));
}

void connect(Node *p){
	p->nextRight = NULL;
	connectRecur(p);
}

int main()
{
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    Node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->right->right       = newnode(90);
 
    // Populates nextRight pointer in all nodes
    connect(root);
 
    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
           root->nextRight? root->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->data,
           root->left->nextRight? root->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->data,
           root->right->nextRight? root->right->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
           root->left->left->nextRight? root->left->left->nextRight->data: -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
           root->right->right->nextRight? root->right->right->nextRight->data: -1);
 
    getchar();
    return 0;
}
